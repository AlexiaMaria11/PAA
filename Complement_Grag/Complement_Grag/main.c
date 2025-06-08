#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int main(void)
{
	FILE* f = fopen("input.txt", "r");
	if (f == NULL)
	{
		printf("Eroare deschidere fisier\n");
		exit(-1);
	}
	int n;
	fscanf(f, "%d", &n);
	int matrice[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fscanf(f, "%d", &matrice[i][j]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				matrice[i][j] = 1 - matrice[i][j];
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	fclose(f);
	return 0;
}