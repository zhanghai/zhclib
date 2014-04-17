/**
 * @file Object.c
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

#include "Object.h"

#include "string.h"
#include "Log.h"


void Object_initialize(Object *this, string name) {

    _(this, name) = string_clone(name);

    _$(this, new) = Object_new;
    _$(this, delete) = Object_delete;
    _$(this, toString) = Object_toString;

    Log_info("Object: Object created: %s@0x%p", name, this);
}

void Object_finalize(Object *this) {

    Log_info("Object: Object destroyed: %s@0x%p", _(this, name),
            this);

    Memory_free(_(this, name));
}

Object *Object_new() {
    OBJECT_NEW(Object, , "Object")
}

OBJECT_DEFINE_DELETE(Object)

string Object_toString(Object *this) {
    char address[sizeof(void *) / 2 + 4] = "@0x";
    sprintf(address + 3, "%p", this);
    return string_concatenate(_(this, name), address);
}
