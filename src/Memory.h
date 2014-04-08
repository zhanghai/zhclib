/**
 * @file Memory.h
 * @author Zhang Hai
 */

#ifndef _MEMORY_H_
#define _MEMORY_H_


#include "primitives.h"


void *Memory_allocate(size_t size);

#define Memory_allocateType(type) Memory_allocate(sizeof(type))

void *Memory_reallocate(void *address, size_t size);

void Memory_free(void *address);


#endif /* _MEMORY_H_ */
