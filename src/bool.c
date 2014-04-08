/**
 * @file bool.c
 * @author Zhang Hai
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
