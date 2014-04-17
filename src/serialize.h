/**
 * @file serialize.h
 * @author Zhang Hai
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

#ifndef _SERIALIZE_H_
#define _SERIALIZE_H_


#include <stdio.h>

#include "primitives.h"


#define LMS_DECLARE_SERIALIZE_FUNCTION(type) \
    bool type##_serialize(type *value, FILE *file);

#define LMS_DECLARE_DESERIALIZE_FUNCTION(type) \
    bool type##_deserialize(type *valueString, FILE *file);


LMS_DECLARE_SERIALIZE_FUNCTION(size_t)

LMS_DECLARE_DESERIALIZE_FUNCTION(size_t)

LMS_DECLARE_SERIALIZE_FUNCTION(bool)

LMS_DECLARE_DESERIALIZE_FUNCTION(bool)

bool cstring_serialize(string cString, FILE *file);

bool cstring_deserialize(string *cString, FILE *file);

bool cstring_array_serialize(string array[], size_t size, FILE *file);

bool cstring_array_deserialize(string array[], size_t size,
        FILE *file);


#undef LMS_DECLARE_SERIALIZE_FUNCTION
#undef LMS_DECLARE_DESERIALIZE_FUNCTION


#endif /* _SERIALIZE_H_ */
