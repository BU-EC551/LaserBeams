package spring15.ec551.fpgacontroller.fragments;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import spring15.ec551.fpgacontroller.R;
import spring15.ec551.fpgacontroller.accelerometer.ControllerInterfaceListener;
import spring15.ec551.fpgacontroller.activities.MainActivity;
import spring15.ec551.fpgacontroller.resources.CustomTextView;

/**
 * Created by davidkim on 3/28/15.
 */
public class CalibrateControllerFragment extends Fragment implements ControllerInterfaceListener{

    Context mContext;
    private FragmentActionListener mListener;

    CustomTextView mInstructionText, mNotificationText, mAngleNum, mConfigButtonLeft, mConfigButtonRight;
    ImageView mBaseLine;
    ImageView mDeviceImage;
    ImageView mExampleImage;

    public static CalibrateControllerFragment newInstance() {
        return new CalibrateControllerFragment();
    }

    public CalibrateControllerFragment() {
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        MainActivity.mControllerObject.setInterface(this);

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_config_controller, container, false);

        mInstructionText = (CustomTextView) view.findViewById(R.id.controller_instruc_textview);
        mNotificationText = (CustomTextView) view.findViewById(R.id.controller_notify_textview);
        mAngleNum = (CustomTextView) view.findViewById(R.id.rotation_angle_num);
        mBaseLine = (ImageView) view.findViewById(R.id.controller_instruc_baseline);
        mDeviceImage = (ImageView) view.findViewById(R.id.device_image);
        mDeviceImage.setRotation(0.0f);
        mConfigButtonLeft = (CustomTextView) view.findViewById(R.id.config_button_left);
        mConfigButtonRight = (CustomTextView) view.findViewById(R.id.config_button_right);
        mExampleImage = (ImageView) view.findViewById(R.id.example_image);

        mListener.adjustActivityForSettings();

        /* If configured, display current settings; otherwise initialize config procedure */
        if (MainActivity.mControllerObject.getConfiguredState()) {
            completeConfiguration();
        } else {
            beginConfiguration();
        }

        return view;
    }

    /* Begin Configuration */
    private void beginConfiguration() {
        mExampleImage.setVisibility(View.VISIBLE);
        mDeviceImage.setVisibility(View.INVISIBLE);
        mAngleNum.setVisibility(View.INVISIBLE);
        mConfigButtonLeft.setVisibility(View.VISIBLE);
        mConfigButtonRight.setVisibility(View.GONE);

        mInstructionText.setText("Please position your device as shown in the picture.\n" +
                "The screen should be facing you flat with the device in landscape position.");
        mNotificationText.setText("Once in position, press \"Begin\".");
        mConfigButtonLeft.setText("Begin");

        mConfigButtonLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity.mControllerObject.resetNetValues();
                inConfiguration();
            }
        });
    }

    /* In Configuration */
    private void inConfiguration() {
        mExampleImage.setVisibility(View.INVISIBLE);
        mDeviceImage.setVisibility(View.VISIBLE);
        mAngleNum.setVisibility(View.VISIBLE);
        mConfigButtonRight.setBackgroundResource(R.drawable.button_blue_selector);
        mConfigButtonRight.setVisibility(View.VISIBLE);

        mConfigButtonLeft.setText("Save");
        mConfigButtonRight.setText("Retry");
        mInstructionText.setText("Check if the device image is aligned correctly with your device.");
        mNotificationText.setText("If correct, press \"Save\". To try again press \"Retry\".");

        // Save
        mConfigButtonLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity.mControllerObject.setConfiguredState(true);
                mListener.updateControllerSavedStateDisplay();
                completeConfiguration();
            }
        });

        // Retry
        mConfigButtonRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity.mControllerObject.resetNetValues();
            }
        });
    }

    public void completeConfiguration() {
        mDeviceImage.setVisibility(View.VISIBLE);
        mExampleImage.setVisibility(View.INVISIBLE);
        mAngleNum.setVisibility(View.VISIBLE);
        mConfigButtonLeft.setVisibility(View.GONE);
        mConfigButtonRight.setBackgroundResource(R.drawable.button_red_selector);

        mConfigButtonRight.setText("Redo");
        mInstructionText.setText("Device has been configured.");
        mNotificationText.setText("To start over from beginning, press \"Redo\". Otherwise return to menu.");

        // Redo - Clear the settings
        mConfigButtonRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity.mControllerObject.setDefaultSettings();
                MainActivity.mControllerObject.setConfiguredState(false);
                mListener.updateControllerSavedStateDisplay();
                beginConfiguration();
            }
        });
    }

    @Override
    public void onAttach(Activity activity) {
        super.onAttach(activity);
        mContext = activity;
        mListener = (FragmentActionListener) mContext;
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

    @Override
    public void onBaseChangedListener(float[] baseValues) {
    }

    @Override
    public void onFilterChangedListener(float[] filterValues, float[] netValues) {
    }

    @Override
    public void onAngleChangeListener(int angleValue) {
        mDeviceImage.setRotation(angleValue);
        mAngleNum.setText("" + angleValue + "\u00B0");
    }
}