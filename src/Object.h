/**
 * @file Object.h
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

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "primitives.h"
#include "Memory.h"


/* Access a field */
#define _(object, field) ((object)->fields->field)

/* Access a method */
#define _$(object, method) ((object)->methods->method)

/* Call a method */
#define $(object, method, ...) (_$(object, method)(object, ##__VA_ARGS__))

/* Call a static method */
#define $_(object, method, ...) (_$(object, method)(__VA_ARGS__))

#define OBJECT_NEW(OBJECT_TYPE, INITIALIZER_POSTFIX, ...) \
        OBJECT_TYPE *this; \
        this = Memory_allocateType(Object); \
        this->fields = Memory_allocateType(OBJECT_TYPE##_Fields); \
        this->methods = Memory_allocateType(OBJECT_TYPE##_Methods); \
        OBJECT_TYPE##_initialize##INITIALIZER_POSTFIX(this, ##__VA_ARGS__); \
        return this;

#define OBJECT_DEFINE_DELETE(OBJECT_TYPE) \
    void OBJECT_TYPE##_delete(OBJECT_TYPE *this) { \
        OBJECT_TYPE##_finalize(this); \
        Memory_free(this->methods); \
        Memory_free(this->fields); \
        Memory_free(this); \
    }


typedef struct {
    string name;
} Object_Fields;


typedef struct tagObject Object;

typedef Object *(*Object_MethodNew)();
typedef void (*Object_MehotdDelete)(Object *this);
typedef string (*Object_MethodToString)(Object *this);

typedef struct {
    Object_MethodNew new;
    Object_MehotdDelete delete;
    Object_MethodToString toString;
} Object_Methods;


typedef struct tagObject {
    Object_Fields *fields;
    Object_Methods *methods;
} Object;


void Object_initialize(Object *this, string name);

void Object_finalize(Object *this);

Object *Object_new();

void Object_delete(Object *this);

string Object_toString(Object *this);


#endif /* _OBJECT_H_ */
