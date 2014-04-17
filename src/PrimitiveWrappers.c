/**
 * @file PrimitiveWrappers.c
 * @author: Zhang Hai
 */

/*
 * Copyright (C) 2014 Zhang Hai
 *
 * This file is part of zhclib.
 *
 * zhclib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * zhclib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with zhclib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "PrimitiveWrappers.h"

/* For string_format() */
#include "string.h"


#define DEFINE_PRIMITIVE_WRAPPER(NAME, TYPE, FORMAT) \
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
        return string_format(FORMAT, _(this, value)); \
    } \
\
    NAME *NAME##_newFromValue(TYPE value) { \
        OBJECT_NEW(NAME, FromValue, #NAME, value) \
    } \


    DEFINE_PRIMITIVE_WRAPPER(Boolean, bool, "%d")

    DEFINE_PRIMITIVE_WRAPPER(Character, char, "%c")

    DEFINE_PRIMITIVE_WRAPPER(Integer, int, "%d")

    DEFINE_PRIMITIVE_WRAPPER(Long, long, "%ld")

    DEFINE_PRIMITIVE_WRAPPER(Float, float, "%f")

    DEFINE_PRIMITIVE_WRAPPER(Double, double, "%f")


#undef DEFINE_PRIMITIVE_WRAPPER
