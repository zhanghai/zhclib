/**
 * @file ArrayList.h
 * @author Zhang Hai
 */

#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_


#include "Common.h"


#define ARRAY_LIST_FOR_EACH(list, data) \
    for (data = *list->array; (void *) data < *list->array + list->size * sizeof(void *); data += sizeof(void *))


typedef struct {
    void **array;
    size_t size;
    size_t allocatedSize;
} ArrayList;


ArrayList *ArrayList_new();

void ArrayList_delete(ArrayList *list);

void *ArrayList_getAt(ArrayList *list, size_t index);

void ArrayList_addEnd(ArrayList *list, void *data);


#endif /* _ARRAY_LIST_H_ */
