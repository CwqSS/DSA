#include <stdlib.h>
#include <stdio.h>
#include "../lifo/list-based/stack.h"

// Para compilar: gcc ..\lifo\list-based\stack.c .\expressionTree.c -o main

#pragma region TREE_HEADER
typedef struct node {
    char * str;
    int length;
    struct node * left;
    struct node * right;
    struct node * parent;
} node;

typedef struct tree {
    node * root;
} tree;

char * copySubStr(char * s, int length) {
    if(s == NULL || length == 0)
        return NULL;
    int i;
    char * str = malloc(sizeof(char) * (length + 1));
    for(i = 0; i < length; i = i + 1) {
        str[i] = s[i];
    }
    str[i] = '\0';
    // printf("%s %s -> %d\n", str, s, length);
    return str;
}

node * createNode(char * str, int length)  {
    node * n = malloc(sizeof(node));
    n->str = copySubStr(str, length);
    if(n->str == NULL)
        n->length = 0;
    else n->length = length;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}

tree * createTree() {
    tree * T = malloc(sizeof(tree));
    T->root = NULL;
    return T;
}

int findLowestPriorityOperator(char * s, int length) { 
    int i, condition = 0;
    for(i = length - 1; i > -1 && !condition; i = i - 1) {
        if(s[i] == '-' || s[i] == '+')
            condition = 1;
    }
    i = i + 1;

    if(condition)
        return i;

    for(i = length - 1; i > -1 && !condition; i = i - 1) {
        if(s[i] == '*' || s[i] == '/')
            condition = 1;
    }
    i = i + 1;

    if(condition)
        return i;
    else return -1;
}

int stringToNumber(char * s, int length) {
    int i = 0, sum = 0;
    while(i < length) {
        sum = sum * 10 + s[i] - '0';
        i = i + 1;
    }
    return sum;
}

void transform_expression(node * root) {
    if(root->length > 1) {
        int root_p = findLowestPriorityOperator(root->str, root->length);
        if(root_p >= 0) {
            char * s = root->str;
            root->left = createNode(s, root_p);
            root->right = createNode((s + root_p + 1), root->length - root_p - 1);
            root->left->parent = root;
            root->right->parent = root;
            root->str = copySubStr((s + root_p), 1);
            transform_expression(root->left);
            transform_expression(root->right);
        }
    }
}

int stringLength(char * s) {
    int i = 0;
    while(s[i]) {
        i = i + 1;
    }
    return i;
}

void tree_expression(tree * T, char * s) {
    if(s != NULL && T != NULL) {
        if(T->root == NULL) {
            T->root = createNode(s, stringLength(s));
        }
        transform_expression(T->root);
    }
}

void tree_innorder(node * root) {
    if(root != NULL) {
        tree_innorder(root->left);
        printf("%s", root->str);
        tree_innorder(root->right);
    }
}
void tree_postorder(node * root) {
    if(root != NULL) {
        tree_postorder(root->left);
        tree_postorder(root->right);
        printf("%s", root->str);
    }
}

#pragma endregion

void calculateSubArv(node * root, stack * S) {
    if(root != NULL) {
        calculateSubArv(root->left, S);
        calculateSubArv(root->right, S);
        if(root->str[0] >= '0' && root->str[0] <= '9') {
            push(S, stringToNumber(root->str, root->length));
        }
        else {
            int A, B; 
            if(root->str[0] == '-') {
                A = pop(S);
                B = pop(S);
                push(S, A - B);
            }
            else if(root->str[0] == '+') {
                A = pop(S);
                B = pop(S);
                push(S, A + B);
            }
            else if(root->str[0] == '*') {
                A = pop(S);
                B = pop(S);
                push(S, A * B);
            }
            else if(root->str[0] == '/') {
                A = pop(S);
                B = pop(S);
                if(B == 0) {
                    return;
                }
                else push(S, B / A);
            }
        }
    }
}

int calculateTreeExpression(tree * T) {
    stack * S = createStack();
    calculateSubArv(T->root, S);
    int result = pop(S);
    freeStack(&S);
    return result;
}

int main() {
    tree * T = createTree();
    char expression[] = "5+2/3";
    tree_expression(T, expression);
    tree_innorder(T->root);
    printf("\n");
    tree_postorder(T->root);
    printf("\n");
    printf("%d", calculateTreeExpression(T));
}