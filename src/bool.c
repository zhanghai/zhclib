/**
 * @file bool.c
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

#include "bool.h"
#include "string.h"


static const string BOOL_FALSE_STRING = "False";
static const string BOOL_TRUE_STRING = "True";


bool bool_is_equal(bool boolean, string theString) {
    return boolean ?
            string_isEqualIgnoreCase(BOOL_TRUE_STRING, theString)
            : string_isEqualIgnoreCase(BOOL_FALSE_STRING, theString);
}

void bool_print(bool boolean, FILE *file) {
    fprintf(file, boolean ? BOOL_TRUE_STRING : BOOL_FALSE_STRING);
}
