#include <jni.h>
#include <string>
#include "counter.hpp"

counter* getCounterInstance(JNIEnv* env, jobject thisj) {
    static jclass classj = env->GetObjectClass(thisj);
    static jfieldID fieldId = env->GetFieldID(classj, "pointer", "J");
    long pointer = env->GetLongField(thisj, fieldId);
    if (!pointer) {
        pointer = (jlong)(new counter());
        env->SetLongField(thisj, fieldId, (jlong)pointer);
    }
    return (counter*)pointer;
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_cppclasstest_Counter_getCountCpp(JNIEnv* env, jobject thisj) {
    return getCounterInstance(env, thisj)->count;
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_cppclasstest_Counter_setCountCpp(JNIEnv* env, jobject thisj, jint value) {
    getCounterInstance(env, thisj)->count = value;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cppclasstest_Counter_description(JNIEnv* env, jobject thisj) {
    string res = getCounterInstance(env, thisj)->description();
    return env->NewStringUTF(res.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_cppclasstest_Counter_increment(JNIEnv* env, jobject thisj) {
    getCounterInstance(env, thisj)->increment();
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_cppclasstest_Counter_delete(JNIEnv* env, jobject thisj) {
    jclass classj = env->GetObjectClass(thisj);
    jfieldID fieldId = env->GetFieldID(classj, "pointer", "J");
    long pointer = env->GetLongField(thisj, fieldId);
    if (!pointer) return;
    delete (counter*)pointer;
    env->SetLongField(thisj, fieldId, (jlong)0);
}