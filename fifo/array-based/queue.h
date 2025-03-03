#ifndef QUEUE
#define QUEUE
typedef struct queue {
    int * values;
    int tail;
    int head;
    int size;
} queue;
queue * createQueue(int size);
int isQueueFull(queue * Q);
int isQueueEmpty(queue * Q);
void enqueue(queue * Q, int element);
int dequeue(queue * Q);
void freeQueue(queue ** Q);
#endif