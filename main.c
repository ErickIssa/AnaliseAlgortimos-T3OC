#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

int main() {
    FILE *arquivo;
    TipoItem vetor[MAXTAM];
    int i = 0;

    // Abre o arquivo para leitura
    arquivo = fopen("numeros10000.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê até MAXTAM números
    while (i < MAXTAM && fscanf(arquivo, "%d", &vetor[i].Chave) == 1) {
        i++;
    }

    fclose(arquivo);
    //BubbleSortInt(vetor,i);
    //RadixsortInt(vetor,i);
    //QuickSortInt(vetor,i);
    //ShellSortInt(vetor,i);
    BubbleSortCacheOptimized(vetor,i);
    Imprime(vetor,i);

    return 0;
}