/**
 * @file StringBuilder.c
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

#include "StringBuilder.h"

// For memset()
#include <string.h>


static size_t LENGTH_STEP = 16;


static void StringBuilder_initializeMethods(StringBuilder *this);

static size_t StringBuilder_roundLength(size_t length);

static void StringBuilder_allocate(StringBuilder *this,
        size_t length);

static void StringBuilder_reallocate(StringBuilder *this,
        size_t length);


static void StringBuilder_initializeMethods(StringBuilder *this) {
    _$(this, new) = StringBuilder_new;
    _$(this, delete) = StringBuilder_delete;
    _$(this, toString) = StringBuilder_toString;
    _$(this, newFromString) = StringBuilder_newFromString;
    _$(this, append) = StringBuilder_append;
}

static size_t StringBuilder_roundLength(size_t length) {
    // Ensures that rounded length is always greater than actual
    // length, along with memory initialized to 0 we can forget about
    // the terminating null.
    length += LENGTH_STEP - length % LENGTH_STEP;
    return length;
}

static void StringBuilder_allocate(StringBuilder *this,
        size_t length) {
    length = StringBuilder_roundLength(length);
    // Memory initialized to 0.
    _(this, buffer) = Memory_allocate(length * sizeof(char));
    _(this, allocatedLength) = length;
}

static void StringBuilder_reallocate(StringBuilder *this,
        size_t length) {
    length = StringBuilder_roundLength(length);
    if (length <= _(this, allocatedLength)) {
        return;
    }
    _(this, buffer) = Memory_reallocate(_(this, buffer),
            length * sizeof(char));
    // Initialize new memory to 0;
    memset(_(this, buffer), 0, length - _(this, allocatedLength));
    _(this, allocatedLength) = length;
}

void StringBuilder_initialize(StringBuilder *this, string name) {

    Object_initialize((Object *)this, name);

    StringBuilder_allocate(this, LENGTH_STEP);
    _(this, length) = 0;

    StringBuilder_initializeMethods(this);
}

void StringBuilder_initializeFromstring(StringBuilder *this,
        string name, string theString) {

    Object_initialize((Object *)this, name);

    _(this, length) = string_length(theString);
    StringBuilder_allocate(this, _(this, length));
    string_copy(theString, _(this, buffer));

    StringBuilder_initializeMethods(this);
}

void StringBuilder_finalize(StringBuilder *this) {

    Memory_free(_(this, buffer));

    Object_finalize((Object *)this);
}

StringBuilder *StringBuilder_new() {
    OBJECT_NEW(StringBuilder, , "StringBuilder")
}

string StringBuilder_toString(StringBuilder *this) {
    return string_clone(_(this, buffer));
}

StringBuilder *StringBuilder_newFromString(string theString) {
    OBJECT_NEW(StringBuilder, Fromstring, "StringBuilder", theString)
}

OBJECT_DEFINE_DELETE(StringBuilder)

StringBuilder *StringBuilder_append(StringBuilder *this,
        string theString) {
    size_t extraLength = string_length(theString);
    StringBuilder_reallocate(this, _(this, length) + extraLength);
    string_copy(theString, _(this, buffer) + _(this, length));
    return this;
}
