//
// Created by sdutton on 09.05.23.
//

#include <malloc.h>
#include "stack.h"

pStack stackRef;

void push(void* item){
    if(!stackRef)
        initStack();
    pStackNode newItem = malloc(sizeof (struct stackNodeDef));
    newItem->value = item;
    newItem->previous = stackRef->current;
    stackRef->current = newItem;
};

void* pop(){
    if(!stackRef)
        initStack();
    if(stackRef->current->isSentinel)
        return 0;
    void* result  = stackRef->current->value;
    pStackNode previous = stackRef->current->previous;
    free(stackRef->current);
    stackRef->current = previous;
    return result;
};

void* peek(){
    if(!stackRef)
        initStack();
    if(stackRef->current->isSentinel)
        return 0;
    return stackRef->current->value;
};

void freeStack(){
    while(pop());
}

pStack initStack(){
    if(stackRef)
        return stackRef;
    stackRef = malloc(sizeof(struct stackDef));
    stackRef->sentinel = malloc(sizeof(struct stackNodeDef));
    stackRef->sentinel->isSentinel = 1;
    stackRef->sentinel->previous=0;
    stackRef->current = stackRef->sentinel;

    stackRef->peek = &peek;
    stackRef->pop = &pop;
    stackRef->push = &push;
    initStack();
}

