#ifndef STACK
#define STACK
typedef struct stack {
    int * values;
    int top;
    int size;
} stack;
stack * createStack(int size);
int isStackFull(stack * S);
int isStackEmpty(stack * S);
void push(stack * S, int element);
int pop(stack * S);
void freeStack(stack ** S);
#endif