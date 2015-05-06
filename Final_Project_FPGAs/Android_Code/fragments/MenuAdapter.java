package spring15.ec551.fpgacontroller.fragments;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;

import java.util.ArrayList;

import spring15.ec551.fpgacontroller.R;
import spring15.ec551.fpgacontroller.resources.CustomTextView;

/**
 * Created by davidkim on 3/25/15.
 */
public class MenuAdapter extends ArrayAdapter<String> {

    ArrayList<String> mList;
    Context mContext;
    LayoutInflater mLayoutInflator;

    /** To prevent any attempts to load a null user mPairedList,
     *  the constructor will check the mPairedList and only assign if it
     *  isn't null. */
    public MenuAdapter(Context context, ArrayList<String> list) {
        super(context, 0);
        mList = new ArrayList<>();
        mContext = context;
        mLayoutInflator = (LayoutInflater) mContext
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        if (list != null) {
            mList = list;
        }
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public String getItem(int position) {
        return mList.get(position);
    }

    @Override
    public int getCount() {
        return mList.size();
    }

    /** Called upon a sucessful server response.  This will
     *  assign the new values to the fragment mPairedList, then invoke a refresh
     *  call.
     */
    public void updateList(ArrayList<String> users) {
        mList = users;
        notifyDataSetChanged();
    }


    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;
        // If no existing view being reused inflate the view, otherwise retrieve
        // the cached viewHolder
        if (convertView == null) {
            convertView = mLayoutInflator.inflate(R.layout.layout_custom_listview_item, parent, false);
            viewHolder = new ViewHolder();
            viewHolder.customTextView = (CustomTextView) convertView.findViewById(R.id.custom_text_view);
            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder) convertView.getTag();
        }

        String menuItem = mList.get(position);

        if (menuItem != null) {
            viewHolder.customTextView.setText(menuItem);
        }

        return convertView;
    }

    /** Using ViewHolder improves performance by caching the data for
     *  faster loads */
    private static class ViewHolder {
        CustomTextView customTextView;
    }


}
