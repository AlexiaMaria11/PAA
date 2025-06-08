#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 20

int n, x, y;
int drum[MAX], vizitat[MAX];

// DFS pentru drumuri de la nod curent la y
void dfs(int curent, int lungime) {
    drum[lungime] = curent;
    vizitat[curent] = 1;

    if (curent == y) {
        // Afișăm drumul
        for (int i = 0; i <= lungime; i++) {
            printf("%d", drum[i]);
            if (i < lungime) printf(" -> ");
        }
        printf("\n");
    }
    else {
        for (int next = curent + 1; next < n; next++) {
            if (!vizitat[next]) {
                dfs(next, lungime + 1);
            }
        }
    }

    vizitat[curent] = 0; // backtrack
}

int main() {
    printf("Numar noduri (n): ");
    scanf("%d", &n);
    printf("Nod de start (x): ");
    scanf("%d", &x);
    printf("Nod de final (y): ");
    scanf("%d", &y);

    if (x >= y || x < 0 || y >= n) {
        printf("Valori invalide: trebuie x < y si in intervalul [0, n-1]\n");
        return 1;
    }

    printf("Drumuri de la %d la %d:\n", x, y);
    dfs(x, 0);

    return 0;
}
