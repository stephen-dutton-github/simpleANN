//
// Created by sdutton on 09.05.23.
//

#ifndef SIMPLEANN_STACK_H
#define SIMPLEANN_STACK_H

typedef struct stackNodeDef{
    int isSentinel;
    struct stackNodeDef* previous;
    void* value;
} stackNode, *pStackNode;

typedef struct stackDef{
    pStackNode sentinel;
    pStackNode current;
    void (*push)(void*);
    void* (*pop)();
    void* (*peek)();
} stack, *pStack;

void push(void* item);
void* pop();
void* peek();
pStack initStack();
void freeStack();

#endif //SIMPLEANN_STACK_H

