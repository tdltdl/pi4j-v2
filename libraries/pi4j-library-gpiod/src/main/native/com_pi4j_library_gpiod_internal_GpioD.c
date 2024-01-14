
#include <gpiod.h>
#include "com_pi4j_library_gpiod_internal_GpioD.h"

// Compile using:
// gcc -I /usr/lib/jvm/java-11-openjdk-amd64/include/ -I /usr/lib/jvm/java-11-openjdk-amd64/include/linux/ -lgpiod -I . -c com_pi4j_library_gpiod_internal_GpioD.c

JNIEXPORT jobject JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1open
  (JNIEnv* env, jclass javaClass, jstring path) {
    struct gpiod_chip* chip;
    const char* nativeString = (*env)->GetStringUTFChars(env, path, NULL);
    chip = gpiod_chip_open(nativeString);
    (*env)->ReleaseStringUTFChars(env, path, nativeString);

    if(chip == NULL) {
      return NULL;
    }
    jclass cls = (*env)->FindClass(env, "java/lang/Long");
    jmethodID longConstructor = (*env)->GetMethodID(env, cls, "<init>", "(J)V");
    return (*env)->NewObject(env, cls, longConstructor, (jlong) chip);
}

JNIEXPORT void JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1close
  (JNIEnv* env, jclass javaClass, jlong chipPtr) {
    gpiod_chip_close((struct gpiod_chip*) chipPtr);
  }

JNIEXPORT jstring JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1name
  (JNIEnv* env, jclass javaClass, jlong chipPtr) {
    const char* name = gpiod_chip_name((struct gpiod_chip*) chipPtr);
    jstring jStrName = (*env)->NewStringUTF(env, name);
    return jStrName;
  }

JNIEXPORT jstring JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1label
  (JNIEnv* env, jclass javaClass, jlong chipPtr) {
    const char* label = gpiod_chip_label((struct gpiod_chip*) chipPtr);
    jstring jStrName = (*env)->NewStringUTF(env, label);
    return jStrName;
}

JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1num_1lines
  (JNIEnv* env, jclass javaClass, jlong chipPtr) {
    unsigned int num_lines = gpiod_chip_num_lines((struct gpiod_chip*) chipPtr);
    return num_lines;
}

JNIEXPORT jobject JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1get_1line
  (JNIEnv* env, jclass javaClass, jlong chipPtr, jint offset) {
    struct gpiod_line* line;
    line = gpiod_chip_get_line((struct gpiod_chip*) chipPtr, offset);
    if(line == NULL) {
      return NULL;
    }
    jclass cls = (*env)->FindClass(env,"java/lang/Long");
    jmethodID longConstructor = (*env)->GetMethodID(env, cls, "<init>","(J)V");
    return (*env)->NewObject(env, cls, longConstructor, (jlong) line);
}

JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1get_1lines
  (JNIEnv* env, jclass javaClass, jlong chipPtr, jintArray offsets, jint num_offsets, jlong lineBulkPtr) {
    jint* c_offsets = (*env)->GetIntArrayElements(env, offsets, 0);


    int returnVal = gpiod_chip_get_lines((struct gpiod_chip*) chipPtr, c_offsets, num_offsets, (struct gpiod_line_bulk*) lineBulkPtr);
    (*env)->ReleaseIntArrayElements(env, offsets, c_offsets, 0);
    return returnVal;
}

JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1get_1all_1lines
  (JNIEnv* env, jclass javaClass, jlong chipPtr, jlong lineBulkPtr) {
    return gpiod_chip_get_all_lines((struct gpiod_chip*) chipPtr, (struct gpiod_line_bulk*) lineBulkPtr);
}

JNIEXPORT jobject JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1chip_1find_1line
  (JNIEnv* env, jclass javaClass, jlong chipPtr, jstring name) {
  const char* c_name = (*env)->GetStringUTFChars(env, name, NULL);
  struct gpiod_line* line = gpiod_chip_find_line((struct gpiod_chip*) chipPtr, c_name);
  (*env)->ReleaseStringUTFChars(env, name, c_name);

  if(line == NULL) {
    return NULL;
  }
  jclass cls = (*env)->FindClass(env, "java/lang/Long");
  jmethodID longConstructor = (*env)->GetMethodID(env, cls, "<init>","(J)V");
  return (*env)->NewObject(env, cls, longConstructor, (jlong) line);
}

JNIEXPORT jobject JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1bulk_1free
  (JNIEnv* env, jclass javaClass, jlong bulkPtr) {
    free((struct gpiod_line_bulk*) bulkPtr);
}

JNIEXPORT void JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_gpiod_1line_1bulk_1init
  (JNIEnv* env, jclass javaClass, jlong bulkPtr) {
    gpiod_line_bulk_init((struct gpiod_line_bulk*) bulkPtr);
}

JNIEXPORT jobject JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1bulk_1new
  (JNIEnv* env, jclass javaClass) {
    struct gpiod_line_bulk* bulkPtr = (struct gpiod_line_bulk*) malloc(sizeof(struct gpiod_line_bulk));
    jclass cls = (*env)->FindClass(env, "java/lang/Long");
    jmethodID longConstructor = (*env)->GetMethodID(env, cls, "<init>","(J)V");
    return (*env)->NewObject(env, cls, longConstructor, (jlong) bulkPtr);
}

JNIEXPORT void JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1bulk_1add
  (JNIEnv* env, jclass javaClass, jlong lineBulkPtr, jlong linePtr) {
    gpiod_line_bulk_add((struct gpiod_line_bulk*) lineBulkPtr, (struct gpiod_line*) linePtr);
}

JNIEXPORT jlong JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1bulk_1get_1line
  (JNIEnv* env, jclass javaClass, jlong lineBulkPtr, jint offset) {
    return (jlong) gpiod_line_bulk_get_line((struct gpiod_line_bulk*) lineBulkPtr, offset);
}

JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1bulk_1num_1lines
  (JNIEnv* env, jclass javaClass, jlong lineBulkPtr) {
    return gpiod_line_bulk_num_lines((struct gpiod_line_bulk*) lineBulkPtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_offset
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1offset
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_offset((struct gpiod_line*) linePtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_name
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1name
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    const char* c_name = gpiod_line_name((struct gpiod_line*) linePtr);
    return (*env)->NewStringUTF(env, c_name);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    gpiod_line_consumer
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_gpiod_1line_1consumer
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    const char* c_name = gpiod_line_consumer((struct gpiod_line*) linePtr);
    return (*env)->NewStringUTF(env, c_name);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_direction
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1direction
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_direction((struct gpiod_line*) linePtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_active_state
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1active_1state
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_active_state((struct gpiod_line*) linePtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_bias
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1bias
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_bias((struct gpiod_line*) linePtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_is_used
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1is_1used
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_is_used((struct gpiod_line*) linePtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_is_open_drain
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1is_1open_1drain
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_is_open_drain((struct gpiod_line*) linePtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_is_open_source
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1is_1open_1source
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_is_open_source((struct gpiod_line*) linePtr);
}

/*
 * Class:     com_pi4j_library_gpiod_internal_GpioD
 * Method:    c_gpiod_line_update
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_pi4j_library_gpiod_internal_GpioD_c_1gpiod_1line_1update
  (JNIEnv* env, jclass javaClass, jlong linePtr) {
    return gpiod_line_update((struct gpiod_line*) linePtr);
}