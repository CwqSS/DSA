#include <stdio.h>
#include <stdlib.h>
#include "../array-based/stack.h"

int main() {
    stack * S = createStack(0);

    if(S == NULL)
        puts("createStack(int size) works for size equals to 0.");
    else puts("createStack(int size) does not work for size equals to 0.");

    S = createStack(10);

    if(S != NULL) {
        printf("createStack(int size) works for sizes greater than 0.\n");
        printf("pointer to S: %x\n", S);
        printf("pointer to S->values: %x\n", S->values);
        printf("S->top: %d\n", S->top);
        printf("S->size: %d\n", S->size);
    }

    int i = 0;
    printf("Push values: ");
    while(!isStackFull(S)) {
        push(S, i);
        printf("%d ", i);
        i = i + 1;
    }
    printf("\n");
    push(S, i);
    
    int pushAndPopWorks = 1;
    i = 9;
    printf("Pop: ");
    while(!isStackEmpty(S) && pushAndPopWorks) {
        int x = pop(S);
        printf("%d ", x);
        if(x != i)
            pushAndPopWorks = 0;
        i = i - 1;
    }
    printf("\n");
    int x = pop(S);

    if(pushAndPopWorks)
        puts("Push and Pop work correctly");

    freeStack(&S);

    if(S == NULL)
        puts("freeStack(Stack ** S) works.");
    else puts("freeStack(Stack ** S) does not work.");
}