package spring15.ec551.fpgacontroller.bluetooth;

import android.bluetooth.BluetoothServerSocket;

/**
 * Created by davidkim on 3/26/15.
 */
public interface BluetoothConnectionListener {
    public void onSuccessfulPairing(BluetoothServerSocket socket);
}
