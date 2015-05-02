package spring15.ec551.fpgacontroller.accelerometer;


/**
 * Created by davidkim on 3/26/15.
 * A filtering object that was implemented off of Apple's SDK implementation of Kalman filtering.
 * This algorithm will apply a cutoff for frequency and filter noises while
 * normalizing the averaged values over a continuous frequency cycle set of x,y,z values
 * received from the accelerometer.
 *
 * Implementation found at StackOverflow:
 * http://stackoverflow.com/questions/1638864/filtering-accelerometer-data-noise
 */
public class AccelerometerHighPassFilter {
    private static final float MAX_FLOAT = 1.0f;
    final int X = 0;
    final int Y = 1;
    final int Z = 2;
    float kFilteringFactor = 0.0f;

    /** Implement two float arrays which respond to X,Y,Z coordinates in ascending order */
    float mPrevAccel[] = {0.0f, 0.0f, 0.0f};
    float mAccel[] = {0.0f, 0.0f, 0.0f};

    public AccelerometerHighPassFilter(float factor) {
        kFilteringFactor = factor;
    }

    /** Will apply the filter, then send the values back to the object listening for it */
    public float[] getFilteredAccelerometerValues(float accelX, float accelY, float accelZ) {
        mPrevAccel[X] = accelX * kFilteringFactor + mPrevAccel[X] * (MAX_FLOAT - kFilteringFactor);
        mPrevAccel[Y] = accelY * kFilteringFactor + mPrevAccel[Y] * (MAX_FLOAT - kFilteringFactor);
        mPrevAccel[Z] = accelZ * kFilteringFactor + mPrevAccel[Z] * (MAX_FLOAT - kFilteringFactor);

        mAccel[X] = accelX - mPrevAccel[X];
        mAccel[Y] = accelY - mPrevAccel[Y];
        mAccel[Z] = accelZ - mPrevAccel[Z];

        return new float[] {mAccel[X], mAccel[Y], mAccel[Z]};
    }

}
