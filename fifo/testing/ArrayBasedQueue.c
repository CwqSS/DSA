#include <stdio.h>
#include <stdlib.h>
#include "../array-based/queue.h"

int main() {
    queue * Q = createQueue(0);

    if(Q == NULL)
        puts("createQueue(int size) works for size equals to 0.");
    else puts("createQueue(int size) does not work for size equals to 0.");

    Q = createQueue(10);

    if(Q != NULL) {
        printf("createQueue(int size) works for sizes greater than 0.\n");
        printf("pointer to Q: %x\n", Q);
        printf("pointer to Q->values: %x\n", Q->values);
        printf("Q->head: %d\n", Q->head);
        printf("Q->tail: %d\n", Q->tail);
        printf("Q->size: %d\n", Q->size);
    }

    int i = 0;
    printf("Enqueue values: ");
    while(!isQueueFull(Q)) {
        enqueue(Q, i);
        printf("%d ", i);
        i = i + 1;
    }
    printf("\n");
    enqueue(Q, i);
    
    int enqueueAndDequeueWorks = 1;
    i = 0;
    printf("Dequeue: ");
    while(!isQueueEmpty(Q) && enqueueAndDequeueWorks) {
        int x = dequeue(Q);
        printf("%d ", x);
        if(x != i)
        enqueueAndDequeueWorks = 0;
    i = i + 1;
    }
    printf("\n");
    int x = dequeue(Q);

    if(enqueueAndDequeueWorks)
        puts("Enqueue and Dequeue work correctly");

    freeQueue(&Q);

    if(Q == NULL)
        puts("freeQueue(queue ** Q) works.");
    else puts("freeQueue(queue ** Q) does not work.");
}