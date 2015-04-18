package spring15.ec551.fpgacontroller.resources;

import android.content.Context;
import android.graphics.Canvas;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.widget.SeekBar;

import java.util.Timer;
import java.util.TimerTask;

import spring15.ec551.fpgacontroller.R;
import spring15.ec551.fpgacontroller.activities.MainActivity;

/**
 * Created by davidkim on 4/9/15.
 */
public class ThrottleSlider extends SeekBar {
    public static final int MAX_PROGRESS = 200;
    public static final int MID_PROGRESS = 100;
    Timer timer;
    Context mContext;
    boolean cancelTimer;

    public ThrottleSlider(Context context) {
        this(context, null);
    }

    public ThrottleSlider(Context context, AttributeSet attrs) {
        this(context,attrs, 0);
    }

    public ThrottleSlider(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        mContext = context;
        timer = new Timer();
        initializeProgressBar();
    }



    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(h, w, oldh, oldw);
    }

    @Override
    protected synchronized void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(heightMeasureSpec, widthMeasureSpec);
        setMeasuredDimension(getMeasuredHeight(), getMeasuredWidth());
    }

    protected void onDraw(Canvas c) {
        c.rotate(-90);
        c.translate(-getHeight(), 0);

        super.onDraw(c);
    }

    @Override
    public synchronized void setProgress(int progress) {
        super.setProgress(progress);
        onSizeChanged(getWidth(), getHeight(), 0, 0);
    }


    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (!isEnabled()) {
            return false;
        }

        switch (event.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_POINTER_DOWN:
                cancelTimer = true;
                break;
            case MotionEvent.ACTION_MOVE:
                cancelTimer = true;
                setProgress(getMax() - (int) (getMax() * event.getY() / getHeight()));
                onSizeChanged(getWidth(), getHeight(), 0, 0);
                break;
            case MotionEvent.ACTION_POINTER_UP:
                cancelTimer = true;
                break;
            case MotionEvent.ACTION_UP:
                cancelTimer = false;
                timer.scheduleAtFixedRate(new TimerTask() {
                    @Override
                    public void run() {
                        ((MainActivity) mContext).runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (getProgress() == MID_PROGRESS || cancelTimer)
                                    cancel();
                                else if (getProgress() < MID_PROGRESS)
                                    setProgress(getProgress()+1);
                                else
                                    setProgress(getProgress()-1);
                            }
                        });
                    }
                }, 0, 10);
                break;
            case MotionEvent.ACTION_CANCEL:
                break;

        }
        return true;
    }

    public void onActionMove(MotionEvent event) {
        setProgress(getMax() - (int) (getMax() * event.getY() / getHeight()));
        onSizeChanged(getWidth(), getHeight(), 0, 0);
    }
    private void initializeProgressBar() {
        setProgressDrawable(getResources().getDrawable(R.drawable.throttle_seekbar));
        setThumb(getResources().getDrawable(R.drawable.throttle_thumb));
        setThumbOffset(0);
        setMax(MAX_PROGRESS);
        setProgress(MID_PROGRESS);
    }



    @Override
    public void setOnSeekBarChangeListener(OnSeekBarChangeListener l) {
        super.setOnSeekBarChangeListener(l);
    }
}
