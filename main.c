#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

int main() {
    FILE *arquivo;
    TipoItem vetor[MAXTAM];
    int i = 0;
    int opcao_ordenacao, opcao_tamanho;
    char *nome_arquivo;

    // Menu para escolher o tamanho do conjunto de dados
    printf("Escolha o tamanho do conjunto de dados:\n");
    printf("1 - 1.000 números (numeros1000.txt)\n");
    printf("2 - 10.000 números (numeros10000.txt)\n");
    printf("Opção: ");
    scanf("%d", &opcao_tamanho);

    // Define o arquivo com base na escolha
    if (opcao_tamanho == 1) {
        nome_arquivo = "numeros1000.txt";
    } else if (opcao_tamanho == 2) {
        nome_arquivo = "numeros10000.txt";
    } else {
        printf("Opção inválida! Usando 'numeros10000.txt' por padrão.\n");
        nome_arquivo = "numeros10000.txt";
    }

    // Abre o arquivo para leitura
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê os números do arquivo
    while (i < MAXTAM && fscanf(arquivo, "%d", &vetor[i].Chave) == 1) {
        i++;
    }
    fclose(arquivo);

    // Menu para escolher o método de ordenação
    printf("\nEscolha o método de ordenação:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Radix Sort\n");
    printf("3 - Quick Sort\n");
    printf("4 - Shell Sort\n");
    printf("5 - Bubble Sort (Cache Optimized)\n");
    printf("Opção: ");
    scanf("%d", &opcao_ordenacao);

    // Executa a ordenação selecionada
    switch(opcao_ordenacao) {
        case 1:
            BubbleSortInt(vetor, i);
            break;
        case 2:
            RadixsortInt(vetor, i);
            break;
        case 3:
            QuickSortInt(vetor, i);
            break;
        case 4:
            ShellSortInt(vetor, i);
            break;
        case 5:
            BubbleSortCacheOptimized(vetor, i);
            break;
        default:
            printf("Opção inválida! Nenhuma ordenação foi aplicada.\n");
    }

    // Exibe os resultados
    printf("\nOrdenação concluída. %d números processados.\n", i);
    Imprime(vetor, i);

    return 0;
}