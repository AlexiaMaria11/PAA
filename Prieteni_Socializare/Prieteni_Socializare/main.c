#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct {
    char nume[32];
    int gen; // 0 = barbat, 1 = femeie
    char resedinta[32];
} om;

void sugestii_prietenie(int matrice[MAX][MAX], om o[MAX], int n, int utilizator) {
    int direct[MAX] = { 0 };   // prieteni direcți
    int vizitat[MAX] = { 0 };  // pentru a evita duplicate
    int count = 0;

    // Marchează prietenii direcți
    for (int i = 0; i < n; i++)
        if (matrice[utilizator][i])
            direct[i] = 1;

    printf("Sugestii pentru %s:\n", o[utilizator].nume);

    // Caută în prietenii prietenilor
    for (int i = 0; i < n; i++) {
        if (matrice[utilizator][i]) { // dacă i este prieten direct
            for (int j = 0; j < n; j++) {
                if (matrice[i][j] && j != utilizator && !direct[j] && !vizitat[j]) {
                    printf("- %s (index %d)\n", o[j].nume, j);
                    vizitat[j] = 1;
                    count++;
                    if (count == 3)
                        return;
                }
            }
        }
    }

    if (count == 0)
        printf("Nicio sugestie gasita.\n");
}

int main(void) {
    FILE* f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        exit(-1);
    }

    int n;
    fscanf(f, "%d\n", &n);  // număr persoane
    om o[MAX];

    for (int i = 0; i < n; i++) {
        char linie[128];
        fgets(linie, sizeof(linie), f);
        sscanf(linie, "%s %d %[^\n]", o[i].nume, &o[i].gen, o[i].resedinta);
    }

    int matrice[MAX][MAX] = { 0 };
    int a, b;

    // Citim relații sub formă de indici
    printf("\nRelatii de prietenie:\n");
    while (fscanf(f, "%d %d", &a, &b) == 2) {
        if (a >= 0 && a < n && b >= 0 && b < n) {
            matrice[a][b] = 1;
            matrice[b][a] = 1;
            printf("%s - %s\n", o[a].nume, o[b].nume);
        }
    }

    fclose(f);

    // Exemplu: sugestii pentru utilizatorul cu index 1 (Ion)
    printf("\n");
    sugestii_prietenie(matrice, o, n, 1);

    return 0;
}
