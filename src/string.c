/**
 * @file string.c
 * @author Zhang Hai
 */

#include "string.h"

#ifdef __gnu_linux__
#define __USE_GNU_STRCASESTR__
#endif

/* For toupper() and tolower() */
#include <ctype.h>
#ifdef __USE_GNU_STRCASESTR__
#define _GNU_SOURCE
#endif
#include <string.h>
#ifdef __USE_GNU_STRCASESTR__
#undef _GNU_SOURCE
#endif
#include <strings.h>
#include <stdarg.h>

#include "array.h"
#include "Memory.h"


string string_EMPTY = "";


string string_allocate(size_t length) {
    return Memory_allocate((length + 1) * sizeof(char));
}

string string_reallocate(string theString, size_t length) {
    return Memory_reallocate(theString, (length + 1) * sizeof(char));
}

void string_copy(string source, string destination) {
    strcpy(destination, source);
}

string string_clone(string theString) {
    string clone = string_allocate(string_length(theString));
    string_copy(theString, clone);
    return clone;
}

bool string_isEqual(string theString1, string theString2) {
    return string_compare(theString1, theString2) == 0;
}

int string_isEqualIgnoreCase(string theString1, string theString2) {
    return string_compareIgnoreCase(theString1, theString2) == 0;
}

int string_compare(string theString1, string theString2) {
    return strcmp(theString1, theString2);
}

int string_compareIgnoreCase(string theString1, string theString2) {
    return strcasecmp(theString1, theString2);
}

size_t string_indexOf(string theString, string subString) {
    string position = strstr(theString, subString);
    if (position == null) {
        return -1;
    } else {
        return position - theString;
    }
}

#ifndef __USE_GNU_STRCASESTR__
string strcasestr(string theString, string subString) {

    string stringUpper = string_clone(theString),
            subStringUpper = string_clone(subString),
            position;

    string_toUpperCase(stringUpper);
    string_toUpperCase(subStringUpper);

    position = strstr(stringUpper, subStringUpper);
    Memory_free(stringUpper);
    Memory_free(subStringUpper);

    return position;
}
#endif

size_t string_indexOfIgnoreCase(string theString, string subString) {
    string position = strcasestr(theString, subString);
    if (position == null) {
        return -1;
    } else {
        return position - theString;
    }
}

size_t string_lastIndexOf(string theString, string subString) {

    string stringReversed = string_clone(theString),
            subStringReversed = string_clone(subString),
            position;

    string_reverse(stringReversed);
    string_reverse(subStringReversed);

    position = strstr(stringReversed, subStringReversed);
    Memory_free(stringReversed);
    Memory_free(subStringReversed);

    if (position == null) {
        return -1;
    } else {
        return string_length(theString) - 1
                - (position - stringReversed);
    }
}

size_t string_lastIndexOfIgnoreCase(string theString,
        string subString) {

    string stringUpper = string_clone(theString),
            subStringUpper = string_clone(subString);
    size_t index;

    string_toUpperCase(stringUpper);
    string_toUpperCase(subStringUpper);

    index = string_lastIndexOf(stringUpper, subStringUpper);
    Memory_free(stringUpper);
    Memory_free(subStringUpper);

    return index;
}

bool string_contains(string theString, string subString) {
    return string_indexOf(theString, subString) != -1;
}

bool string_containsIgnoreCase(string theString, string subString) {
    return string_indexOfIgnoreCase(theString, subString) != -1;
}

bool string_startsWith(string theString, string prefix) {
    return string_indexOf(theString, prefix) == 0;
}

bool string_startsWithIgnoreCase(string theString, string prefix) {
    return string_indexOfIgnoreCase(theString, prefix) == 0;
}

bool string_endsWith(string theString, string suffix) {
    return string_lastIndexOf(theString, suffix) ==
            string_length(theString) - string_length(suffix);
}

bool string_endsWithIgnoreCase(string theString, string suffix) {
    return string_lastIndexOfIgnoreCase(theString, suffix) ==
            string_length(theString) - string_length(suffix);
}

size_t string_indexOfChar(string theString, char theChar) {
    string position = strchr(theString, theChar);
    if (position == null) {
        return -1;
    } else {
        return position - theString;
    }
}

size_t string_indexOfCharIgnoreCase(string theString, char theChar) {

    string stringUpper = string_clone(theString);
    size_t index;

    string_toUpperCase(stringUpper);
    theChar = toupper(theChar);

    index = string_indexOfChar(stringUpper, theChar);
    Memory_free(stringUpper);

    return index;
}

size_t string_lastIndexOfChar(string theString, char theChar) {
    string position = strrchr(theString, theChar);
    if (position == null) {
        return -1;
    } else {
        return position - theString;
    }
}

size_t string_lastIndexOfCharIgnoreCase(string theString,
        char theChar) {

    string stringUpper = string_clone(theString);
    size_t index;

    string_toUpperCase(stringUpper);
    theChar = toupper(theChar);

    index = string_lastIndexOfChar(stringUpper, theChar);
    Memory_free(stringUpper);

    return index;
}

bool string_containsChar(string theString, char theChar) {
    return string_indexOfChar(theString, theChar) != -1;
}

bool string_containsCharIgnoreCase(string theString, char theChar) {
    return string_indexOfCharIgnoreCase(theString, theChar) != -1;
}

size_t string_indexOfWithin(string theString, string chars) {
    string position = strpbrk(theString, chars);
    if (position == null) {
        return -1;
    } else {
        return position - theString;
    }
}

size_t string_indexOfOutside(string theString, string chars) {

    string start = theString,
            end = theString + string_length(theString);

    while (start != end && string_indexOfWithin(start, chars) == 0) {
        ++start;
    }

    if (start == end) {
        return -1;
    } else {
        return start - theString;
    }
}

size_t string_indexOfWithinIgnoreCase(string theString,
        string chars) {

    string stringUpper = string_clone(theString),
            charsUpper = string_clone(chars);
    size_t index;

    string_toUpperCase(stringUpper);
    string_toUpperCase(charsUpper);

    index = string_indexOfWithin(stringUpper, charsUpper);
    Memory_free(stringUpper);
    Memory_free(charsUpper);

    return index;
}

size_t string_indexOfOutsideIgnoreCase(string theString,
        string chars) {

    string stringUpper = string_clone(theString),
            charsUpper = string_clone(chars);
    size_t index;

    string_toUpperCase(stringUpper);
    string_toUpperCase(charsUpper);

    index = string_indexOfOutside(stringUpper, charsUpper);
    Memory_free(stringUpper);
    Memory_free(charsUpper);

    return index;
}

size_t string_length(string theString) {
    return strlen(theString);
}

bool string_isEmpty(string theString) {
    return string_length(theString) == 0;
}

void string_toUpperCase(string theString) {
    size_t i, size;
    size = string_length(theString);
    for (i = 0; i < size; ++i) {
        // No conversion will be done if not possible.
        theString[i] = toupper(theString[i]);
    }
}

void string_toLowerCase(string theString) {
    size_t i, size;
    size = string_length(theString);
    for (i = 0; i < size; ++i) {
        // No conversion will be done if not possible.
        theString[i] = tolower(theString[i]);
    }
}

void string_reverse(string theString) {
    char *start = theString,
            *end = start + string_length(theString) - 1,
            temp;
    while (start < end) {
        SWAP(*start, *end, temp);
        ++start;
        --end;
    }
}

/**
 * Append a string to an existing string.
 * @param theString The existing string.
 * @param extra The extra string to be appended.
 * @return The address of the string appended by extra, may differ
 *         from the original string.
 */
string string_append(string theString, string extra) {
    size_t oldLength = string_length(theString);
    theString = string_reallocate(theString,
            oldLength + string_length(extra));
    strcpy(theString + oldLength, extra);
    return theString;
}

/**
 * Concatenate a string with another string.
 * @param theString The first string.
 * @param extra The second string.
 * @return The new concatenated string.
 */
string string_concatenate(string first, string second) {
    size_t firstLength = string_length(first);
    string concatenated = string_allocate(
            firstLength + string_length(second));
    strcpy(concatenated + firstLength, second);
    return concatenated;
}

/**
 * Return the sub string of a string, with new memory allocated.
 * @param theString The original string.
 * @param start The inclusive start position, starting from 0.
 * @param end The exclusive end position.
 * @return The new sub string.
 */
string string_subString(string theString, size_t start, size_t end) {
    size_t length = end - start;
    string subString = string_allocate(length);
    strncpy(subString, theString + start, length);
    theString[length] = '\0';
    return subString;
}

#ifdef __USE_GNU_VASPRINTF__
string string_format(string format, ...) {
    string result = null;
    va_list arguments;
    va_start(arguments, format);
    vasprintf(&result, format, arguments);
    va_end(arguments);
    return result;
}
#else
string string_format(string format, ...) {
    size_t length;
    string result;
    va_list arguments;
    va_start(arguments, format);
    length = vsnprintf(null, 0, format, arguments);
    if (length < 0) {
        return null;
    }
    result = string_allocate(length);
    vsprintf(result, format, arguments);
    va_end(arguments);
    return result;
}
#endif

/**
 * Make a deep copy of a string array.
 * @param source The source string array.
 * @param destination The destination string array.
 * @param size Size of both string arrays.
 */
void string_array_clone(string src[], string dest[], size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        dest[i] = string_clone(src[i]);
    }
}

void string_array_copy(string source[], string destination[],
        size_t size) {
    array_copy(source, destination, size, sizeof(string));
}

void string_array_free(string array[], size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        Memory_free(array[i]);
    }
}

bool string_array_isEqual(string array1[], string array2[],
        size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        if (!string_isEqual(array1[i], array2[i])) {
            return false;
        }
    }
    return true;
}

bool string_array_isEqualIgnoreCase(string array1[],
        string array2[], size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        if (!string_isEqualIgnoreCase(array1[i], array2[i])) {
            return false;
        }
    }
    return true;
}

size_t string_array_containsEqual(string array[], size_t size,
        string theString) {
    size_t i;
    for (i = 0; i < size; ++i) {
        if (string_isEqual(array[i], theString)) {
            return i;
        }
    }
    return -1;
}

size_t string_array_containsEqualIgnoreCase(string array[],
        size_t size, string theString) {
    size_t i;
    for (i = 0; i < size; ++i) {
        if (string_isEqualIgnoreCase(array[i], theString)) {
            return i;
        }
    }
    return -1;
}

bool string_array_contains(string array[], size_t size,
        string subString) {
    size_t i;
    for (i = 0; i < size; ++i) {
        if (string_contains(array[i], subString)) {
            return true;
        }
    }
    return false;
}

bool string_array_containsIgnoreCase(string array[], size_t size,
        string subString) {
    size_t i;
    for (i = 0; i < size; ++i) {
        if (string_containsIgnoreCase(array[i], subString)) {
            return true;
        }
    }
    return false;
}

void string_array_print(string array[], size_t size,
        string splitter, FILE *file) {
    int i;
    for (i = 0; i < size; ++i) {
        if (i != 0) {
            fprintf(file, splitter);
        }
        fprintf(file, array[i]);
    }
}

void string_array_printSkipEmpty(string array[], size_t size,
        string splitter, FILE *file) {
    int i;
    for (i = 0; i < size; ++i) {
        if (string_isEmpty(array[i])) {
            continue;
        }
        if (i != 0) {
            fprintf(file, splitter);
        }
        fprintf(file, array[i]);
    }
}
