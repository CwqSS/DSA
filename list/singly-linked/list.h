#ifndef LIST
#define LIST
typedef struct node {
    int key;
    struct node * next;
} node;
typedef struct singly_linked_list {
    node * head;
} list;
list * createList();
node * createNode(int key);
node * listSearch(list * L, int key); 
void listInsert(list * L, int key);
void listInsertAtEnd(list * L, int key);
void listInsertAfterNode(node * x, int key);
void listDelete(list * L, node * x);
void printList(list * L);
void freeList(list ** L);
#endif