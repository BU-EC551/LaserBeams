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
public class FixedWidthTextView extends TextView{

    private static Typeface mTypeface;

    public FixedWidthTextView(Context context) {
        super(context);
        mTypeface = Typeface.createFromAsset(context.getAssets(), "inconsolata/inconsolata_regular.otf");
        this.setTypeface(mTypeface);
        this.setTextColor(getResources().getColor(R.color.flat_white));
    }

    public FixedWidthTextView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        mTypeface = Typeface.createFromAsset(context.getAssets(), "inconsolata/inconsolata_regular.otf");
        this.setTypeface(mTypeface);
        this.setTextColor(getResources().getColor(R.color.flat_white));
    }

    public FixedWidthTextView(Context context, AttributeSet attrs) {
        super(context, attrs);
        mTypeface = Typeface.createFromAsset(context.getAssets(), "inconsolata/inconsolata_regular.otf");
        this.setTypeface(mTypeface);
        this.setTextColor(getResources().getColor(R.color.flat_white));
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
    }
}
