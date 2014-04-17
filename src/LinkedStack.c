/**
 * @file LinkedStack.c
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

#include "LinkedStack.h"


void LinkedStack_initialize(LinkedStack *this, string name) {

    LinkedList_initialize((LinkedList *)this, name);

    _$(this, new) = LinkedStack_new;
    _$(this, delete) = LinkedStack_delete;
    _$(this, push) = LinkedStack_push;
    _$(this, pop) = LinkedStack_pop;
    _$(this, peek) = LinkedStack_peek;
}

void LinkedStack_finalize(LinkedStack *this) {
    LinkedList_finalize((LinkedList *)this);
}

LinkedStack *LinkedStack_new() {
    OBJECT_NEW(LinkedStack, , "LinkedStack")
}

OBJECT_DEFINE_DELETE(LinkedStack)

/**
 * Peek the data at the top of a {@link LinkedStack} without popping it.
 * @return The data at the top of this stack, or null if empty.
 */
void *LinkedStack_peek(LinkedStack *this) {
    LinkedStackNode *tail = _(this, tail);
    if (tail == null) {
        return null;
    } else {
        return tail->data;
    }
}

/**
 * Pop the data at the top of a {@link LinkedStack}.
 * @note This implementation prevents {@link deleteNode} from free
 *       the returned data by setting the node to null before calling
 *       it.
 *       You may want to override this function to deal with other
 *       types of memory management.
 * @return The data at the top of this stack, or null if empty.
 */
void *LinkedStack_pop(LinkedStack *this) {
    LinkedStackNode *tail = _(this, tail);
    if (tail == null) {
        return null;
    }
    void *data = tail->data;
    /* HACK: Protect data from finalization. */
    tail->data = null;
    $(this, removeNode, tail);
    return data;
}

/**
 * Push a piece of data into a {@link LinkedStack}.
 * @param data The data to be push into the stack.
 */
void LinkedStack_push(LinkedStack *this, void *data) {
    $(this, addEnd, data);
}
