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

/**
 * Copy the source string to the destination string.
 * @note The terminating null character of the source string will
 *       also be copied to the destination string.
 * @param source The source string.
 * @param destination The destination string.
 */
void string_copy(string source, string destination) {
    strcpy(destination, source);
}

/**
 * Copy the first length characters of the source string to
 * the destination string.
 * @note A null-character is guaranteed to be appended to the end of
 *       the destination string.
 * @param source The source string.
 * @param destination The destination string.
 * @param length The length to be copied.
 */
void string_copyWithLength(string source, string destination,
        size_t length) {
    strncpy(destination, source, length);
    destination[length] = '\0';
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

    string stringReversed = string_reverse(theString),
            subStringReversed = string_reverse(subString),
            position;

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

    string stringUpper = string_toUpperCase(theString),
            subStringUpper = string_toUpperCase(subString);
    size_t index;

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

    string stringUpper = string_toUpperCase(theString);
    size_t index;

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

    string stringUpper = string_toUpperCase(theString);
    size_t index;

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

size_t string_indexWithin(string theString, string chars) {
    string position = strpbrk(theString, chars);
    if (position == null) {
        return -1;
    } else {
        return position - theString;
    }
}

size_t string_indexOutside(string theString, string chars) {

    string start = theString,
            end = theString + string_length(theString);

    while (start != end && string_indexWithin(start, chars) == 0) {
        ++start;
    }

    if (start == end) {
        return -1;
    } else {
        return start - theString;
    }
}

size_t string_indexWithinIgnoreCase(string theString,
        string chars) {

    string stringUpper = string_toUpperCase(theString),
            charsUpper = string_toUpperCase(chars);
    size_t index;

    index = string_indexWithin(stringUpper, charsUpper);
    Memory_free(stringUpper);
    Memory_free(charsUpper);

    return index;
}

size_t string_indexOutsideIgnoreCase(string theString,
        string chars) {

    string stringUpper = string_toUpperCase(theString),
            charsUpper = string_toUpperCase(chars);
    size_t index;

    index = string_indexOutside(stringUpper, charsUpper);
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

string string_toUpperCase(string theString) {
    string upper = string_clone(theString);
    size_t i, length = string_length(upper);
    for (i = 0; i < length; ++i) {
        // No conversion will be done if not possible.
        upper[i] = toupper(upper[i]);
    }
    return upper;
}

string string_toLowerCase(string theString) {
    string lower = string_clone(theString);
    size_t i, length = string_length(lower);
    for (i = 0; i < length; ++i) {
        // No conversion will be done if not possible.
        lower[i] = tolower(lower[i]);
    }
    return lower;
}

/*
void string_reverse(string theString) {
    char *start = theString,
            *end = start + string_length(theString) - 1,
            temp;
    while (start < end) {
        temp = *start; \
        *start = *end; \
        *end = temp; \
        ++start;
        --end;
    }
}
*/

string string_reverse(string theString) {
    size_t i, length = string_length(theString);
    string reverse = string_allocate(length);
    for (i = 0; i < length; ++i) {
        // No conversion will be done if not possible.
        reverse[i] = theString[length - 1 - i];
    }
    reverse[length] = '\0';
    return reverse;
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
    string_copy(concatenated + firstLength, second);
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
    string_copyWithLength(theString + start, subString, length);
    return subString;
}

string string_trim(string theString) {
    string start = theString,
            end = theString + string_length(theString);
    while (start < end && *start == ' ') {
        ++start;
    }
    while (end > start && *(end - 1) == ' ') {
        --end;
    }
    return string_subString(theString, start - theString,
            end - theString);
}

string string_replaceFirstReturnsNull(string theString, string old,
        string new) {

    size_t index = string_indexOf(theString, old),
            length, oldLength, newLength;
    string result;

    if (index == -1) {
        return null;
    }

    length = string_length(theString);
    oldLength = string_length(old);
    newLength = string_length(new);
    result = string_allocate(length - oldLength + newLength);
    string_copyWithLength(theString, result, index);
    string_copy(new, result + index);
    string_copy(theString + index + oldLength,
            result + index + newLength);

    return result;
}

string string_replaceFirst(string theString, string old, string new) {
    string result = string_replaceFirstReturnsNull(theString, old,
            new);
    if (result == null) {
        result = string_clone(theString);
    }
    return result;
}

string string_replaceRecursiveReturnsNull(string theString,
        string old, string new) {

    string result, oldResult = theString;

    if ((oldResult = string_replaceFirstReturnsNull(theString, old,
            new)) == null) {
        return null;
    }

    while ((result = string_replaceFirstReturnsNull(oldResult, old,
            new)) != null) {
        Memory_free(oldResult);
        oldResult = result;
    }

    return oldResult;
}

string string_replaceRecursive(string theString, string old,
        string new) {
    string result = string_replaceRecursiveReturnsNull(theString, old,
            new);
    if (result == null) {
        result = string_clone(theString);
    }
    return result;
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

#define DEFINE_PARSE_PRIMITIVE(NAME, TYPE, FORMAT) \
    size_t string_parse##NAME(string theString, TYPE *value) { \
        size_t count; \
        if (sscanf(theString, #FORMAT"%zn", value, &count) == 1) { \
            return count; \
        } else { \
            return -1; \
        } \
    }

DEFINE_PARSE_PRIMITIVE(Int, int, %d)

DEFINE_PARSE_PRIMITIVE(Long, long, %ld)

DEFINE_PARSE_PRIMITIVE(Float, float, %f)

DEFINE_PARSE_PRIMITIVE(Double, double, %lf)

#undef DEFINE_PARSE_PRIMITIVE

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
