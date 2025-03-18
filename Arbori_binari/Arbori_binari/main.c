#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

Node* citire(Node* root, char* nume)
{
	FILE* fis = fopen(nume, "r");
	if (fis == NULL)
	{
		printf("Eroare deschidere fisier\n");
		exit(-1);
	}
	int value;
	while (fscanf(fis, "%d", &value) == 1)
	{
		root = insert(root, value);
	}
	fclose(fis);
	return root;
}

int main(int argc, char* argv[])
{
	Node* root = NULL;
	root=citire(root, argv[1]);
	printTree(root);
	freeTree(root);
	return 0;
}