#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <limits.h>

qNode * createQNode(int value) {
    qNode * n = malloc(sizeof(qNode));
    n->value = value;
    n->next = NULL;
    return n;
}

queue * createQueue() {
    queue * Q = malloc(sizeof(queue));
    Q->tail = NULL;
    Q->head = NULL;
    return Q;
}
int isQueueEmpty(queue * Q) {
    if(Q->head == NULL)
        return 1;
    else return 0;
}
void enqueue(queue * Q, int element) {
    qNode * x = createQNode(element);
    if(Q->head == NULL) {
        Q->head = x;
        Q->tail = x;
    }
    else {
        Q->tail->next = x;
        Q->tail = x;
    }
}
int dequeue(queue * Q) {
    if(Q->head == NULL) {
        printf("Error: the queue is empty!");
        return INT_MAX;
    }

    if(Q->head == Q->tail)
        Q->tail = NULL;

    qNode * x = Q->head;
    int value = x->value;
    Q->head = Q->head->next;
    free(x);
    return value;
}

void freeQueue(queue ** Q) {
    if(*Q != NULL) {
        if((*Q)->head != NULL) {
            qNode * x = (*Q)->head;
            qNode * y;
            while(x != NULL) {
                y = x;
                x = x->next;
                free(y);
            }
        }
        free(*Q);
        *Q = NULL;
    }
}