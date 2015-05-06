package spring15.ec551.fpgacontroller.accelerometer;

/**
 * Created by davidkim on 3/28/15.
 * Allows for classes that implement this interface to be able to listen to outgoing accelerometer
 * signals from ControllerStaticObject.
 */
public interface ControllerInterfaceListener {

    public void onBaseChangedListener(float[] baseValues);

    public void onFilterChangedListener(float[] filterValues, float[] netValues);

    public void onAngleChangeListener(int angleValue);
}
