#include <stdio.h>
#include <stdlib.h>
#include "../singly-linked/list.h"

int main() {
    node * x, * y;
    list * L = createList();
    printList(L);

    listPrepend(L, 20);
    listPrepend(L, 30);
    listPrepend(L, 40);
    printList(L);
    
    listInsertAtEnd(L, 50);
    listInsertAtEnd(L, 60);
    printList(L);

    x = listSearch(L, 40);
    y = listSearch(L, 30);

    printf("Looking for node x with key 40...\n");
    printf("x->key == %d\n", x->key);
    printf("Looking for node y with key 30...\n");
    printf("y->key == %d\n", y->key);

    listInsert(x, 15);
    listInsert(y, 25);
    printList(L);
    
    listDelete(L, x);
    printList(L);
    listDelete(L, y);
    printList(L);

    freeList(&L);
    printList(L);
}