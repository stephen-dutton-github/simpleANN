//
// Created by sdutton on 09.05.23.
//

#ifndef SIMPLEANN_STACK_H
#define SIMPLEANN_STACK_H

#define STACK_SIZE 100000000  // define max size of stack

typedef struct Stack {
    void* data[STACK_SIZE];
    int top;
}  *pStack;

pStack initStack();
int push(struct Stack* stack, void* item) ;
void* pop(struct Stack* stack) ;

#endif //SIMPLEANN_STACK_H

