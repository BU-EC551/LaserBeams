package spring15.ec551.fpgacontroller.bluetooth;

/**
 * Created by davidkim on 3/26/15.
 */
public class ConnectThread extends Thread {
    /*
    private final BluetoothSocket mSocket;
    private final BluetoothDevice mDevice;
    private BluetoothAdapter mBluetoothAdapter;
//    public BluetoothConnectionListener mListener;

    public ConnectThread(MainActivity activity, BluetoothDevice device) {
//        mListener = activity;
        BluetoothSocket tmp = null;
        mDevice = device;

        try {
            tmp = device.createRfcommSocketToServiceRecord(MainActivity.mUUID);
        } catch (IOException e) {
            e.printStackTrace();
        }
        mSocket = tmp;
    }

    @Override
    public void run() {
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        mBluetoothAdapter.cancelDiscovery();

        try {
            mSocket.connect();
        } catch (IOException connectException) {
            cancel();
            return;
        }

//        mListener.onSuccessfulPairing(mSocket);
    }

    public void cancel() {
        try {
            mSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


*/
}
