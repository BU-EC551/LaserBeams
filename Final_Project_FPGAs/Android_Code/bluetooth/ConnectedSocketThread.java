package spring15.ec551.fpgacontroller.bluetooth;

import android.bluetooth.BluetoothSocket;
import android.os.Handler;
import android.os.Message;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import spring15.ec551.fpgacontroller.activities.MainActivity;

/**
 * Created by davidkim on 4/30/15.
 */
public class ConnectedSocketThread extends Thread {

    private final BluetoothSocket mmSocket;
    private final InputStream mmInStream;
    private final OutputStream mmOutStream;
    Handler mHandler;

    public ConnectedSocketThread(BluetoothSocket socket) {
        mmSocket = socket;
        InputStream tmpIn = null;
        OutputStream tmpOut = null;

        // Get the input and output streams, using temp objects because
        // member streams are final
        try {
            tmpIn = socket.getInputStream();
            tmpOut = socket.getOutputStream();
        } catch (IOException e) {
            e.printStackTrace();
        }

        mmInStream = tmpIn;
        mmOutStream = tmpOut;
    }

    public void run() {
        byte[] buffer = new byte[1024];  // buffer store for the stream
        int bytes; // bytes returned from read()

        // Keep listening to the InputStream until an exception occurs
        while (true) {
            try {
                // Read from the InputStream
                bytes = mmInStream.read(buffer);
                System.out.println("" + bytes + "\n");

                // Send the obtained bytes to the UI activity
                mHandler.obtainMessage(MainActivity.BluetoothStaticObject.READ_MESSAGE, bytes, -1, buffer)
                        .sendToTarget();
                mHandler.dispatchMessage(Message.obtain());
            } catch (IOException e) {
                break;
            }
        }
    }

    /* Call this from the main activity to send data to the remote device */
    public void write(int one_byte) {
        try {
            mmOutStream.flush();
            mmOutStream.write(one_byte);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void write(byte[] bytes) {
        try {
            mmOutStream.write(bytes);
        } catch (IOException e) { e.printStackTrace();}
    }

    /* Call this from the main activity to shutdown the connection */
    public void cancel() {
        try {
            mmSocket.close();
        } catch (IOException e) { }
    }
}
