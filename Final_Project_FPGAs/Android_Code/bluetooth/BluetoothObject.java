package spring15.ec551.fpgacontroller.bluetooth;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Set;
import java.util.UUID;

import spring15.ec551.fpgacontroller.activities.MainActivity;

/**
 * Created by davidkim on 4/30/15.
 *
 * A container object that stores all bluetooth-related subclasses, including subroutines, that
 * will allow users to connect to a device as a client (ConnectThread), or as a host (AcceptThread).
 * Documented and implemented for flexibility.  A gift to future EC551 students from me.
 *
 * This object should be instantiated at the main activity level as a static object.  It can then be configured
 * at any other fragments, provided that the main activity context is provided.
 *
 * Pairing is done at VehicleSettingsFragment
 *
 * Implementation example can be found at:
 *      @see spring15.ec551.fpgacontroller.fragments.PlayFragment
 *
 * Bluetooth functionality must be enabled at AndroidManifest.xml:
 *
 *     <uses-permission android:name="android.permission.BLUETOOTH" />
 *     <uses-permission android:name="android.permission.BLUETOOTH_ADMIN" />
 */
public class BluetoothObject {
    /** Used to identify various requests between bluetooth interface and Activity */
    public final int REQUEST_ENABLE_BT = 100;
    public final int REQUEST_DISCOVERABLE = 200;
    public final int READ_MESSAGE = 300;

    BluetoothAdapter mBTAdapter;
    ConnectedSocketThread mConnectedSocketThread;
    Set<BluetoothDevice> mPairedDevices;
    ArrayList<BluetoothDevice> mConnectedDevices;
    BluetoothConnectionStateListener mConnectionStateListener;

    Context mContext;

    // Status of whether bluetooth controller is connected
    private boolean isConnected;
    private boolean allowSendingData;

    public BluetoothObject(Context context) {
        mContext = context;
        isConnected = false;
        allowSendingData = false;

        mBTAdapter = BluetoothAdapter.getDefaultAdapter();
    }

    /** Checks whether device is bluetooth supported */
    public boolean isBluetoothSupported() {
        return (mBTAdapter != null);
    }

    /** Checks if Bluetooth is enabled - displays popup dialog if not enabled */
    public void checkEnabled() {
        if (!mBTAdapter.isEnabled()) {
            if (mContext != null) {
                Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                ((MainActivity) mContext).startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
                Toast.makeText(mContext,"Turned on",Toast.LENGTH_LONG).show();
            }
        } else {
            Toast.makeText(mContext,"Already on", Toast.LENGTH_LONG).show();
        }
    }

    /** Queries for paired devices
     *
     *  @return ArrayList<Bluetooth> object if devices found.
     *  Otherwise, it will return empty arraylist.
     */
    public ArrayList<BluetoothDevice> queryPairedDevices() {
        mPairedDevices = mBTAdapter.getBondedDevices();
        ArrayList<BluetoothDevice> pairedDevices = new ArrayList<>();
        if (mPairedDevices.size() > 0) {
            for (BluetoothDevice device : mPairedDevices) {
                pairedDevices.add(device);
            }
        }
        return pairedDevices;
    }

    /** Turns off Bluetooth */
    public void disableBluetooth(){
        mBTAdapter.disable();
        Toast.makeText(mContext,"Turned off" ,
                Toast.LENGTH_LONG).show();
    }

    public void registerReceivers() {
        IntentFilter connected_filter = new IntentFilter(BluetoothDevice.ACTION_ACL_CONNECTED);
        IntentFilter found_filter = new IntentFilter(BluetoothDevice.ACTION_FOUND);

        mContext.registerReceiver(mReceiver, connected_filter);
        mContext.registerReceiver(mReceiver, found_filter);
    }

    public void unregisterReceivers() {
        mContext.unregisterReceiver(mReceiver);
    }

    public void becomeDiscoverable() {
        Intent discoverableIntent = new Intent(BluetoothAdapter.
                ACTION_REQUEST_DISCOVERABLE);
        discoverableIntent.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, 30);
        ((MainActivity) mContext).startActivityForResult(discoverableIntent, REQUEST_DISCOVERABLE);
    }


    /**
     * Receiver used to notify user of Found Devices and Connected Devices.
     * If a pair device is successfully connected, the socket will be set to receive input
     * and output stream.
     */
    public final BroadcastReceiver mReceiver = new BroadcastReceiver() {
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            // When discovery finds a device
            if (BluetoothDevice.ACTION_FOUND.equals(action)) {
                ArrayList<BluetoothDevice> foundDevices = new ArrayList<>();
                // Get the BluetoothDevice object from the Intent
                BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                // Add the name and address to an array adapter to show in a ListView
                foundDevices.add(device);
            } else if (BluetoothDevice.ACTION_ACL_CONNECTED.equals(action)) {
                BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                mConnectedDevices = new ArrayList<>();
                mConnectedDevices.add(device);
                isConnected = true;
                if (mConnectionStateListener != null)
                    mConnectionStateListener.onConnectedDeviceUpdate(mConnectedDevices);
                Toast.makeText(mContext, "Connected Device " + device.getName(), Toast.LENGTH_LONG).show();
            }
        }
    };

    /** Returns state of whether vehicle has been connected or not (after attempting connection). */
    public boolean getConnectedSockets() {
        return isConnected;
    }

    public void connectToBTasClient(BluetoothDevice device, UUID uuid) {
        final ConnectThread connectThread = new ConnectThread(device, uuid);
        connectThread.start();
    }

    public void connectIOStream(BluetoothSocket socket) {
        if (socket.isConnected()) {
            mConnectedSocketThread = new ConnectedSocketThread(socket);
            mConnectedSocketThread.start();
        }

    }

    public void closeIOStream() {
        mConnectedSocketThread.cancel();
    }

    public void sendByte(int one_byte) {
        mConnectedSocketThread.write(one_byte);
    }

    public void setConnectionStateListener(BluetoothConnectionStateListener listener) {
        mConnectionStateListener = listener;
    }

    public interface BluetoothConnectionStateListener {
        public void onConnectedDeviceUpdate(ArrayList<BluetoothDevice> list);
    }

    public void sendBytes(byte[] bytes) {
//        for (int i=0; i < bytes.length; i++) {
//            Log.d("" + i + ": ", "" + Integer.toHexString(bytes[i]) + "\n" );
//        }
        mConnectedSocketThread.write(bytes);
    }



//    @Override
//    public void sendbits(byte[] bytes_) {
//        connectedThread.write(bytes_);
//    }
//
//    @Override
//    public void startreceivinginputs(boolean b) {
//        if (b) {
//            Message msg = new Message();
//            fragment = (PlayFragment) getFragmentManager().findFragmentByTag(FREE_ROAM_FRAGMENT);

//
//        }
//    }

}
