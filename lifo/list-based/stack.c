#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

sNode * createSNode(int value) {
    sNode * n = malloc(sizeof(sNode));
    n->value = value;
    n->previous = NULL; 
}
stack * createStack() {
    stack * S = malloc(sizeof(stack));
    S->top = NULL;
    return S;
}
int isStackEmpty(stack * S) {
    if(S->top == NULL)
        return 1;
    else return 0;
}
void push(stack * S, int element) {
    sNode * x = createSNode(element);
    x->previous = S->top;
    S->top = x;
}
int pop(stack * S) {
    if(isStackEmpty(S)) {
        return INT_MAX;
    }
    sNode * x = S->top;
    S->top = x->previous;
    int value = x->value;
    free(x);
    return value;
}
void freeStack(stack ** S) {
    if(*S != NULL) {
        if((*S)->top != NULL) {
            sNode * x = (*S)->top;
            sNode * y;
            while(x != NULL) {
                y = x;
                x = x->previous;
                free(y);
            }
        }
        free(*S);
        *S = NULL;
    }
}