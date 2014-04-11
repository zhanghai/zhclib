/**
 * @file PrimitiveWrappers.c
 * @author: Zhang Hai
 */

#include "PrimitiveWrappers.h"

/* For string_format() */
#include "string.h"


#define DEFINE_PRIMITIVE_WRAPPER(NAME, TYPE, FORMAT_STRING) \
\
    void NAME##_initializeMethods(NAME *this) { \
        _$(this, new) = NAME##_new; \
        _$(this, delete) = NAME##_delete; \
        _$(this, toString) = NAME##_toString; \
        _$(this, newFromValue) = NAME##_newFromValue; \
    } \
\
    void NAME##_initialize(NAME *this, string name) { \
\
        Object_initialize((Object *)this, name); \
\
        _(this, value) = 0; \
\
        NAME##_initializeMethods(this); \
    } \
\
    void NAME##_initializeFromValue(NAME *this, string name, \
            TYPE value) { \
\
        Object_initialize((Object *)this, name); \
\
        _(this, value) = value; \
\
        NAME##_initializeMethods(this); \
    } \
\
    void NAME##_finalize(NAME *this) { \
        Object_finalize((Object *)this); \
    } \
\
    NAME *NAME##_new() { \
        OBJECT_NEW(NAME, , #NAME) \
    } \
\
    OBJECT_DEFINE_DELETE(NAME) \
\
    string NAME##_toString(NAME *this) { \
        return string_format(FORMAT_STRING, _(this, value)); \
    } \
\
    NAME *NAME##_newFromValue(TYPE value) { \
        OBJECT_NEW(NAME, FromValue, #NAME, value) \
    } \


    DEFINE_PRIMITIVE_WRAPPER(Boolean, bool, "%d");

    DEFINE_PRIMITIVE_WRAPPER(Character, char, "%c");

    DEFINE_PRIMITIVE_WRAPPER(Integer, int, "%d");

    DEFINE_PRIMITIVE_WRAPPER(Long, long, "%ld");

    DEFINE_PRIMITIVE_WRAPPER(Float, float, "%f");

    DEFINE_PRIMITIVE_WRAPPER(Double, double, "%f");


#undef DEFINE_PRIMITIVE_WRAPPER
