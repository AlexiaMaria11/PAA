#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

void Prim(int matrice[MAX][MAX], int n)
{
	int u[MAX] = { 0 };
	u[0] = 1;
	printf("Prim\n");
	for (int pas = 1; pas < n; pas++)
	{
		int mini = -1, minj = -1, min = 9999;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if (matrice[i][j] && u[i] && !u[j] && matrice[i][j] < min)
				{
					mini = i;
					minj = j;
					min = matrice[i][j];
				}
		if (mini != -1 && minj != -1)
		{
			u[minj] = 1;
			printf("Muchia %d - %d, cost %d\n", mini, minj, min);
		}
	}
}

void Kruskal(int matrice[MAX][MAX], int n)
{
	int s[MAX];
	for (int i = 0; i < n; i++)
		s[i] = i;
	printf("Kruskal\n");
	for (int pas = 1; pas < n; pas++)
	{
		int mini = -1, minj = -1, min = 9999;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if (matrice[i][j] && s[i] != s[j] && matrice[i][j] < min)
				{
					min = matrice[i][j];
					mini = i;
					minj = j;
				}
		for (int i = 0; i < n; i++)
			if (s[i] == s[minj])
				s[i] = s[mini];
		if (mini != -1 && minj != -1)
			printf("Muchia %d - %d, cost %d\n", mini, minj, min);
	}
}

int main(void)
{
	FILE* f = fopen("input.txt", "r");
	if (f == NULL)
	{
		printf("Eroare la deschidere fisier\n");
		exit(-1);
	}
	int n, a, b, c;
	fscanf(f, "%d", &n);
	int matrice[MAX][MAX] = { 0 };
	while ((fscanf(f, "%d %d %d", &a, &b, &c)) == 3)
	{
		matrice[a][b] = c;
		matrice[b][a] = c;
	}
	fclose(f);
	int maxim = 0;
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < n; j++)
			if (matrice[i][j]) c++;
		if (c > maxim) maxim = c;
	}
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < n; j++)
			if (matrice[i][j]) c++;
		if (c == maxim)
		{
			printf("Calculatorul %d are cele mai multe conexiuni\n", c);
			break;
		}
	}
	Prim(matrice, n);
	Kruskal(matrice, n);
	//pentru a verifica daca arborii de acoperire sunt identici
	//salvam toate muchiile intr-o matrice cu 2 coloane
	//si verificam daca gasim toate muchiile dintr-o matrice in cealalta matrice
	return 0;
}