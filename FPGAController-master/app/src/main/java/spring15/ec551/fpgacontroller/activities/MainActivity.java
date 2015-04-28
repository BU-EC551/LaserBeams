package spring15.ec551.fpgacontroller.activities;

import android.app.FragmentTransaction;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.RelativeLayout;
import spring15.ec551.fpgacontroller.R;
import spring15.ec551.fpgacontroller.accelerometer.ControllerObject;
import spring15.ec551.fpgacontroller.fragments.CalibrateControllerFragment;
import spring15.ec551.fpgacontroller.fragments.ExamineAccelFragment;
import spring15.ec551.fpgacontroller.fragments.FragmentActionListener;
import spring15.ec551.fpgacontroller.fragments.MenuFragment;
import spring15.ec551.fpgacontroller.fragments.PlayFragment;
import spring15.ec551.fpgacontroller.resources.CustomTextView;

public class MainActivity extends ActionBarActivity implements FragmentActionListener {

    // Tags used for Fragment Transactions
    final String MENU_FRAGMENT = "MENU_FRAGMENT";
    final String EXAMINE_ACCEL_FRAGMENT = "EXAMINE_ACCEL_FRAGMENT";
    final String CONTROLLER_SETTINGS_FRAGMENT = "CONTROLLER_SETTINGS_FRAGMENT";
    public final static String FREE_ROAM_FRAGMENT = "FREE_ROAM_FRAGMENT";

    // Controller object that is used throughout the application.
    public static ControllerObject mControllerObject;

    // Layout items
    FrameLayout mFragmentContainer;
    RelativeLayout mTopHudContainer;
    CustomTextView mControllerIndicator;
    CustomTextView mVehicleIndicator;
    Button mBackButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // Hides action-menu bar
        getSupportActionBar().setBackgroundDrawable(new ColorDrawable(Color.parseColor("#00FFFFFF")));
        getSupportActionBar().hide();
        setContentView(R.layout.activity_main);

        // Initialize the controller object
        mControllerObject = new ControllerObject(getBaseContext());

        mFragmentContainer = (FrameLayout) findViewById(R.id.fragment_container);
        mTopHudContainer = (RelativeLayout) findViewById(R.id.top_hud_container);
        mControllerIndicator = (CustomTextView) findViewById(R.id.controller_text);
        mVehicleIndicator = (CustomTextView) findViewById(R.id.vehicle_text);
        mBackButton = (Button) findViewById(R.id.back_button);
        setBackButtonListener();

        // Check for connection
        isControllerConfigured();
        isVehicleConnected();

        // If no fragment is visible
        if (savedInstanceState == null) {
            initializeMenuFragment();
        }
    }

    /** Initialize back button */
    private void setBackButtonListener() {
        mBackButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getFragmentManager().popBackStack();
                mBackButton.setVisibility(View.INVISIBLE);
            }
        });
    }

    /** Listener for MenuFragment ListView */
    @Override
    public void onMenuItemClickListener(String itemName) {
        switch (itemName) {
            case MenuFragment.EXAMINE_ACCEL:
                initializeExamineAccelFragment();
                break;
            case MenuFragment.CALIBRATE_CONTROLLER:
                initializeControllerSettingsFragment();
                break;
            case MenuFragment.FREE_ROAM:
                initializeFreeRoamFragment();
                break;
        }
    }

    /** MenuFragment Transactions */
    private void initializeMenuFragment() {
        MenuFragment menuFragment = MenuFragment.newInstance();
        FragmentTransaction transaction = getFragmentManager().beginTransaction();
        transaction.replace(R.id.fragment_container, menuFragment, MENU_FRAGMENT);
        transaction.addToBackStack(null);
        transaction.commit();
    }

    /** ExamineAccelFragment initializer */
    public void initializeExamineAccelFragment() {
        ExamineAccelFragment examineAccelFragment = ExamineAccelFragment.newInstance();
        FragmentTransaction transaction = getFragmentManager().beginTransaction();
        transaction.replace(R.id.fragment_container, examineAccelFragment, EXAMINE_ACCEL_FRAGMENT);
        transaction.addToBackStack(EXAMINE_ACCEL_FRAGMENT);
        transaction.commit();
    }

    /** ControllerSettingsFragment initializer */
    private void initializeControllerSettingsFragment() {
        CalibrateControllerFragment calibrateControllerFragment = CalibrateControllerFragment.newInstance();
        FragmentTransaction transaction = getFragmentManager().beginTransaction();
        transaction.replace(R.id.fragment_container, calibrateControllerFragment, CONTROLLER_SETTINGS_FRAGMENT);
        transaction.addToBackStack(CONTROLLER_SETTINGS_FRAGMENT);
        transaction.commit();
    }

    /** FreeRoamFragment initializer */
    private void initializeFreeRoamFragment() {
        PlayFragment playFragment = PlayFragment.newInstance();
        FragmentTransaction transaction = getFragmentManager().beginTransaction();
        transaction.replace(R.id.fragment_container, playFragment, FREE_ROAM_FRAGMENT);
        transaction.addToBackStack(FREE_ROAM_FRAGMENT);
        transaction.commit();
    }

    @Override
    public void adjustActivityForMainMenu() {
        mBackButton.setVisibility(View.INVISIBLE);
        mTopHudContainer.setVisibility(View.VISIBLE);
    }

    @Override
    public void adjustActivityForSettings() {
        mBackButton.setVisibility(View.VISIBLE);
        mTopHudContainer.setVisibility(View.INVISIBLE);
    }

    public void adjustActivityForPlay() {
        mBackButton.setVisibility(View.INVISIBLE);
        mTopHudContainer.setVisibility(View.INVISIBLE);

        RelativeLayout layout = (RelativeLayout) findViewById(R.id.activity_layout);
        layout.setBackgroundColor(getResources().getColor(R.color.flat_black1));

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    /** Action Bar Listener */
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void updateControllerSavedStateDisplay() {
        isControllerConfigured();
    }

    /** Checks for the status of controller (connection).  Will update color status
     *  and can also be used to return a boolean value of status
     *  @return true if configured.
     */
    public boolean isControllerConfigured() {
        if (mControllerObject.getConfiguredState()) {
            mControllerIndicator.setBackgroundResource(R.color.flat_green);
            return true;
        } else {
            mControllerIndicator.setBackgroundResource(R.color.flat_red2);
            return false;
        }
    }

    // TODO Change color when connected
    public boolean isVehicleConnected() {
        mVehicleIndicator.setBackgroundResource(R.color.flat_red2);
        return false;
    }

}
