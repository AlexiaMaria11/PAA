#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int pred[MAX], dist[MAX];

void afisare(int dest, int* pred)
{
	if (pred[dest] == -1)
	{
		printf("L%d", dest+1);
		return;
	}
	afisare(pred[dest], pred);
	printf(" -> L%d", dest+1);
}

void dijkstra(int matrice[MAX][MAX], int n, int m, int start)
{
	int vizitat[MAX] = { 0 };
	for (int i = 0; i < n; i++)
	{
		pred[i] = -1;
		dist[i] = 9999;
	}
	dist[start] = 0;
	for (int pas = 1; pas < n; pas++)
	{
		int u = -1, minim = 9999;
		for(int i=0; i<n; i++)
			if (vizitat[i] == 0 && dist[i] < minim)
			{
				minim = dist[i];
				u = i;
			}
		if (u == -1) break;
		vizitat[u] = 1;
		for(int i=0; i<n; i++)
			if (vizitat[i] == 0 && matrice[u][i]>0)
			{
				int drum = matrice[u][i];
				int total = drum + dist[u];
				if (u != start) total += m;
				if (total < dist[i])
				{
					dist[i] = total;
					pred[i] = u;
				}
			}
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
	int n, m; //n-localitati, m-minute de asteptare
	fscanf(f, "%d %d", &n, &m);
	int matrice[MAX][MAX] = { 0 };
	int a, b, c;
	while ((fscanf(f, "%d %d %d", &a, &b, &c)) == 3)
	{
		matrice[a][b] = c;
		matrice[b][a] = c;
	}
	dijkstra(matrice, n, m, 0); //plec din L1
	for (int i = 1; i < n; i++)
	{
		if (dist[i] == 9999) printf("Nu exista drum\n");
		else
		{
			printf("Drum de la L1 la L%d: ", i + 1);
			afisare(i, pred);
			printf(" cu costul %d\n", dist[i]); 
		}
	}
	fclose(f);
	return 0;
}