#include <stdint.h>
#include <stdio.h>

typedef struct Node {
    int data; 
    struct Node* left; 
    struct Node* right; 
} Node;

Node* createNode(int value);

Node* insert(Node* root, int value);

void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);

void printTree(Node* root);

void freeTree(Node* root);