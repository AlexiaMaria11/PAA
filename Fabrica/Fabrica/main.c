#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int d[MAX];

void dijkstra(int matrice[MAX][MAX], int n, int* vizitat, int start)
{
	for (int i = 0; i < n; i++)
		d[i] = 9999;
	d[start] = 0;
	for (int pas = 1; pas < n; pas++)
	{
		int u = -1, min = 9999;
		for(int i=0; i<n; i++)
			if (vizitat[i] == 0 && d[i] < min)
			{
				min = d[i];
				u = i;
			}
		if (u == -1) break;
		vizitat[u] = 1;
		for (int i = 0; i < n; i++)
			if (vizitat[i] == 0 && matrice[u][i] && d[u] + matrice[u][i] < d[i])
				d[i] = matrice[u][i] + d[u];
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
		matrice[a][b] = c;
	fclose(f);
	int vizitat[MAX] = { 0 };
	dijkstra(matrice, n, vizitat, 0);
	printf("Costul de la fabrica 1 la fabrica %d este %d\n", n, d[n - 1]);
	return 0;
}