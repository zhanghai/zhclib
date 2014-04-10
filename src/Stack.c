/**
 * @file Stack.c
 * @author: Zhang Hai
 */

#include "Stack.h"


void Stack_initialize(Stack *this, string name) {

    LinkedList_initialize((LinkedList *)this, name);

    _$(this, new) = Stack_new;
    _$(this, delete) = Stack_delete;
    _$(this, peek) = Stack_peek;
    _$(this, pop) = Stack_pop;
    _$(this, push) = Stack_push;
}

void Stack_finalize(Stack *this) {
    LinkedList_finalize((LinkedList *)this);
}

Stack *Stack_new() {
    OBJECT_NEW(Stack, , "Stack")
}

OBJECT_DEFINE_DELETE(Stack)

/**
 * Peek the data at the top of a {@link Stack} without popping it.
 * @return The data at the top of this stack, or null if empty.
 */
void *Stack_peek(Stack *this) {
    StackNode *tail = _(this, tail);
    if (tail == null) {
        return null;
    } else {
        return tail->data;
    }
}

/**
 * Pop the data at the top of a {@link Stack}.
 * @note This implementation prevents {@link deleteNode} from free
 *       the returned data by setting the node to null before calling
 *       it.
 *       You may want to override this function to deal with other
 *       types of memory management.
 * @return The data at the top of this stack, or null if empty.
 */
void *Stack_pop(Stack *this) {
    StackNode *tail = _(this, tail);
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
 * Push a piece of data into a {@link Stack}.
 * @param data The data to be push into the stack.
 */
void Stack_push(Stack *this, void *data) {
    $(this, addEnd, data);
}
