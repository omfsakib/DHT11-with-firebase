package com.myapp.dht11firebase.ui.main;

import android.content.Context;

import androidx.annotation.Nullable;
import androidx.annotation.StringRes;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;

import com.myapp.dht11firebase.R;


public class SectionsPagerAdapter extends FragmentPagerAdapter {

    public SectionsPagerAdapter(Context context, FragmentManager fm) {
        super(fm);
    }

    @Override
    public Fragment getItem(int position) {
        switch (position) {
            case 0: return  new TemperatureFragment();
            case  1: return  new HumidityFragment();
            default:
                throw new IllegalStateException("Unexpected value: " + position);
        }
    }


    @Override
    public int getCount() {
        // Show 2 total pages.
        return 2;
    }
}