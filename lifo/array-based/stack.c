#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

stack * createStack(int size) {
    stack * S = NULL;
    if(size > 0) {
        S = malloc(sizeof(stack));
        S->top = 0;
        S->size = size;
        S->values = malloc(sizeof(int) * size);
    }
    return S;
}

int isStackFull(stack * S) {
    if(S->top == S->size)
        return 1;
    else return 0;
}

int isStackEmpty(stack * S) {
    if(S->top == 0)
        return 1;
    else return 0;
}

void push(stack * S, int element) {
    if(!isStackFull(S)) {
        S->values[S->top] = element;
        S->top = S->top + 1;
    }
    else printf("Error: stack overflow\n");
}

int pop(stack * S) {
    if(isStackEmpty(S)) {
        printf("Error: stack underflow\n");
        return INT_MAX;
    }
    else {
        S->top = S->top - 1;
        return S->values[S->top];
    }
}

void freeStack(stack ** S) {
    if(*S != NULL) {
        if((*S)->values != NULL)
            free((*S)->values);
        free(*S);
        *S = NULL;
    }
}