#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#define MAXTAM 10000
#define NBITS 32
#define M 4
#define BASE (1 << M)

// typedef int TipoChave; // Não está sendo usado

typedef int TipoIndice;

typedef struct {
    int Chave;
} TipoItem;

extern TipoItem B[MAXTAM + 1]; // buffer auxiliar global
extern int C[BASE];            // contador global

//imprime geral
void Imprime(TipoItem *V, TipoIndice n);
//radix
int GetBits(int chave, int desloc, int tam);
void ContagemInt(TipoItem *A, TipoIndice n, int Pass);
void RadixsortInt(TipoItem *A, TipoIndice n);
void ImprimeRadix(TipoItem *V, TipoIndice n);
void TestaRadix(TipoItem *V, TipoIndice n);
//bubblesort
void BubbleSortInt(TipoItem *V, TipoIndice n);
//quicksort
void Troca(TipoItem *a, TipoItem *b);
int Particao(TipoItem *A, int esq, int dir);
void QuickSortRecursivo(TipoItem *A, int esq, int dir);
void QuickSortInt(TipoItem *A, TipoIndice n);
//bubbleSortOptimized
void BubbleSortCacheOptimized(TipoItem *V, TipoIndice n);
//SHELLSORT
void ShellSortInt(TipoItem *V, TipoIndice n);

#endif
