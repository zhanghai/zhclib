/**
 * @file Common.h
 * @author Zhang Hai
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
