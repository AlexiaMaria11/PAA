#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ArbGenParentPointer.h"

TTree citire(char* nume, TTree t) {
	FILE* fis = fopen(nume, "r");
	if (fis == NULL)
	{
		printf("Eroare deschidere fisier\n");
		exit(-1);
	}
	uint8_t a, b;
	while (fscanf(fis, "%hhu %hhu", &a, &b) == 2) {
		t = InsertNode(t, b, a);
	}
	fclose(fis);
	return t;
}

int main(int argc, char* argv[]) {
	TTree* tree = (TTree*)malloc(sizeof(TTree));
	if (tree == NULL) {
		printf("Eroare alocare dinamica\n");
		exit(-1);
	}
	*tree = InitTree(*tree);
	*tree = citire(argv[1], *tree);
	printArray(*tree);
	printf("\nPreorder: \n");
	preOrder(*tree);
	printf("\nInorder: \n");
	inOrder(*tree);
	printf("\nPostorder: \n");
	postOrder(*tree);
	free(tree);
	return 0;
}