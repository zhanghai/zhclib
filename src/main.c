/**
 * @file main.c
 * @author: Zhang Hai
 */

#include "Common.h"

#include "Stack.h"


int main() {
    Stack *stack;
    Time_start();
    stack = Stack_new();
    $(stack, delete);
    return 0;
}
