#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list * createList() {
    list * L = malloc(sizeof(list));
    L->head = NULL;
    return L;
}
node * createNode(int key) {
    node * new = malloc(sizeof(node));
    new->key = key;
    new->next = NULL;
    new->previous = NULL;
    return new;
}
node * listSearch(list * L, int key) {
    node * x = L->head;
    while(x != NULL && x->key != key)
        x = x->next;
    return x;
} 
void listPrepend(list * L, int key) {
    node * x = createNode(key);
    if(L->head == NULL) {
        L->head = x;
    }
    else {
        x->next = L->head;
        L->head->previous = x;
        L->head = x;
    }
}
void listInsert(node * x, int key) {
    node * y = createNode(key);
    y->previous = x;
    y->next = x->next;
    if(x->next != NULL)
        x->next->previous = y;
    x->next = y;
}
void listInsertAtEnd(list * L, int key) {
    node * x = createNode(key);
    if(L->head == NULL) {
        L->head = x;
        return;
    }
    node * y = L->head;
    while(y->next != NULL)
        y = y->next;
    y->next = x;
    return;
}
void listDelete(list * L, node * x) {
    if(x->previous != NULL) {
        x->previous->next = x->next;
    }
    else L->head = x->head;
    if(x->next != NULL)
        x->next->previous = x->previous;
}
void printList(list * L) {
    if(L != NULL) {
        if(L->head != NULL) {
            printf("L.head -> ");
            node * x = L->head;
            while(x != NULL) {
                printf("%d <-> ", x->key);
                x = x->next;
            }
            printf("NULL\n");
        }
        else printf("L.head -> NULL\n");
    }
    else printf("L == NULL\n");
}

void freeList(list ** L) {
    if(*L != NULL) {
        if((*L)->head != NULL) {
            node * x = (*L)->head;
            node * y;
            while(x != NULL) {
                y = x;
                x = x->next;
                free(y);
            }
        }
        free(*L);
        *L = NULL;
    }
}