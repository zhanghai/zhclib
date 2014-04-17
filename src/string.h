/**
 * @file string.h
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

#ifndef _STRING_H_
#define _STRING_H_

#ifdef __gnu_linux__
#define __USE_GNU_VASPRINTF__
#endif

#include "primitives.h"

#ifdef __USE_GNU_VASPRINTF__
#define _GNU_SOURCE
#endif
#include "stdio.h"
#ifdef __USE_GNU_VASPRINTF__
#undef _GNU_SOURCE
#endif


extern string string_EMPTY;


string string_allocate(size_t length);

string string_reallocate(string theString, size_t length);

string string_subsititute(string *theString, string new);

string string_subsitituteIfNotNull(string *theString, string new);

void string_copy(string source, string destination);

void string_copyWithLength(string source, string destination,
        size_t length);

string string_clone(string theString);

bool string_isEqual(string theString1, string theString2);

bool string_isEqualIgnoreCase(string theString1, string theString2);

int string_compare(string theString1, string theString2);

int string_compareIgnoreCase(string theString1, string theString2);

size_t string_indexOf(string theString, string subString);

size_t string_indexOfIgnoreCase(string theString, string subString);

size_t string_indexOfStartingFrom(string theString, size_t start,
        string subString);

size_t string_indexOfStartingFromIgnoreCase(string theString,
        size_t start, string subString);

size_t string_lastIndexOf(string theString, string subString);

size_t string_lastIndexOfIgnoreCase(string theString,
        string subString);

size_t string_lastIndexOfEndingTo(string theString, size_t end,
        string subString);

size_t string_lastIndexOfEndingToIgnoreCase(string theString,
        size_t end, string subString);

bool string_contains(string theString, string subString);

bool string_containsIgnoreCase(string theString, string subString);

bool string_startsWith(string theString, string prefix);

bool string_startsWithIgnoreCase(string theString, string prefix);

bool string_endsWith(string theString, string suffix);

bool string_endsWithIgnoreCase(string theString, string suffix);

size_t string_indexOfChar(string theString, char theChar);

size_t string_indexOfCharIgnoreCase(string theString, char theChar);

size_t string_indexOfCharStartingFrom(string theString, size_t start,
        char theChar);

size_t string_indexOfCharStartingFromIgnoreCase(string theString,
        size_t start, char theChar);

size_t string_lastIndexOfChar(string theString, char theChar);

size_t string_lastIndexOfCharIgnoreCase(string theString,
        char theChar);

size_t string_lastIndexOfCharEndingTo(string theString, size_t end,
        char theChar);

size_t string_lastIndexOfCharEndingToIgnoreCase(string theString,
        size_t end, char theChar);

bool string_containsChar(string theString, char theChar);

bool string_containsCharIgnoreCase(string theString, char theChar);

/*
 * TODO
 *

size_t string_indexWithin(string theString, string strings[]);

size_t string_indexOutside(string theString, string strings[]);

size_t string_indexWithinIgnoreCase(string theString,
        string strings[]);

size_t string_indexOutsideIgnoreCase(string theString,
        string strings[]);
*/

size_t string_indexWithinChars(string theString, string chars);

size_t string_indexOutsideChars(string theString, string chars);

size_t string_indexWithinCharsIgnoreCase(string theString,
        string chars);

size_t string_indexOutsideCharsIgnoreCase(string theString,
        string chars);

size_t string_length(string theString);

bool string_isEmpty(string theString);

string string_toUpperCase(string theString);

string string_toLowerCase(string theString);

string string_reverse(string theString);

string string_append(string theString, string extra);

string string_concatenate(string first, string second);

string string_subString(string theString, size_t start, size_t end);

string string_trim(string theString);

string string_replaceFirstReturnsNull(string theString, string old,
        string new);

string string_replaceFirst(string theString, string old, string new);

string string_replaceFirstStartingFromReturnsNull(string theString,
        size_t start, string old, string new);

string string_replaceFirstStartingFrom(string theString, size_t start,
        string old, string new);

string string_replaceAllReturnsNull(string theString, string old,
        string new);

string string_replaceAll(string theString, string old, string new);

string string_replaceRecursiveReturnsNull(string theString,
        string old, string new);

string string_replaceRecursive(string theString, string old,
        string new);

string string_format(string format, ...);

#define DECLARE_PARSE_PRIMITIVE(NAME, TYPE) \
    size_t string_parse##NAME(string theString, TYPE *value);

DECLARE_PARSE_PRIMITIVE(Int, int)

DECLARE_PARSE_PRIMITIVE(Long, long)

DECLARE_PARSE_PRIMITIVE(Float, float)

DECLARE_PARSE_PRIMITIVE(Double, double)

#undef DECLARE_PARSE_PRIMITIVE

void string_array_clone(string source[], string destination[],
        size_t size);

void string_array_copy(string source[], string destination[],
        size_t size);

void string_array_free(string array[], size_t size);

bool string_array_isEqual(string array1[], string array2[],
        size_t size);

bool string_array_isEqualIgnoreCase(string array1[],
        string array2[], size_t size);

size_t string_array_containsEqual(string array[], size_t size,
        string theString);

size_t string_array_containsEqualIgnoreCase(string array[],
        size_t size, string theString);

bool string_array_contains(string array[], size_t size,
        string subString);

bool string_array_containsIgnoreCase(string array[], size_t size,
        string subString);

void string_array_print(string array[], size_t size,
        string splitter, FILE *file);

void string_array_printSkipEmpty(string array[], size_t size,
        string splitter, FILE *file);

#endif /* _STRING_H_ */
