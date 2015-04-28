package spring15.ec551.fpgacontroller.accelerometer;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Parcel;
import android.os.Parcelable;
import android.util.Log;

/**
 * Created by davidkim on 3/26/15.
 * The controller object that will be used throughout the application.  This class
 * implements the accelerometer, processing its information with the the high pass filter.
 * It will output base, filtered, and net values.  In addition, it will output angle degrees
 * using a precision value.  It will also be able to save and load configurations.
 */
public class ControllerObject implements SensorEventListener, Parcelable {
    final int X = 0;
    final int Y = 1;
    final int Z = 2;

    // Default values used for this app
    final float DEFAULT_K_FACTOR = 0.65f;
    final int DEFAULT_BOUND = 5;
    final float ZERO_FLOAT = 0.0f;

    // Threshold for kFactor Limit (only used for examine accelerometer fragment)
    final float KFACTOR_LIMIT = 1.0f;
    final float KFACTOR_INCREMENT = 0.05f;

    // Sensor Objects
    private SensorManager mSensorManager;
    private Sensor mAccelerometer;

    /** Filter implementation */
    private AccelerometerHighPassFilter mFilter;

    /** Interface that outputs XYZ data from sensor */
    public ControllerInterfaceListener mInterface;

    /** The accelerometer values from AccelerometerHighPassFilter */
    float mBaseValues[];
    float mFilterValues[];
    float mNetValues[];

    /** Checks for whether the controller has been configured by user. */
    private boolean isConfigured;

    /** Used to calculate the angle **/
    float mAnglePrecision;
    int mLeftBound;               // Uses integer for precision purposes
    int mRightBound;              // Uses integer for precision purposes
    final float ANGLE_SENSITIVITY_HIGH_LIMIT = 10.0f;
    final float ANGLE_INCREMENT = 0.5f;

    /** Implements an empty controller object for activity level. This should not
     *  initially be set to listen to anything */
    public ControllerObject(Context context) {
        this(context, null);
    }

    /** Implements default values */
    public ControllerObject(Context context, ControllerInterfaceListener interfacer) {
        isConfigured = false;

        if (interfacer != null)
            mInterface = interfacer;

        /** Initialize object with default values */
        setDefaultSettings();

        mSensorManager = (SensorManager)context.getSystemService(Context.SENSOR_SERVICE);
        if (mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER) != null) {
            mAccelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        }
    }

    public void setDefaultSettings() {
        mBaseValues = new float[]{ZERO_FLOAT, ZERO_FLOAT, ZERO_FLOAT};
        mFilterValues = new float[]{ZERO_FLOAT, ZERO_FLOAT, ZERO_FLOAT};
        mNetValues = new float[]{ZERO_FLOAT, ZERO_FLOAT, ZERO_FLOAT};
        mLeftBound = DEFAULT_BOUND;
        mRightBound = DEFAULT_BOUND;
        mAnglePrecision = 1.0f;
        mFilter = new AccelerometerHighPassFilter(DEFAULT_K_FACTOR);
    }

    public void setSavedSettings(ControllerObject object) {
        mBaseValues = object.getBaseValue();
        mFilterValues = object.getFilterValues();
        mNetValues = object.getNetValue();
        mLeftBound = object.getLeftBound();
        mRightBound = object.getRightBound();
        mAnglePrecision = object.getAnglePrecision();
        mFilter = new AccelerometerHighPassFilter(DEFAULT_K_FACTOR);
    }

    /** Getters */
    public float    getKFactorValue()   { return this.mFilter.kFilteringFactor; }
    public float[]  getBaseValue()      { return this.mBaseValues; }
    public float[]  getFilterValues()   { return this.mFilterValues; }
    public float[]  getNetValue()       { return this.mNetValues; }
    public int      getLeftBound()      { return this.mLeftBound; }
    public int      getRightBound()     { return this.mRightBound; }
    public float    getAnglePrecision() { return this.mAnglePrecision; }

    /** Used to set the starting net baseline */
    public void resetNetValues() {
        mNetValues[X] = ZERO_FLOAT;
        mNetValues[Y] = ZERO_FLOAT;
        mNetValues[Z] = ZERO_FLOAT;
    }

    public void setInterface(ControllerInterfaceListener interfaceListener) {
        mInterface = interfaceListener;
    }

    /** Set the state of whether controller has been configured */
    public void setConfiguredState(boolean state) {
        isConfigured = state;
    }

    /** Get the current state of controller configuration */
    public boolean getConfiguredState() {
        return isConfigured;
    }

    /** Attach and detach sensor */
    public void registerSensor() {
        mSensorManager.registerListener(this, mAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);
    }
    public void unregisterSensor() {
        mSensorManager.unregisterListener(this);
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
        Log.d("ACCURACYCHANGED: ", "Integer: " + accuracy);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        mBaseValues[X] = event.values[X];
        mBaseValues[Y] = event.values[Y];
        mBaseValues[Z] = event.values[Z];

        mFilterValues = mFilter.getFilteredAccelerometerValues(
                event.values[X],
                event.values[Y],
                event.values[Z]);

        mNetValues[X] += mFilterValues[X];
        mNetValues[Y] += mFilterValues[Y];
        mNetValues[Z] += mFilterValues[Z];

        if (mInterface != null) {
            mInterface.onBaseChangedListener(mBaseValues);
            mInterface.onFilterChangedListener(mFilterValues, mNetValues);

            if (mLeftBound != 0 && mRightBound != 0) {
                calculateAngle();
            }
        }
    }

    /** Calculates the angle value */
    public void calculateAngle() {
        float xySum = (Math.abs(mNetValues[X]) + Math.abs(mNetValues[Y])) / 2;

        if (mNetValues[Y] < 0) {
            int rawAngle = (int)((xySum/ (float)mLeftBound) * 90);
            if (rawAngle > 90) {
                mInterface.onAngleChangeListener(-90);
            } else {
                mInterface.onAngleChangeListener(-1*rawAngle);
            }
        } else {
            int rawAngle = (int)((xySum/ (float)mRightBound) * 90);
            if (rawAngle > 90) {
                mInterface.onAngleChangeListener(90);
            } else {
                mInterface.onAngleChangeListener(rawAngle);
            }
        }
    }

    /** The following methods are used for examine accelerometer only
     *  (not in configure and vehicle control) */
    public void increaseFilterValue() {
        if (mFilter.kFilteringFactor < KFACTOR_LIMIT) {
            if (mFilter.kFilteringFactor > KFACTOR_LIMIT - KFACTOR_INCREMENT) {
                mFilter.kFilteringFactor = KFACTOR_LIMIT;
            } else {
                mFilter.kFilteringFactor += KFACTOR_INCREMENT;
            }
        }
    }
    public void decreaseFilterValue() {
        if (mFilter.kFilteringFactor > ZERO_FLOAT) {
            if (mFilter.kFilteringFactor < ZERO_FLOAT + KFACTOR_INCREMENT) {
                mFilter.kFilteringFactor = ZERO_FLOAT;
            } else {
                mFilter.kFilteringFactor -= KFACTOR_INCREMENT;
            }
        }
    }
    public void setAnglePrecision(float precision) {
        mAnglePrecision = precision;
    }
    public void increaseAngleSensitivity() {
        if (mAnglePrecision < ANGLE_SENSITIVITY_HIGH_LIMIT) {
            if (mAnglePrecision > ANGLE_SENSITIVITY_HIGH_LIMIT - ANGLE_INCREMENT) {
                mAnglePrecision = ANGLE_SENSITIVITY_HIGH_LIMIT;
            } else {
                mAnglePrecision += ANGLE_INCREMENT;
            }
        }
    }
    public void decreaseAngleSensitivity() {
        if (mAnglePrecision > ZERO_FLOAT) {
            if (mAnglePrecision < ZERO_FLOAT + ANGLE_INCREMENT) {
                mAnglePrecision = ZERO_FLOAT;
            } else {
                mAnglePrecision -= ANGLE_INCREMENT;
            }
        }
    }
    /********************************************************************************************/

    /** Parcelable implementation */
    protected ControllerObject(Parcel in) {
        mBaseValues = new float[3];
        in.readFloatArray(mBaseValues);
        mFilterValues = new float[3];
        in.readFloatArray(mFilterValues);
        mNetValues = new float[3];
        in.readFloatArray(mNetValues);
        mAnglePrecision = in.readFloat();
        mLeftBound = in.readInt();
        mRightBound = in.readInt();
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeFloatArray(mBaseValues);
        dest.writeFloatArray(mFilterValues);
        dest.writeFloatArray(mNetValues);
        dest.writeFloat(mAnglePrecision);
        dest.writeInt(mLeftBound);
        dest.writeInt(mRightBound);
    }

    @SuppressWarnings("unused")
    public static final Parcelable.Creator<ControllerObject> CREATOR = new Parcelable.Creator<ControllerObject>() {
        @Override
        public ControllerObject createFromParcel(Parcel in) {
            return new ControllerObject(in);
        }

        @Override
        public ControllerObject[] newArray(int size) {
            return new ControllerObject[size];
        }
    };
}

