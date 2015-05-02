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

import java.io.IOException;
import java.text.DecimalFormat;
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

    final int MAX_AMMO = 50;
    final int RELOAD_DELAY = 3;
    final int QUARTER_SEC = 250;    // 0.25 second
    final int TENTH_SEC = 100;      // 0.10 second

    final int STOP = 0;
    final int BACK = 4;
    final int FORWARD = 8;

    final int NEUTRAL = 0;
    final int LEFT = 1;
    final int RIGHT = 2;

    final int NO_FIRE = 0;
    final int FIRE_ZE_LAZERS = 16;

    Context mContext;
    FragmentActionListener mListener;

    // Steering
    ImageView mSteeringIcon;
//    CustomTextView mLeftAngle;
//    CustomTextView mRightAngle;

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

    DecimalFormat speedDecimalFormat;

    // Debug
    CustomTextView mySignalText;
    CustomTextView vehicleSignalText;

    static int throttle_state;
    static int steering_state;
    static int laser_state;
    boolean allowOutput;

    public static PlayFragment newInstance() {
        return new PlayFragment();
    }

    public PlayFragment() {
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        MainActivity.ControllerStaticObject.setInterface(this);
        speedDecimalFormat = new DecimalFormat("+###;-###");
        mLaserHandler = new Handler();
        throttle_state = STOP;
        steering_state = NEUTRAL;
        laser_state = NO_FIRE;
        allowOutput = false;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_free_roam, container, false);

//        mListener.adjustActivityForPlay();

        mListener.adjustActivityForSettings();

        // Steering
        mSteeringIcon = (ImageView) view.findViewById(R.id.steering_rotating_icon);
        mSteeringIcon.setRotation(0.0f);
//        mLeftAngle = (CustomTextView) view.findViewById(R.id.left_angle_text);
//        mRightAngle = (CustomTextView) view.findViewById(R.id.right_angle_text);

        // Throttle
        mThrottleSpeed = (CustomTextView) view.findViewById(R.id.throttle_speed);
        mThrottleSlider = (ThrottleSlider) view.findViewById(R.id.throttle_slider);
        mThrottleSlider.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                mThrottleSpeed.setText(speedDecimalFormat.format(progress - ThrottleSlider.MID_PROGRESS) + "%");
                int speed = progress - ThrottleSlider.MID_PROGRESS;
                if (speed == 0) {
                    throttle_state = STOP;
                } else if (speed > 0) {
                    throttle_state = FORWARD;
                } else {
                    throttle_state = BACK;
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

        sendInstructions();
        allowOutput = true;
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
        if (angleValue < 10) {
            steering_state = LEFT;
        } else if (angleValue > 10) {
            steering_state = RIGHT;
        } else {
            steering_state = NEUTRAL;
        }
    }

    public void sendInstructions() {
        final Handler handler = new Handler();

        final Runnable outputRunnable = new Runnable() {
            @Override
            public void run() {
                if (allowOutput) {
                    int b = 0;
                    b = throttle_state + laser_state + steering_state;
                    MainActivity.BluetoothStaticObject.sendByte(b);
                }
                handler.postDelayed(this, 20);
            }
        };
        handler.postDelayed(outputRunnable, 20);

//        Thread sendThread = new Thread(outputRunnable);
//        sendThread.start();
    }

    public void resumeSending() {
        allowOutput = true;
    }

    public void pauseSending() {
        allowOutput = false;
    }

    /*
    public byte sendInstruction() {
        if (laser_state == Laser_State.NO_FIRE) {
            switch (throttle_state) {
                case STOP:
                    if (steering_state == Steering_State.NEUTRAL) {
                        return 0x00;
                    } else if (steering_state == Steering_State.RIGHT) {
                        return 0x02;
                    } else {
                        return 0x01;
                    }

                case FORWARD:
                    if (steering_state == Steering_State.NEUTRAL) {
                        return 0x08;
                    } else if (steering_state == Steering_State.RIGHT) {
                        return 0x0A;
                    } else {
                        return 0x09;
                    }
                case BACK:
                    if (steering_state == Steering_State.NEUTRAL) {
                        return 0x04;
                    } else if (steering_state == Steering_State.RIGHT) {
                        return 0x06;
                    } else {
                        return 0x05;
                    }
            }
        } else {
            switch (throttle_state) {
                case STOP:
                    if (steering_state == Steering_State.NEUTRAL) {
                        return 0x10;
                    } else if (steering_state == Steering_State.RIGHT) {
                        return 0x12;
                    } else {
                        return 0x11;
                    }
                case FORWARD:
                    if (steering_state == Steering_State.NEUTRAL) {
                        return 0x18;
                    } else if (steering_state == Steering_State.RIGHT) {
                        return 0x1A;
                    } else {
                        return 0x19;
                    }
                case BACK:
                    if (steering_state == Steering_State.NEUTRAL) {
                        return 0x14;
                    } else if (steering_state == Steering_State.RIGHT) {
                        return 0x16;
                    } else {
                        return 0x15;
                    }
                default:
                    return 0x00;
            }
        }
        return 0x00;
    }
    */
}

