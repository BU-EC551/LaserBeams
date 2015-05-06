package spring15.ec551.fpgacontroller.fragments;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import spring15.ec551.fpgacontroller.R;
import spring15.ec551.fpgacontroller.accelerometer.ControllerInterfaceListener;
import spring15.ec551.fpgacontroller.accelerometer.ControllerObject;
import spring15.ec551.fpgacontroller.resources.CustomTextView;
import spring15.ec551.fpgacontroller.resources.FixedWidthTextView;


/**
 * Created by davidkim on 3/27/15
 */
public class ExamineAccelFragment extends Fragment implements ControllerInterfaceListener {

    private final int X = 0;
    private final int Y = 1;
    private final int Z = 2;

    Context mContext;
    private FragmentActionListener mListener;

    FixedWidthTextView mUnfiltered, mFiltered, mNet;
    CustomTextView mFilterControl, mAngleSensitivity, mAngleValue;
    Button mResetNet, mIncreaseFilter, mDecreaseFilter, mIncreaseAngle, mDecreaseAngle;

    private ControllerObject mController;

    public static ExamineAccelFragment newInstance() {
        ExamineAccelFragment fragment = new ExamineAccelFragment();
        Bundle args = new Bundle();
        fragment.setArguments(args);
        return fragment;
    }

    public ExamineAccelFragment() {}

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        if (getArguments() != null) {
            // TODO: Get UserConfigurationObject
        }

        /** This will allow the the filtered values to be outputted to this fragment */
        mController = new ControllerObject(mContext, this);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_accel, container, false);

        mUnfiltered = (FixedWidthTextView) view.findViewById(R.id.unfiltered_vector);
        mFiltered = (FixedWidthTextView) view.findViewById(R.id.filtered_vector);
        mNet = (FixedWidthTextView) view.findViewById(R.id.net_vector);
        mFilterControl = (CustomTextView) view.findViewById(R.id.kfilter_textview);
        mAngleSensitivity = (CustomTextView) view.findViewById(R.id.angle_textview);
        mAngleValue = (CustomTextView) view.findViewById(R.id.angle_value);
        mResetNet = (Button) view.findViewById(R.id.reset_button);
        mIncreaseFilter = (Button) view.findViewById(R.id.kfilter_up_arrow_button);
        mDecreaseFilter = (Button) view.findViewById(R.id.kfilter_down_arrow_button);
        mIncreaseAngle = (Button) view.findViewById(R.id.angle_up_arrow_button);
        mDecreaseAngle = (Button) view.findViewById(R.id.angle_down_arrow_button);
        initializeListeners();

        mFilterControl.setText("Filter Value\n" + String.format("%6.2f", mController.getKFactorValue()));
        mAngleSensitivity.setText(String.format("Angle Precision\n" + mController.getAnglePrecision()));

        mListener.adjustActivityForSettings();

        return view;
    }

    private void initializeListeners() {
        mResetNet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mController.resetNetValues();
            }
        });

        mIncreaseFilter.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mController.increaseFilterValue();
                mFilterControl.setText("Filter Value\n" + String.format("%6.2f", mController.getKFactorValue()));
            }
        });

        mDecreaseFilter.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mController.decreaseFilterValue();
                mFilterControl.setText("Filter Value\n" + String.format("%6.2f", mController.getKFactorValue()));
            }
        });

        mIncreaseAngle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mController.increaseAngleSensitivity();
                mAngleSensitivity.setText("Angle Precision\n" + mController.getAnglePrecision());
            }
        });

        mDecreaseAngle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mController.decreaseAngleSensitivity();
                mAngleSensitivity.setText("Angle Precision\n" + mController.getAnglePrecision());
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
        if (mController != null) {
            mController.registerSensor();
        }
    }

    @Override
    public void onStop() {
        super.onStop();
        mController.unregisterSensor();
    }

    @Override
    public void onBaseChangedListener(float baseValues[]) {
        if (mUnfiltered != null) {
            mUnfiltered.setText(
                    String.format("%-13s%8.2f%n", "Raw X:", baseValues[X]) +
                    String.format("%-13s%8.2f%n", "Raw Y:", baseValues[Y]) +
                    String.format("%-13s%8.2f%n", "Raw Z:", baseValues[Z]));
        }
    }

    @Override
    public void onDetach() {
        super.onDetach();
        mListener = null;
    }

    @Override
    public void onFilterChangedListener(float filteredValues[], float netValues[]) {
        if (mFiltered != null) {
            mFiltered.setText(
                    String.format("%-13s%8.2f%n", "Filtered X:", filteredValues[X]) +
                    String.format("%-13s%8.2f%n", "Filtered Y:", filteredValues[Y]) +
                    String.format("%-13s%8.2f%n", "Filtered Z:", filteredValues[Z]));
        }

        if (mNet != null) {
            mNet.setText(
                    String.format("%-13s%8.2f%n", "Net X:", netValues[X]) +
                    String.format("%-13s%8.2f%n", "Net Y:", netValues[Y]) +
                    String.format("%-13s%8.2f%n", "Net Z:", netValues[Z]));
        }
    }

    @Override
    public void onAngleChangeListener(int angleValue) {
        // TODO
    }
}
