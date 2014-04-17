/**
 * @file array.h
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

#ifndef _ARRAY_H_
#define _ARRAY_H_


#include "primitives.h"


#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))


void array_copy(void *source, void *destination, size_t size,
        size_t elementSize);


#endif /* _ARRAY_H_ */
