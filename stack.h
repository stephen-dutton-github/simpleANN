//
// Created by sdutton on 09.05.23.
//

#ifndef SIMPLEANN_STACK_H
#define SIMPLEANN_STACK_H

#define STACK_SIZE 100  // define max size of stack

typedef struct Stack {
    void* data[STACK_SIZE];
    int top;
}  *pStack;

void init(struct Stack* stack) ;
int push(struct Stack* stack, void* item) ;
void* pop(struct Stack* stack) ;

#endif //SIMPLEANN_STACK_H

