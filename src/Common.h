/**
 * @file Common.h
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

#ifndef _COMMON_H_
#define _COMMON_H_


#include <stdio.h>
#include <stdlib.h>

#include "primitives.h"
#include "bool.h"
#include "array.h"
#include "string.h"
#include "serialize.h"
#include "Application.h"
#include "Memory.h"
#include "Time.h"
#include "Log.h"
#include "Object.h"
#include "PrimitiveWrappers.h"


#define MAX(var1, var2) ((var1) > (var2) ? (var1) : (var2))

#define MIN(var1, var2) ((var1) < (var2) ? (var1) : (var2))

#define SWAP(var1, var2, tmp) \
    do { \
        tmp = var1; \
        var1 = var2; \
        var2 = tmp; \
    } while (false)


typedef int (*Comparator)(void *data1, void *data2);

typedef bool (*FilterFunction)(void *book, void *filterData);

typedef struct {
    FilterFunction filter;
    void *filterData;
} Filter;


#endif /* _COMMON_H_ */
