/**
 * @file StringBuilder.h
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

#ifndef _STRING_BUILDER_H_
#define _STRING_BUILDER_H_


#include "Common.h"


typedef struct {

    string name;

    string buffer;
    size_t length;
    size_t allocatedLength;
} StringBuilder_Fields;


typedef struct tagStringBuilder StringBuilder;

typedef StringBuilder *(*StringBuilder_MethodNew)();
typedef void (*StringBuilder_MethodDelete)(StringBuilder *this);
typedef string (*StringBuilder_MethodToString)(StringBuilder *this);

typedef StringBuilder *(*StringBuilder_MethodNewFromString)
        (string theString);
typedef StringBuilder *(*StringBuilder_MethodAppend)
        (StringBuilder *this, string theString);

typedef struct {

    StringBuilder_MethodNew new;
    StringBuilder_MethodDelete delete;
    StringBuilder_MethodToString toString;

    StringBuilder_MethodNewFromString newFromString;
    StringBuilder_MethodAppend append;
} StringBuilder_Methods;


typedef struct tagStringBuilder {
    StringBuilder_Fields *fields;
    StringBuilder_Methods *methods;
} StringBuilder;


void StringBuilder_initialize(StringBuilder *this, string name);

void StringBuilder_initializeFromString(StringBuilder *this,
        string name, string theString);

void StringBuilder_finalize(StringBuilder *this);

StringBuilder *StringBuilder_new();

void StringBuilder_delete(StringBuilder *this);

string StringBuilder_toString(StringBuilder *this);

StringBuilder *StringBuilder_newFromString(string theString);

StringBuilder *StringBuilder_append(StringBuilder *this,
        string theString);


#endif /* _STRING_H_ */
