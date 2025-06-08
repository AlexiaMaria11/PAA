#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

void Kruskal(int matrice[MAX][MAX], int n)
{
	int s[MAX];
	for (int i = 0; i < n; i++)
		s[i] = i;
	int suma = 0;
	for (int pas = 1; pas < n; pas++)
	{
		int mini = -1, minj = -1, min = 9999;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if (matrice[i][j] && s[i] != s[j] && matrice[i][j] < min)
				{
					mini = i;
					minj = j;
					min = matrice[i][j];
				}
		for (int i = 0; i < n; i++)
			if (s[i] == s[minj])
				s[i] = s[mini];
		if (mini != -1 && minj != -1)
		{
			printf("Gard de la %d la %d, cost %d\n", mini, minj, min);
			suma += min;
		}
	}
	if (suma % 100 == 0)
		printf("Numar total de stalpi: %d", suma / 100 + 1);
	else
		printf("Numar total de stalpi: %d\n", suma / 100 + 2);
}

int main(void)
{
	FILE* f = fopen("input.txt", "r");
	if (f == NULL)
	{
		printf("Eraore deschidre fisier\n");
		exit(-1);
	}
	int n, a, b, c;
	int matrice[MAX][MAX] = { 0 };
	fscanf(f, "%d", &n);
	while ((fscanf(f, "%d %d %d", &a, &b, &c)) == 3)
	{
		matrice[a][b] = c;
		matrice[b][a] = c;
	}
	fclose(f);
	Kruskal(matrice, n);
	return 0;
}