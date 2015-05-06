package spring15.ec551.fpgacontroller.bluetooth;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import java.io.IOException;
import java.util.UUID;

import spring15.ec551.fpgacontroller.activities.MainActivity;

/**
 * Created by davidkim on 3/26/15.
 * Used to connect to a device on a separate thread.
 */

public class ConnectThread extends Thread {
    BluetoothAdapter adapter;
    private final BluetoothSocket mmSocket;
    final BluetoothDevice mmDevice;

    // UUID Provided
    public ConnectThread(BluetoothDevice device, UUID uuid) {
        BluetoothSocket tmp = null;
        mmDevice = device;
        adapter = BluetoothAdapter.getDefaultAdapter();

        try {
            tmp = device.createRfcommSocketToServiceRecord(uuid);
        } catch (IOException e) {
            e.printStackTrace();
        }
        mmSocket = tmp;
    }

    public void run() {
        adapter.cancelDiscovery();

        try {
            // Connect the device through the socket. This is a blocking request
            // until it succeeds or throws an exception
            mmSocket.connect();
        } catch (IOException connectException) {

            // Unable to connect; close the socket and get out
            try {
                mmSocket.close();
            } catch (IOException closeException) {
                closeException.printStackTrace();
            }
        }

        MainActivity.BluetoothStaticObject.connectIOStream(mmSocket);
    }

    /** Will cancel an in-progress connection, and cause the thread to finish */
    public void cancel() {
        try {
            mmSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}