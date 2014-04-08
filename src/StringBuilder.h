/*
 * @file StringBuilder.h
 * @author: Zhang Hai
 */

#ifndef _STRING_BUILDER_H_
#define _STRING_BUILDER_H_


#include "Common.h"


typedef struct {

    string name;

    string buffer;
    size_t length;
    size_t allocatedLength;
} StringBuilder_Fields;


typedef struct tagStringBuilder StringBuilder;

typedef StringBuilder *(*StringBuilder_MethodNew)();
typedef void (*StringBuilder_MethodDelete)(StringBuilder *this);
typedef string (*StringBuilder_MethodToString)(StringBuilder *this);

typedef StringBuilder *(*StringBuilder_MethodNewFromString)
        (string theString);
typedef StringBuilder *(*StringBuilder_MethodAppend)
        (StringBuilder *this, string theString);

typedef struct {

    StringBuilder_MethodNew new;
    StringBuilder_MethodDelete delete;
    StringBuilder_MethodToString toString;

    StringBuilder_MethodNewFromString newFromString;
    StringBuilder_MethodAppend append;
} StringBuilder_Methods;


typedef struct tagStringBuilder {
    StringBuilder_Fields *fields;
    StringBuilder_Methods *methods;
} StringBuilder;


void StringBuilder_initialize(StringBuilder *this, string name);

void StringBuilder_initializeFromString(StringBuilder *this,
        string name, string theString);

void StringBuilder_finalize(StringBuilder *this);

StringBuilder *StringBuilder_new();

void StringBuilder_delete(StringBuilder *this);

string StringBuilder_toString(StringBuilder *this);

StringBuilder *StringBuilder_newFromString(string theString);

StringBuilder *StringBuilder_append(StringBuilder *this,
        string theString);


#endif /* _STRING_H_ */
