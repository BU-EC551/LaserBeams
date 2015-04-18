package spring15.ec551.fpgacontroller.resources;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Typeface;
import android.util.AttributeSet;
import android.widget.TextView;

import spring15.ec551.fpgacontroller.R;

/**
 * Created by davidkim on 3/25/15.
 */
public class CustomTextView extends TextView{

    private static Typeface mTypeface;

    public CustomTextView(Context context) {
        super(context);
        if (!isInEditMode()) {
            init(context);
        }
    }

    public CustomTextView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        if (!isInEditMode()) {
            init(context);
        }
    }

    public CustomTextView(Context context, AttributeSet attrs) {
        super(context, attrs);
        if (!isInEditMode()) {
            init(context);
        }
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
    }

    private void init(Context context) {
        mTypeface = Typeface.createFromAsset(context.getAssets(), "roboto/roboto_light.ttf");
        this.setTypeface(mTypeface);
        this.setTextColor(getResources().getColor(R.color.flat_white));
    }
}
