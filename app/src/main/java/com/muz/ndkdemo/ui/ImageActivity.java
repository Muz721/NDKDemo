package com.muz.ndkdemo.ui;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.muz.ndkdemo.R;
import com.muz.ndkdemo.util.JavaImageUtils;
import com.muz.ndkdemo.util.NDKUtils;

/**
 * Created by Administrator on 2018/11/12.
 */

public class ImageActivity extends AppCompatActivity implements View.OnClickListener {
    private ImageView mImageView;
    private TextView mOriginal, mJava, mNdk, mTextview;

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.original:
                srcImage(mImageView);
                break;
            case R.id.java:
                javaImage(mImageView);
                break;
            case R.id.ndk:
                ndkImage(mImageView);
                break;
            default:
                break;
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image);

        mOriginal = (TextView)findViewById(R.id.original);
        mJava = (TextView)findViewById(R.id.java);
        mNdk = (TextView)findViewById(R.id.ndk);
        mImageView = (ImageView)findViewById(R.id.imageView);
        mTextview = (TextView)findViewById(R.id.textview);

        mOriginal.setOnClickListener(this);
        mJava.setOnClickListener(this);
        mNdk.setOnClickListener(this);
    }

    /**
     * 设置原图
     * @param imageView
     */
    public void srcImage(ImageView imageView){
        long start = System.currentTimeMillis();
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.img_4);
        long end = System.currentTimeMillis();
        mTextview.setText("原图展示" + (end - start) + "ms");
        imageView.setImageBitmap(bitmap);
    }

    /**
     * java处理图片
     * @param imageView
     */
    public void javaImage(ImageView imageView){
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.img_4);

        long start = System.currentTimeMillis();
        Bitmap result = JavaImageUtils.getImage(bitmap);
        long end = System.currentTimeMillis();
        mTextview.setText("java处理时间---" + (end - start) + "ms");

        imageView.setImageBitmap(result);
    }

    /**
     * ndk处理图片
     * @param imageView
     */
    public void ndkImage(ImageView imageView){
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.img_4);

        long start = System.currentTimeMillis();
        int width = bitmap.getWidth();
        int height = bitmap.getHeight();
        int[] buffer = new int[width * height];
        bitmap.getPixels(buffer, 0, width, 1, 1, width - 1, height - 1);
        int[] resultArray = NDKUtils.imageBrightnessJNI(buffer, width, height);
        Bitmap result = Bitmap.createBitmap(resultArray, width, height, Bitmap.Config.RGB_565);
        long end = System.currentTimeMillis();
        mTextview.setText("ndk处理时间---" + (end - start) + "ms");

        imageView.setImageBitmap(result);
    }
}
