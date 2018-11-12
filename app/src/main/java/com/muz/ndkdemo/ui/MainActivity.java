package com.muz.ndkdemo.ui;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

import com.muz.ndkdemo.R;
import com.muz.ndkdemo.util.NDKUtils;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.


    int fff = 33;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        fff = max();
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI()+"___"+isMaxOther(6,4));
//        int[] array = array(6,4);
        int[] arrayArray = {3, 4, 1, 5, 9, 6, 8, 7};
//        Log.e("array=",array[0]+","+array[1]+","+array[2]);
        arrayArray = NDKUtils.arrayArrayJNI(arrayArray);
        for (int i = 0; i < arrayArray.length; i++) {
            Log.e("arrayArray=", arrayArray[i] + "");
        }
        int[] array = NDKUtils.arrayOtherJNI(6,4);
        for (int i = 0; i < array.length; i++) {
            Log.e("array=", array[i] + "");
        }
        //tv.setText(NDKUtils.stringFromMainJNI()+"___"+NDKUtils.maxMainJNI());
//        tv.setText(NDKUtils.spliceJNI());
        tv.setText(NDKUtils.md5JNI("admin"));
//        NDKUtils.md5JNI("admin");
    }
}

