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

    public static PlayFragment newInstance() {
        return new PlayFragment();
    }

    public PlayFragment() {}

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        MainActivity.mControllerObject.setInterface(this);
        speedDecimalFormat = new DecimalFormat("+###;-###");
        mLaserHandler = new Handler();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_free_roam, container, false);

        mListener.adjustActivityForPlay();

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
        initializeLasers(MAX_AMMO,RELOAD_DELAY);

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

        return view;
    }

    /** Initialize Lasers - Invoked in the UI thread*/
    private void initializeLasers(int maxAmmo, int reloadDelay) {
        this.mMaxAmmo = maxAmmo;
        this.mCurrentAmmo = maxAmmo;
        this.mReloadDelay = reloadDelay;
        this.isReloading = false;
        mAmmoTextView.setText(mCurrentAmmo + "/" + mMaxAmmo);
        mAmmoSlider.initializeAmmo(MAX_AMMO);
    }

    /** Registers first shot - 0.1 delay */
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

    /** Register the second consecutive fire that is 0.25 seconds apart.
     *  Following this, the laser will be shot every 0.1 seconds.
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

    /** Automatic mode (fires every 0.1 second) */
    private void ramboMode() {
        if (isAmmoEmpty())
            reload();
        else
            mLaserHandler.postDelayed(mUIRunnable, TENTH_SEC);
    }

    /** Will shoot laser and update UI in addition to ammo count.
     *  This method is invoked at the UI Thread.
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

    /** Begin Reloading */
    private void reload() {
        isReloading = true;
        clearCallbacks();
        mReloadButton.setClickable(false);
        mFireButton.setClickable(false);
        mFireHud.setBackgroundColor(getResources().getColor(R.color.hud_black));
        mFireButton.setBackgroundResource(R.drawable.fire_button_active);
        mReloadButton.setBackgroundResource(R.drawable.reload_button_active);
        mAmmoTextView.setText("Reloading");
        mAmmoSlider.startReload();
    }

    /** Reloading Complete */
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
    }

    private void fireButtonUp() {
      mFireHud.setBackgroundColor(getResources().getColor(R.color.hud_blue));
      mFireButton.setBackgroundResource(R.drawable.fire_button_initial);
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
      if (MainActivity.mControllerObject != null)
          MainActivity.mControllerObject.registerSensor();
    }

    @Override
    public void onStop() {
      super.onStop();
      if (MainActivity.mControllerObject != null)
          MainActivity.mControllerObject.unregisterSensor();
    }

    @Override
    public void onDetach() {
      super.onDetach();
      mListener = null;
    }

    /** Steering */
    @Override
    public void onBaseChangedListener(float[] baseValues) {

    }

    @Override
    public void onFilterChangedListener(float[] filterValues, float[] netValues) {

    }

    @Override
    public void onAngleChangeListener(int angleValue) {
        mSteeringIcon.setRotation(angleValue);
//        if (angleValue < 0) {
//            mLeftAngle.setText((angleValue*-1) + "\u00B0");
//            mRightAngle.setText("0"+ "\u00B0");
//        } else {
//            mLeftAngle.setText("0" + "\u00B0");
//            mRightAngle.setText(angleValue + "\u00B0");
//        }
    }
}
