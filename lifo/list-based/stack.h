#ifndef STACK
#define STACK
typedef struct sNode {
    int value;
    struct sNode * previous;
} sNode;
typedef struct stack {
    sNode * top;
} stack;
sNode * createSNode(int value);
stack * createStack();
// int isStackFull(stack * S);
int isStackEmpty(stack * S);
void push(stack * S, int element);
int pop(stack * S);
void freeStack(stack ** S);
#endif