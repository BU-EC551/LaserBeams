package spring15.ec551.fpgacontroller.resources;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.ProgressBar;
import java.util.Timer;
import java.util.TimerTask;

import spring15.ec551.fpgacontroller.R;
import spring15.ec551.fpgacontroller.activities.MainActivity;
import spring15.ec551.fpgacontroller.fragments.PlayFragment;

/**
 * Created by davidkim on 4/12/15.
 */
public class AmmoSlider extends ProgressBar{
    // Default reload time is set to 3 seconds
    final int RELOAD_MAX = 60;  // 60 iterations
    final int INCREMENT = 1;
    final int TIME = 50;       // 0.05 second

    // Default Ammo
    final int DEFAULT_MAX_AMMO = 50;

    int mMaxAmmo;

    Context mContext;
    Timer mTimer;
    
    public AmmoSlider(Context context) {
        this(context, null);
    }

    public AmmoSlider(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public AmmoSlider(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        mContext = context;
        mTimer = new Timer();
        initializeAmmo(DEFAULT_MAX_AMMO);
    }

    public void initializeAmmo(int maxAmmo) {
        mMaxAmmo = maxAmmo;
        setProgressDrawable(getResources().getDrawable(R.drawable.ammo_seekbar));
        setMax(mMaxAmmo);
        setProgress(mMaxAmmo);
    }


    public void startReload() {
        setProgressDrawable(getResources().getDrawable(R.drawable.reload_seekbar));
        setMax(RELOAD_MAX);
        setProgress(0);
        mTimer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                ((MainActivity) mContext).runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        if (getProgress() < RELOAD_MAX) {
                            setProgress(getProgress() + INCREMENT);
                        } else {
                            cancel();
                            setProgress(0);
                            finishReload();
                        }

                    }
                });
            }
        }, 0, TIME);
    }

    /** This invokes PlayFragment method */
    private void finishReload() {
        setProgressDrawable(getResources().getDrawable(R.drawable.ammo_seekbar));
        setMax(mMaxAmmo);
        setProgress(mMaxAmmo);
        PlayFragment fragment = (PlayFragment)((MainActivity) mContext).getFragmentManager().findFragmentByTag(MainActivity.FREE_ROAM_FRAGMENT);
        fragment.finishReloading();
    }


}
