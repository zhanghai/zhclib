/**
 * @file ArrayList.c
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
