#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "TransArbFiu.h"

TTree citire(char* nume, TTree t) {
	FILE* fis = fopen(nume, "r");
	if (fis == NULL)
	{
		printf("Eroare deschidere fisier\n");
		exit(-1);
	}
	uint8_t a, b, c;
	while (fscanf(fis, "%hhu %hhu %hhu", &a, &b, &c) == 3) {
		t = InsertNode(t, b, c, a);
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
	TNodeB* root = transform(*tree, 1);
	printf("\nPreorderBin: \n");
	preOrderBin(root);
	free(tree);
	freeTree(root);
	return 0;
}