#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

queue * createQueue(int size) {
    queue * Q = NULL;
    if(size > 0) {
        Q = (queue *) malloc(sizeof(queue));
        Q->tail = 0;
        Q->head = 0;
        Q->size = size;
        Q->values = malloc(sizeof(int) * size);
    }
    return Q;
}

int isQueueFull(queue * Q) {
    if((Q->tail + 1) % Q->size == Q->head)
        return 1;
    else return 0;
}

int isQueueEmpty(queue * Q) {
    if(Q->tail == Q->head)
        return 1;
    else return 0;
}

void enqueue(queue * Q, int element) {
    if(!isQueueFull(Q)) {
        Q->values[Q->tail] = element;
        if(Q->tail + 1 == Q->size)
            Q->tail = 0;
        else Q->tail = Q->tail + 1;
    }
    else printf("Error: the queue is full\n");
}

int dequeue(queue * Q) {
    if(isQueueEmpty(Q)) {
        printf("Error: the queue is empty\n");
        return INT_MAX;
    }
    else {
        int element = Q->values[Q->head];
        if(Q->head + 1 == Q->size)
        Q->head = 0;
        else Q->head = Q->head + 1;
        return element;
    }
}

void freeQueue(queue ** Q) {
    if(*Q != NULL) {
        if((*Q)->values != NULL)
            free((*Q)->values);
        free(*Q);
        *Q = NULL;
    }
}