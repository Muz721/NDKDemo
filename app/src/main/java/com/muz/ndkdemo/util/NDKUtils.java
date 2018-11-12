package com.muz.ndkdemo.util;

/**
 * Created by Administrator on 2018/11/8.
 */

public class NDKUtils {
    static {
        System.loadLibrary("native-lib");
    }

    public native int maxJNI();
    public native int addJNI(int a, int b);
    public native boolean isMaxJNI(int a, int b);
    public native boolean isMaxOtherJNI(int a, int b);
    public native int[] arrayJNI(int a, int b);
    public static native int[] arrayArrayJNI(int[] array);
    public static native int maxMainJNI();
    public static native String stringFromMainJNI();
    public static native int[] arrayOtherJNI(int a, int b);

    public static String javaStaticString(){
        return "这个是java的静态方法";
    }
    public String javaString(){
        return "这个是java的非静态方法";
    }
    public static native String spliceStaticJNI();
    public static native String spliceJNI();

    public static native String md5JNI(String encrypt);
    public static native int[] imageBrightnessJNI(int[] buffer,int width,int height);
}
