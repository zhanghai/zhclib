/**
 * @file ArrayList.c
 * @author Zhang Hai
 */

#include "ArrayList.h"


static const size_t INITIAL_ALLOCATION_SIZE = 8;


ArrayList *ArrayList_new() {

    ArrayList *list = Memory_allocateType(ArrayList);

    list->array = Memory_allocate(INITIAL_ALLOCATION_SIZE * sizeof(void *));
    list->size = 0;
    list->allocatedSize = INITIAL_ALLOCATION_SIZE;

    return list;
}

void ArrayList_delete(ArrayList *list) {

    Memory_free(list->array);

    Memory_free(list);
}

void *ArrayList_getAt(ArrayList *list, size_t index) {

    if (index >= list->size) {
        return null;
    }

    return list->array[index];
}

void ArrayList_addEnd(ArrayList *list, void *data) {

    if (list->size == list->allocatedSize) {
        list->array = Memory_reallocate(list->array,
                2 * list->allocatedSize * sizeof(void *));
        list->allocatedSize *= 2;
    }

    list->array[list->size] = data;
    ++list->size;
}
