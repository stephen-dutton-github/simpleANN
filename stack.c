//
// Created by sdutton on 09.05.23.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


// Initialize stack
pStack initStack() {
    pStack stack = malloc(sizeof (struct Stack));
    stack->top = -1;
    push(stack, stack);
    return stack;
}

// Push an item onto the stack
int push(struct Stack* stack, void* item) {
    if (stack->top == STACK_SIZE - 1) {
        printf("Stack is full.\n");
        return -1;
    }
    stack->data[++stack->top] = item;
    return 0;
}

// Pop an item from the stack
void* pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return NULL;
    }
    return stack->data[stack->top--];
}


