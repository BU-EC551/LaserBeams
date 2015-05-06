package spring15.ec551.fpgacontroller.fragments;

import android.app.Activity;
import android.app.Fragment;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Toast;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

import spring15.ec551.fpgacontroller.R;
import spring15.ec551.fpgacontroller.accelerometer.ControllerInterfaceListener;
import spring15.ec551.fpgacontroller.activities.MainActivity;
import spring15.ec551.fpgacontroller.resources.AmmoSlider;
import spring15.ec551.fpgacontroller.resources.CustomTextView;
import spring15.ec551.fpgacontroller.resources.ThrottleSlider;

/**
   * Created by davidkim on 4/9/15.
   * This fragment provides a platform where both vehicle and controller will
   * be able to communicate with each other.  This is used for Free Roam, but should
   * be extended for New Game mode where opponent information and game settings need to be initialized.
   */
public class PlayFragment extends Fragment implements ControllerInterfaceListener {

    // Constant UI Values
    final int MAX_AMMO = 50;
    final int RELOAD_DELAY = 3;
    final int QUARTER_SEC = 250;    // 0.25 second
    final int TENTH_SEC = 100;      // 0.10 second

    // BIT Values that respond to controls
    final int STOP = 12;    // bit 2,3
    final int BACK = 8;     // bit 3
    final int FORWARD = 4;  // bit 2

    final int NEUTRAL = 3;  // bit 0,1
    final int LEFT = 1;     // bit 0
    final int RIGHT = 2;    // bit 1

    final int NO_FIRE = 0;
    final int FIRE_ZE_LAZERS = 16;  // bit 5

    // The rate in which values are checked and sent (Deprecated)
    int RATE_OF_OUTPUT_SIGNAL = 20;   // in milliseconds

    // The sensitivity of steering angle.  Neutral is between +/- Steering Threshold
    int STEERING_THRESHOLD = 10;

    Context mContext;
    FragmentActionListener mListener;

    // Checks for socket connection
    public static final String SOCKET_BOOLEAN = "SOCKET_BOOLEAN";
    boolean mIsSocketConnected;

    // Steering
    ImageView mSteeringIcon;
    CustomTextView mSteeringAngleText;
    Button mIncreaseThreshold;
    Button mDecreaseThreshold;
    CustomTextView mThresholdText;

    // Throttle
    ThrottleSlider mThrottleSlider;
    CustomTextView mThrottleSpeed;

    // "FIRE THE LASERS!"
    LinearLayout mFireHud;
    Button mFireButton;
    Button mReloadButton;
    CustomTextView mAmmoTextView;
    AmmoSlider mAmmoSlider;
    Handler mLaserHandler;
    Runnable mUIRunnable;
    boolean isFireHeldDown;
    boolean isReloading;
    int mMaxAmmo;
    int mCurrentAmmo;
    int mReloadDelay;

    Button mDisableSignal;
    boolean allowOutput = false;

    DecimalFormat speedDecimalFormat;

    int throttle_state;
    int steering_state;
    int laser_state;

    // Saves the last state so that signals for latches are only sent when there is a change
    int last_throttle_state = 0;
    int last_steering_state = 0;

    public static PlayFragment newInstance(boolean isSocketConnected) {
        PlayFragment fragment = new PlayFragment();
        Bundle args = new Bundle();
        args.putBoolean(SOCKET_BOOLEAN, isSocketConnected);
        fragment.setArguments(args);
        return fragment;
    }

    public PlayFragment() {
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        if (getArguments() != null) {
            mIsSocketConnected = getArguments().getBoolean(SOCKET_BOOLEAN);
        }

        MainActivity.ControllerStaticObject.setInterface(this);
        speedDecimalFormat = new DecimalFormat("+###;-###");
        mLaserHandler = new Handler();
        throttle_state = STOP;
        steering_state = NEUTRAL;
        laser_state = NO_FIRE;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_free_roam, container, false);

        mListener.adjustActivityForSettings();

        // Steering
        mSteeringIcon = (ImageView) view.findViewById(R.id.steering_rotating_icon);
        mSteeringIcon.setRotation(0.0f);
        mSteeringAngleText = (CustomTextView) view.findViewById(R.id.current_angle_text);

        // Throttle
        mThrottleSpeed = (CustomTextView) view.findViewById(R.id.throttle_speed);
        mThrottleSlider = (ThrottleSlider) view.findViewById(R.id.throttle_slider);
        mThrottleSlider.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                mThrottleSpeed.setText(speedDecimalFormat.format(progress - ThrottleSlider.MID_PROGRESS) + "%");
                int speed = progress - ThrottleSlider.MID_PROGRESS;
                String s = "";
                if (speed == 0) {
                    throttle_state = STOP;
                    s = "STOP";
                } else if (speed > 0) {
                    throttle_state = FORWARD;
                    s = "FORWARD";
                } else {
                    throttle_state = BACK;
                    s = "REVERSE";
                }

                if (!(throttle_state == last_throttle_state)) {
                    last_throttle_state = throttle_state;
                    if (mIsSocketConnected && allowOutput) { MainActivity.BluetoothStaticObject.sendByte(throttle_state); }
                    System.out.println("THROTTLE : " + s);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }

        });

        // Fire
        mFireButton = (Button) view.findViewById(R.id.fire_button);
        mReloadButton = (Button) view.findViewById(R.id.reload_button);
        mAmmoTextView = (CustomTextView) view.findViewById(R.id.current_ammo);
        mFireHud = (LinearLayout) view.findViewById(R.id.fire_hud);
        mAmmoSlider = (AmmoSlider) view.findViewById(R.id.ammo_bar);
        initializeLasers(MAX_AMMO, RELOAD_DELAY);

        mReloadButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!isReloading) reload();
            }
        });

        mFireButton.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (!isReloading) {
                    isFireHeldDown = false; // Control
                    switch (event.getActionMasked()) {
                        case MotionEvent.ACTION_DOWN:
                        case MotionEvent.ACTION_POINTER_DOWN:
                            isFireHeldDown = true;
                            fireButtonDown();
                            firstBlood();
                            break;
                        case MotionEvent.ACTION_MOVE:
                            isFireHeldDown = true;
                            fireButtonDown();
                            break;
                        case MotionEvent.ACTION_POINTER_UP:
                        case MotionEvent.ACTION_UP:
                            isFireHeldDown = false;
                            fireButtonUp();
                            clearCallbacks();
                            break;
                        case MotionEvent.ACTION_CANCEL:
                            break;
                    }
                }
                return true;
            }
        });

        // Steering sensitivity (between +/- threshold value
        mThresholdText = (CustomTextView) view.findViewById(R.id.th_text);
        mThresholdText.setText("+/-" + STEERING_THRESHOLD + "\u00B0");
        mIncreaseThreshold = (Button) view.findViewById(R.id.th_increase);
        mDecreaseThreshold = (Button) view.findViewById(R.id.th_decrease);
        mIncreaseThreshold.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (STEERING_THRESHOLD < 45) {
                    STEERING_THRESHOLD += 1;
                    mThresholdText.setText("+/-" + STEERING_THRESHOLD + "\u00B0");
                }
            }
        });
        mDecreaseThreshold.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (STEERING_THRESHOLD > 1) {
                    STEERING_THRESHOLD -= 1;
                    mThresholdText.setText("+/-" + STEERING_THRESHOLD + "\u00B0");
                }
            }
        });

        mDisableSignal = (Button) view.findViewById(R.id.pause_signals);
        mDisableSignal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                allowOutput = !allowOutput;
            }
        });

        // If socket is connected, enable allowing outputs to vehicle
        if (mIsSocketConnected) {
            allowOutput = true;
        } else {
            Toast.makeText(mContext, "No Bluetooth Connection Detected!", Toast.LENGTH_SHORT).show();
        }
//        sendInstructions();

        return view;
    }

    /**
     * Initialize Lasers - Invoked in the UI thread
     */
    private void initializeLasers(int maxAmmo, int reloadDelay) {
        this.mMaxAmmo = maxAmmo;
        this.mCurrentAmmo = maxAmmo;
        this.mReloadDelay = reloadDelay;
        this.isReloading = false;
        mAmmoTextView.setText(mCurrentAmmo + "/" + mMaxAmmo);
        mAmmoSlider.initializeAmmo(MAX_AMMO);
    }

    /**
     * Registers first shot - 0.1 delay
     */
    private void firstBlood() {
        mUIRunnable = new Runnable() {
            @Override
            public void run() {
                ((MainActivity) mContext).runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        if (isFireHeldDown) {
                            shootLaser();
                        }
                    }
                });
                firstBloodPartII();
            }
        };

        if (isAmmoEmpty())
            reload();
        else
            mLaserHandler.postDelayed(mUIRunnable, TENTH_SEC);
    }

    /**
     * Register the second consecutive fire that is 0.25 seconds apart.
     * Following this, the laser will be shot every 0.1 seconds.
     */
    private void firstBloodPartII() {
        mUIRunnable = new Runnable() {
            @Override
            public void run() {
                ((MainActivity) mContext).runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        if (isFireHeldDown) {
                            shootLaser();
                        }
                    }
                });
                ramboMode();
            }
        };

        if (isAmmoEmpty())
            reload();
        else
            mLaserHandler.postDelayed(mUIRunnable, QUARTER_SEC);
    }

    /**
     * Automatic mode (fires every 0.1 second)
     */
    private void ramboMode() {
        if (isAmmoEmpty())
            reload();
        else
            mLaserHandler.postDelayed(mUIRunnable, TENTH_SEC);
    }

    /**
     * Will shoot laser and update UI in addition to ammo count.
     * This method is invoked at the UI Thread.
     */
    private void shootLaser() {
        if (!isAmmoEmpty()) {
            if (mIsSocketConnected && allowOutput) { MainActivity.BluetoothStaticObject.sendByte(FIRE_ZE_LAZERS); }
            System.out.println("LASER FIRED!");
            mCurrentAmmo -= 1;
            mAmmoTextView.setText(mCurrentAmmo + "/" + mMaxAmmo);
            mAmmoSlider.setProgress(mCurrentAmmo);
        }

    }

    private boolean isAmmoEmpty() {
        return (mCurrentAmmo == 0);
    }

    private void clearCallbacks() {
        mLaserHandler.removeCallbacksAndMessages(null);
    }

    /**
     * Begin Reloading
     */
    private void reload() {
        isReloading = true;
        laser_state = NO_FIRE;
        clearCallbacks();
        mReloadButton.setClickable(false);
        mFireButton.setClickable(false);
        mFireHud.setBackgroundColor(getResources().getColor(R.color.hud_black));
        mFireButton.setBackgroundResource(R.drawable.fire_button_active);
        mReloadButton.setBackgroundResource(R.drawable.reload_button_active);
        mAmmoTextView.setText("Reloading");
        mAmmoSlider.startReload();
    }

    /**
     * Reloading Complete
     */
    public void finishReloading() {
        mCurrentAmmo = mMaxAmmo;
        mAmmoTextView.setText(mCurrentAmmo + "/" + mMaxAmmo);
        fireButtonUp();
        mReloadButton.setBackgroundResource(R.drawable.reload_button_selector);
        mAmmoSlider.setProgress(mCurrentAmmo);

        mReloadButton.setClickable(true);
        mFireButton.setClickable(true);
        isReloading = false;
    }

    private void fireButtonDown() {
        mFireHud.setBackgroundColor(getResources().getColor(R.color.hud_red));
        mFireButton.setBackgroundResource(R.drawable.fire_button_active);
        laser_state = FIRE_ZE_LAZERS;
    }

    private void fireButtonUp() {
        mFireHud.setBackgroundColor(getResources().getColor(R.color.hud_blue));
        mFireButton.setBackgroundResource(R.drawable.fire_button_initial);
        laser_state = NO_FIRE;
    }

    @Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        mContext = activity;
        mListener = (FragmentActionListener) activity;
    }

    @Override
    public void onStart() {
        super.onStart();
        if (MainActivity.ControllerStaticObject != null)
            MainActivity.ControllerStaticObject.registerSensor();
    }

    @Override
    public void onStop() {
        super.onStop();
        if (MainActivity.ControllerStaticObject != null)
            MainActivity.ControllerStaticObject.unregisterSensor();

    }

    @Override
    public void onDetach() {
        super.onDetach();
        mListener = null;
        allowOutput = false;
    }

    /**
     * Steering
     */
    @Override
    public void onBaseChangedListener(float[] baseValues) {

    }

    @Override
    public void onFilterChangedListener(float[] filterValues, float[] netValues) {

    }

    @Override
    public void onAngleChangeListener(int angleValue) {
        mSteeringIcon.setRotation(angleValue);
        mSteeringAngleText.setText("" + angleValue + "\u00B0");

        String s;
        if (angleValue < -STEERING_THRESHOLD) {
            steering_state = LEFT;
            s = "LEFT";
        } else if (angleValue > STEERING_THRESHOLD) {
            steering_state = RIGHT;
            s = "RIGHT";
        } else {
            steering_state = NEUTRAL;
            s = "NEUTRAL";
        }

        if (!(steering_state == last_steering_state)) {
            last_steering_state = steering_state;
            if (mIsSocketConnected && allowOutput) { MainActivity.BluetoothStaticObject.sendByte(steering_state); }
            System.out.println("STEERING : " + s);
        }
    }

    public void sendInstructions() {

        final Handler handler = new Handler();

        final Runnable outputRunnable = new Runnable() {
            @Override
            public void run() {
                if (allowOutput) {
                    /* Byte Array */
                    byte[] b_array = generateOutputByteBuffer();
                    if (b_array.length > 0) {
                        String s = "";
                        for (byte b : b_array) {
                            s += Integer.toHexString(b) + " ";
                        }
                        System.out.println("Output: " + s);
                    }
                    if (mIsSocketConnected && allowOutput) { MainActivity.BluetoothStaticObject.sendBytes(b_array); }
                }
//                handler.postDelayed(this, RATE_OF_OUTPUT_SIGNAL);
            }
        };

        handler.post(outputRunnable);
//        handler.postDelayed(outputRunnable, RATE_OF_OUTPUT_SIGNAL);
                    /*----------------*/


                    /* SINGLE BYTE
                    final int b = (throttle_state + laser_state + steering_state);
                    Log.d("Output", Integer.toHexString(b) + " ");
                    if (mIsSocketConnected) {

                        if (b != 0) {
                            MainActivity.BluetoothStaticObject.sendByte(b);
                        }
                    }
                    /* --------------- */
    }

    public byte[] generateOutputByteBuffer() {
        List<Byte> byteBuffer = new ArrayList<>();
        if (!(throttle_state == last_throttle_state)) {
            last_throttle_state = throttle_state;
            byteBuffer.add((byte) throttle_state);
        }

        if (!(steering_state == last_steering_state)) {
            last_steering_state = steering_state;
            byteBuffer.add((byte) steering_state);
        }

        if (laser_state != NO_FIRE) {
            byteBuffer.add((byte) laser_state);
        }

        byte[] b_array = new byte[byteBuffer.size()];
        for (int i=0; i < byteBuffer.size(); i++) {
            b_array[i] = byteBuffer.get(i);
        }

        return b_array;
    }

}

