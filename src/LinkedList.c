/**
 * @file LinkedList.c
 * @author Zhang Hai
 */

#include "LinkedList.h"


void LinkedList_initialize(LinkedList *this, string name) {

    Object_initialize((Object *)this, name);

    _(this, head) = null;
    _(this, tail) = null;
    _(this, size) = 0;

    _$(this, new) = LinkedList_new;
    _$(this, delete) = LinkedList_delete;
    _$(this, newNode) = LinkedList_newNode;
    _$(this, deleteNode) = LinkedList_deleteNode;
    _$(this, addStart) = LinkedList_addStart;
    _$(this, addEnd) = LinkedList_addEnd;
    _$(this, insertBefore) = LinkedList_insertBefore;
    _$(this, insertAfter) = LinkedList_insertAfter;
    _$(this, removeNode) = LinkedList_removeNode;
    _$(this, remove) = LinkedList_remove;
    _$(this, swap) = LinkedList_swap;
    _$(this, sort) = LinkedList_sort;
    _$(this, search) = LinkedList_search;
}

void LinkedList_finalize(LinkedList *this) {

    LinkedListNode *node, *nextNode;
    for (node = _(this, head); node != null; ) {
        nextNode = node->next;
        $_(this, deleteNode, node);
        node = nextNode;
    }

    Object_finalize((Object *)this);
}

LinkedList *LinkedList_new() {
    OBJECT_NEW(LinkedList, , "LinkedList")
}

OBJECT_DEFINE_DELETE(LinkedList)

/**
 * @protected
 * Create a new {@link LinkedListNode} instance.
 * @param data The data to be held by the new node.
 * @param previous The node previous to the new node.
 * @param next The node next to the new node.
 * @return The created {@link LinkedListNode} instance.
 */
LinkedListNode *LinkedList_newNode(void *data, LinkedListNode *previous,
        LinkedListNode *next) {

    LinkedListNode *node = Memory_allocateType(LinkedListNode);

    node->data = data;
    node->previous = previous;
    node->next = next;

    return node;
}

/**
 * @protected
 * Destroy a {@link LinkedListNode} instance and free its data.
 * @note You may want to override this function to deal with other
 *       types of memory management.
 * @param node The node to be destroyed.
 */
void LinkedList_deleteNode(LinkedListNode *node) {

    Memory_free(node->data);

    Memory_free(node);
}

/**
 * Add a node holding some data to the start of a {@link LinkedList}.
 * @param data The data to be added.
 * @return The newly added node.
 */
LinkedListNode *LinkedList_addStart(LinkedList *this, void *data) {

    LinkedListNode *node = $_(this, newNode, data, null,
            _(this, head));

    if (_(this, head) != null) {
        _(this, head)->previous = node;
    }

    _(this, head) = node;
    if (_(this, tail) == null) {
        _(this, tail) = node;
    }

    ++_(this, size);

    return node;
}

/**
 * Add a node holding some data to the end of a {@link LinkedList}.
 * @param data The data to be added.
 * @return The newly added node.
 */
LinkedListNode *LinkedList_addEnd(LinkedList *this, void *data) {

    LinkedListNode *node = $_(this, newNode, data, _(this, tail),
            null);

    if (_(this, tail) != null) {
        _(this, tail)->next = node;
    }

    _(this, tail) = node;
    if (_(this, head) == null) {
        _(this, head) = node;
    }

    ++_(this, size);

    return node;
}

/**
 * Insert a new node holding some data before a node.
 * @param node The node to insert before.
 * @param data The data to be inserted.
 * @return The newly inserted node.
 */
LinkedListNode *LinkedList_insertBefore(LinkedList *this,
        LinkedListNode *node, void *data) {

    LinkedListNode *newNode = $_(this, newNode, data, node->previous,
            node);

    if (node->previous != null) {
        node->previous->next = newNode;
    } else {
        _(this, head) = newNode;
    }
    node->previous = newNode;

    ++_(this, size);

    return newNode;
}

/**
 * Insert a new node holding some data after a node.
 * @param node The node to insert after.
 * @param data The data to be inserted.
 * @return The newly inserted node.
 */
LinkedListNode *LinkedList_insertAfter(LinkedList *this,
        LinkedListNode *node, void *data) {

    LinkedListNode *newNode = $_(this, newNode ,data, node,
            node->next);

    if (node->next != null) {
        node->next->previous = newNode;
    } else {
        _(this, tail) = newNode;
    }
    node->next = newNode;

    ++_(this, size);

    return newNode;
}

/**
 * Remove a node from a {@link LinkedList}.
 * @param node The node to be removed.
 * @return the node following the removed one, or null if the tail
 *         node is removed.
 */
LinkedListNode *LinkedList_removeNode(LinkedList *this,
        LinkedListNode *node) {

    LinkedListNode *nextNode = node->next;

    if (node->previous != null) {
        node->previous->next = node->next;
    } else {
        _(this, head) = node->next;
    }
    if (node->next != null) {
        node->next->previous = node->previous;
    } else {
        _(this, tail) = node->previous;
    }

    $_(this, deleteNode, node);

    --_(this, size);

    return nextNode;
}

/**
 * Remove a piece of data from a {@link LinkedList}.
 * @note This function will only remove the first occurrence of the
 *       data.
 * @param data The data to be removed.
 */
void LinkedList_remove(LinkedList *this, void *data) {
    LinkedListNode *node;
    LINKED_LIST_FOR_EACH(this, node) {
        if (node->data == data) {
            $(this, removeNode, node);
            return;
        }
    }
}

/**
 * Swap two nodes in a {@link LinkedList}.
 * @note This function will simply swap the data of the two nodes.
 * @param node1 The first node to be swapped.
 * @param node2 The second node to be swapped.
 */
void LinkedList_swap(LinkedList *this, LinkedListNode *node1,
        LinkedListNode *node2) {
    void *tmp;
    SWAP(node1->data, node2->data, tmp);
}

/**
 * Sort a {@link LinkedList} by a comparator.
 * @note This function uses bubble sort.
 * @param comparator The comparator for sorting.
 */
void LinkedList_sort(LinkedList *this, Comparator comparator) {

    LinkedListNode *node1, *node2;
    bool changed;

    if (_(this, size) == 0) {
        return;
    }

    for (node1 = _(this, head); node1->next != null;
            node1 = node1->next) {

        changed = false;

        for (node2 = _(this, tail); node2 != node1; ) {
            if (comparator(node2->previous->data, node2->data) > 0) {
                $(this, swap, node2->previous, node2);
                changed = true;
            } else {
                node2 = node2->previous;
            }
        }

        if (!changed) {
            break;
        }
    }
}

/**
 * Search in a {@link LinkedList} by a filter.
 * @param filter A filter function for the search.
 * @param criteria The criteria data to be passed into the filter.
 * @return A {@link LinkedList} containing the result.
 */
LinkedList *LinkedList_search(LinkedList *this, Filter filter) {

    LinkedList *result = $_(this, new);
    LinkedListNode *node;

    LINKED_LIST_FOR_EACH(this, node) {
        if (filter.filter(node->data, filter.filterData)) {
            $(result, addEnd, node->data);
        }
    }

    return result;
}
