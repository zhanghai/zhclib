/**
 * @file LinkedStack.h
 * @author: Zhang Hai
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

#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_


#include "Common.h"

#include "LinkedList.h"


typedef LinkedListNode LinkedStackNode;


typedef struct {
    string name;
    LinkedStackNode *head;
    LinkedStackNode *tail;
    size_t size;
} LinkedStack_Fields;


typedef struct tagLinkedStack LinkedStack;

typedef LinkedStack *(*LinkedStack_MethodNew)();
typedef void (*LinkedStack_MethodDelete)(LinkedStack *this);
typedef string (*LinkedStack_MethodToString)(LinkedStack *this);
typedef LinkedStackNode *(*LinkedStack_MethodNewNode)(void *data,
        LinkedStackNode *previous,
        LinkedStackNode *next);
typedef void (*LinkedStack_MethodDeleteNode)(
        LinkedStackNode *node);
typedef LinkedStackNode *(*LinkedStack_MethodAddStart)(
        LinkedStack *this, void *data);
typedef LinkedStackNode *(*LinkedStack_MethodAddEnd)(
        LinkedStack *this, void *data);
typedef LinkedStackNode *(*LinkedStack_MethodInsertBefore)(
        LinkedStack *this, LinkedStackNode *node, void *data);
typedef LinkedStackNode *(*LinkedStack_MethodInsertAfter)(
        LinkedStack *this, LinkedStackNode *node, void *data);
typedef LinkedStackNode *(*LinkedStack_MethodRemoveNode)(
        LinkedStack *this, LinkedStackNode *node);
typedef void (*LinkedStack_MethodRemove)(LinkedStack *this,
        void *data);
typedef void (*LinkedStack_MethodSwap)(LinkedStack *this,
        LinkedStackNode *node1, LinkedStackNode *node2);
typedef void (*LinkedStack_MethodSort)(LinkedStack *this,
        Comparator comparator);
typedef LinkedStack *(*LinkedStack_MethodSearch)(LinkedStack *this,
        Filter filter);

typedef void (*LinkedStack_MethodPush)(LinkedStack *this, void *data);
typedef void *(*LinkedStack_MethodPop)(LinkedStack *this);
typedef void *(*LinkedStack_MethodPeek)(LinkedStack *this);


typedef struct {

    LinkedStack_MethodNew new;
    LinkedStack_MethodDelete delete;
    LinkedStack_MethodToString toString;
    LinkedStack_MethodNewNode newNode;
    LinkedStack_MethodDeleteNode deleteNode;
    LinkedStack_MethodAddStart addStart;
    LinkedStack_MethodAddEnd addEnd;
    LinkedStack_MethodInsertBefore insertBefore;
    LinkedStack_MethodInsertAfter insertAfter;
    LinkedStack_MethodRemoveNode removeNode;
    LinkedStack_MethodRemove remove;
    LinkedStack_MethodSwap swap;
    LinkedStack_MethodSort sort;
    LinkedStack_MethodSearch search;

    LinkedStack_MethodPush push;
    LinkedStack_MethodPop pop;
    LinkedStack_MethodPeek peek;
} LinkedStack_Methods;


typedef struct tagLinkedStack {
    LinkedStack_Fields *fields;
    LinkedStack_Methods *methods;
} LinkedStack;


void LinkedStack_initialize(LinkedStack *this, string name);

void LinkedStack_finalize(LinkedStack *this);

LinkedStack *LinkedStack_new();

void LinkedStack_delete(LinkedStack *this);

void LinkedStack_push(LinkedStack *this, void *data);

void *LinkedStack_pop(LinkedStack *this);

void *LinkedStack_peek(LinkedStack *this);


#endif /* _LINKED_STACK_H_ */
