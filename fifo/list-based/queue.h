#ifndef QUEUE
#define QUEUE

typedef struct qNode {
    int value;
    struct qNode * next;
} qNode;

typedef struct queue {
    qNode * tail;
    qNode * head;
} queue;
qNode * createQNode(int value);
queue * createQueue(int size);
// int isQueueFull(queue * Q);
int isQueueEmpty(queue * Q);
void enqueue(queue * Q, int element);
int dequeue(queue * Q);
void freeQueue(queue ** Q);
#endif