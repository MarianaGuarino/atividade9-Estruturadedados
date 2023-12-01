#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <time.h>

int main(int argc, char *argv[]) {
    FILE *arquivo;
    
    if (argc != 2) {
        printf("Erro de sintaxe!\n");
        exit(1);
    }

    if ((arquivo = fopen(argv[1], "r")) == NULL) {
        printf("Falha ao tentar abrir o arquivo: %s\n", argv[1]);
        exit(2);
    }

    float valor;
    fscanf(arquivo, "%f", &valor);
    No *nao_ordenada = criar_no(valor, NULL);
    No *lista_ordenada = criar_no(valor, NULL);
 
    int count = 0;
    clock_t inicio = clock();
    while (fscanf(arquivo, "%f", &valor) != EOF) {
        printf("N: %d\n", ++count);  
        lista_inserir_no_ordenado(lista_ordenada, criar_no(valor, NULL));
    }
    clock_t fim = clock();
    double tempo = (double) fim - inicio;
    system("cls");
    printf("Tempo: %f\n", tempo);
    system("pause");
    return 0;
}