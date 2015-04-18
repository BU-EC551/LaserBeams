package spring15.ec551.fpgacontroller.bluetooth;

/**
 * Created by davidkim on 3/26/15.
 */

public class AcceptThread extends Thread {}
    /*
    private final BluetoothServerSocket mServerSocket;
    private BluetoothAdapter mBluetoothAdapter = null;
    public BluetoothConnectionListener mListener;



    public AcceptThread(MainActivity activity) {
        mListener = activity;
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        BluetoothServerSocket tempServerSocket = null;

        try {
            tempServerSocket = mBluetoothAdapter.listenUsingRfcommWithServiceRecord(MainActivity.mServiceString, MainActivity.mUUID);
        } catch (IOException e) {
            e.printStackTrace();
        }

        mServerSocket = tempServerSocket;
    }

    @Override
    public void run() {
        BluetoothSocket socket = null;
        while (true) {
            try {
                socket = mServerSocket.accept();
            } catch (IOException e) {
                break;
            }

            if (socket != null) {
                mListener.onSuccessfulPairing(mServerSocket);
//                cancel();
                }
            }
        }

    public void cancel() {
        try {
            mServerSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
*/