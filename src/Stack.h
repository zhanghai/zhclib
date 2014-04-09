/**
 * @file Stack.h
 * @author: Zhang Hai
 */

#ifndef _STACK_H_
#define _STACK_H_


#include "Common.h"

#include "LinkedList.h"


typedef LinkedListNode StackNode;


typedef struct {
    string name;
    StackNode *head;
    StackNode *tail;
    size_t size;
} Stack_Fields;


typedef struct tagStack Stack;

typedef Stack *(*Stack_MethodNew)();
typedef void (*Stack_MethodDelete)(Stack *this);
typedef string (*Stack_MethodToString)(Stack *this);

typedef StackNode *(*Stack_MethodNewNode)(void *data,
        StackNode *previous,
        StackNode *next);
typedef void (*Stack_MethodDeleteNode)(
        StackNode *node);
typedef StackNode *(*Stack_MethodAddStart)(
        Stack *this, void *book);
typedef StackNode *(*Stack_MethodAddEnd)(Stack *this,
        void *book);
typedef StackNode *(*Stack_MethodInsertBefore)(
        Stack *this, StackNode *node, void *book);
typedef StackNode *(*Stack_MethodInsertAfter)(
        Stack *this, StackNode *node, void *book);
typedef StackNode *(*Stack_MethodRemoveNode)(
        Stack *this, StackNode *node);
typedef void (*Stack_MethodRemove)(Stack *this,
        void *book);
typedef void (*Stack_MethodSwap)(Stack *this,
        StackNode *node1, StackNode *node2);
typedef void (*Stack_MethodSort)(Stack *this,
        Comparator comparator);
typedef Stack *(*Stack_MethodSearch)(Stack *this,
        Filter filter);
typedef void *(*Stack_MethodPeek)(Stack *this);
typedef void *(*Stack_MethodPop)(Stack *this);
typedef void (*Stack_MethodPush)(Stack *this, void *data);


typedef struct {

    Stack_MethodNew new;
    Stack_MethodDelete delete;
    Stack_MethodToString toString;
    Stack_MethodNewNode newNode;
    Stack_MethodDeleteNode deleteNode;
    Stack_MethodAddStart addStart;
    Stack_MethodAddEnd addEnd;
    Stack_MethodInsertBefore insertBefore;
    Stack_MethodInsertAfter insertAfter;
    Stack_MethodRemoveNode removeNode;
    Stack_MethodRemove remove;
    Stack_MethodSwap swap;
    Stack_MethodSort sort;
    Stack_MethodSearch search;

    Stack_MethodPeek peek;
    Stack_MethodPop pop;
    Stack_MethodPush push;
} Stack_Methods;


typedef struct tagStack {
    Stack_Fields *fields;
    Stack_Methods *methods;
} Stack;


void Stack_initialize(Stack *this, string name);

void Stack_finalize(Stack *this);

Stack *Stack_new();

void Stack_delete(Stack *this);

void *Stack_peek(Stack *this);

void *Stack_pop(Stack *this);

void Stack_push(Stack *this, void *data);



#endif /* _STACK_H_ */
