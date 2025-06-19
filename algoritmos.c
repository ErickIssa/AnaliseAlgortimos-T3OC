#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "algoritmos.h"

TipoItem B[MAXTAM + 1];
int C[BASE];

//-----FUNCOES RADIXSORT-------
void ContagemInt(TipoItem *A, TipoIndice n, int Pass) {
    int i, j;
    for (i = 0; i < BASE; i++) C[i] = 0;

    for (i = 1; i <= n; i++) {
        j = GetBits(A[i].Chave, Pass * M, M);
        C[j]++;
    }

    if (C[0] == n) return;

    for (i = 1; i < BASE; i++) C[i] += C[i - 1];

    for (i = n; i > 0; i--) {
        j = GetBits(A[i].Chave, Pass * M, M);
        B[C[j]] = A[i];
        C[j]--;
    }

    for (i = 1; i <= n; i++) A[i] = B[i];
}

void RadixsortInt(TipoItem *A, TipoIndice n) {
    for (int i = 0; i < NBITS / M; i++)
        ContagemInt(A, n, i);
}

void ImprimeRadix(TipoItem *V, TipoIndice n) {
    for (int i = 1; i <= n; i++)
        printf("%d ", V[i].Chave);
    printf("\n");
}

void TestaRadix(TipoItem *V, TipoIndice n) {
    for (int i = 2; i <= n; i++) {
        if (V[i].Chave < V[i - 1].Chave) {
            printf("ERRO: ");
            ImprimeRadix(V, n);
            return;
        }
    }
    printf("OK: ");
    ImprimeRadix(V, n);
}

int GetBits(int chave, int desloc, int tam) {
    return (chave >> desloc) & ((1 << tam) - 1);
}

// ---FUNCOES BUBBLE-----

void BubbleSortInt(TipoItem *V, TipoIndice n) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (V[j].Chave > V[j + 1].Chave) {
                TipoItem temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }
}

void Imprime(TipoItem *V, TipoIndice n) {
    for (int i = 1; i <= n; i++)
        printf("%d ", V[i].Chave);
    printf("\n");
}

// FUNCOES QUICKSORT

#include <stdio.h>
#include "algoritmos.h"

void Troca(TipoItem *a, TipoItem *b) {
    TipoItem temp = *a;
    *a = *b;
    *b = temp;
}

int Particao(TipoItem *A, int esq, int dir) {
    TipoItem pivo = A[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (A[j].Chave <= pivo.Chave) {
            i++;
            Troca(&A[i], &A[j]);
        }
    }

    Troca(&A[i + 1], &A[dir]);
    return i + 1;
}

void QuickSortRecursivo(TipoItem *A, int esq, int dir) {
    if (esq < dir) {
        int q = Particao(A, esq, dir);
        QuickSortRecursivo(A, esq, q - 1);
        QuickSortRecursivo(A, q + 1, dir);
    }
}

void QuickSortInt(TipoItem *A, TipoIndice n) {
    QuickSortRecursivo(A, 1, n);  // Começa do índice 1 até n
}

// ------BubbleSort Otimizado-----

void BubbleSortCacheOptimized(TipoItem *V, TipoIndice n) {
    int trocou;
    TipoIndice limite = n;

    do {
        trocou = 0;
        TipoIndice novoLimite = 1;

        for (int i = 1; i < limite; i++) {
            // Acesso sequencial: V[i] e V[i+1]
            if (V[i].Chave > V[i + 1].Chave) {
                TipoItem temp = V[i];
                V[i] = V[i + 1];
                V[i + 1] = temp;

                trocou = 1;
                novoLimite = i; // Reduz o escopo do próximo loop
            }
        }

        limite = novoLimite;
    } while (trocou);
}

//-----SHELLSORT-----

void ShellSortInt(TipoItem *V, TipoIndice n) {
    int h = 1;

    // Geração da sequência de gaps: Knuth (1, 4, 13, 40, ...)
    while (h < n / 3)
        h = 3 * h + 1;

    while (h >= 1) {
        for (int i = h + 1; i <= n; i++) {
            TipoItem temp = V[i];
            int j = i;

            // Inserção com espaçamento h
            while (j > h && temp.Chave < V[j - h].Chave) {
                V[j] = V[j - h];
                j -= h;
            }
            V[j] = temp;
        }
        h = h / 3;
    }
}
