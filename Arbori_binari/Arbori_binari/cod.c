#include<stdlib.h>
#include<stdio.h>
#include "biblio.h"

Node* createNode(int value)
{
	Node* nou = (Node*)malloc(sizeof(Node));
	if (nou == NULL)
	{
		printf("Eroare alocare\n");
		exit(-1);
	}
	nou->data = value;
	nou->left = NULL;
	nou->right = NULL;
	return nou;
}

Node* insert(Node* root, int value) {
	if (root == NULL)
		return createNode(value);
	if (value < root->data)
		root->left = insert(root->left, value);
	else
		if (value > root->data)
			root->right = insert(root->right, value);
	return root;
}

void preOrder(Node* root)
{
	if (root)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root)
{
	if (root)
	{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(Node* root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

void printTree(Node* root)
{
	if (root == NULL)
	{
		printf("Arbore gol\n");
		return;
	}
	printf("Parcurgere inOrdine: ");
	inOrder(root);
	printf("\n");
	printf("Parcurgere preOrdine: ");
	preOrder(root);
	printf("\n");
	printf("Parcurgere postOrdine: ");
	postOrder(root);
	printf("\n");
}

void freeTree(Node* root)
{
	if (root != NULL)
	{
		freeTree(root->right);
		freeTree(root->left);
		free(root);
	}
}