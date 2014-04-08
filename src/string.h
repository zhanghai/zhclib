/**
 * @file string.h
 * @author Zhang Hai
 */

#ifndef _STRING_H_
#define _STRING_H_


#include "primitives.h"

#include "stdio.h"


extern string string_EMPTY;


void string_copy(string source, string destination);

string string_clone(string theString);

bool string_isEqual(string theString1, string theString2);

bool string_isEqualIgnoreCase(string theString1, string theString2);

int string_compare(string theString1, string theString2);

int string_compareIgnoreCase(string theString1, string theString2);

bool string_contains(string theString, string subString);

bool string_containsIgnoreCase(string theString, string subString);

size_t string_length(string theString);

bool string_isEmpty(string theString);

void string_toUpperCase(string theString);

void string_toLowerCase(string theString);

string string_append(string theString, string extra);

string string_concatenate(string first, string second);

string string_subString(string theString, size_t start, size_t end);

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
