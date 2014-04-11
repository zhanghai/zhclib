/**
 * @file PrimitiveWrappers.h
 * @author: Zhang Hai
 */

#ifndef _PRIMITIVE_WRAPPERS_H_
#define _PRIMITIVE_WRAPPERS_H_


#include "primitives.h"

#include "Object.h"


#define DECLARE_PRIMITIVE_WRAPPER(NAME, TYPE) \
\
    typedef struct { \
\
        string name; \
\
        TYPE value; \
    } NAME##_Fields; \
\
\
    typedef struct tag##NAME NAME; \
\
    typedef NAME *(*NAME##_MethodNew)(); \
    typedef void (*NAME##_MehotdDelete)(NAME *this); \
    typedef string (*NAME##_MethodToString)(NAME *this); \
\
    typedef NAME *(*NAME##_MethodNewFromValue)(TYPE value); \
\
    typedef struct { \
\
        NAME##_MethodNew new; \
        NAME##_MehotdDelete delete; \
        NAME##_MethodToString toString; \
\
        NAME##_MethodNewFromValue newFromValue; \
    } NAME##_Methods; \
\
\
    typedef struct tag##NAME { \
        NAME##_Fields *fields; \
        NAME##_Methods *methods; \
    } NAME; \
\
\
    void NAME##_initialize(NAME *this, string name); \
\
    void NAME##_finalize(NAME *this); \
\
    NAME *NAME##_new(); \
\
    void NAME##_delete(NAME *this); \
\
    string NAME##_toString(NAME *this); \
\
    NAME *NAME##_newFromValue(TYPE value); \


DECLARE_PRIMITIVE_WRAPPER(Boolean, bool);

DECLARE_PRIMITIVE_WRAPPER(Character, char);

DECLARE_PRIMITIVE_WRAPPER(Integer, int);

DECLARE_PRIMITIVE_WRAPPER(Long, long);

DECLARE_PRIMITIVE_WRAPPER(Float, float);

DECLARE_PRIMITIVE_WRAPPER(Double, double);


#undef DECLARE_PRIMITIVE_WRAPPER


#endif /* _PRIMITIVE_WRAPPERS_H_ */
