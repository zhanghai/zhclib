/**
 * @file array.h
 * @author Zhang Hai
 */

#ifndef _ARRAY_H_
#define _ARRAY_H_


#include "primitives.h"


#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))


void array_copy(void *source, void *destination, size_t size,
        size_t elementSize);


#endif /* _ARRAY_H_ */
