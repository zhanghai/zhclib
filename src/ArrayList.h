/**
 * @file ArrayList.h
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
