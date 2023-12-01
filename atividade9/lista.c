#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

No *criar_no(float valor, No *proximo_no) {
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void inserir_no_finalLista(No *lista, No *no) {
    if (lista == NULL) return;
    if (no == NULL) return;

    No *no_atual = lista;
    while (no_atual->proximo_no != NULL) {
        no_atual = no_atual->proximo_no;
    }

    no_atual->proximo_no = no;
}

void inserir_no_inicioLista(No *lista, No *no) {
    if (lista == NULL) return;
    if (no == NULL) return;

    No *no_copia = criar_no(lista->valor, lista->proximo_no);
    lista->valor = no->valor;
    lista->proximo_no = no_copia;
    
    free(no);
}

void inserir_no_entre_dois_nos(No *no_anterior, No *no) {
    no->proximo_no = no_anterior->proximo_no;
    no_anterior->proximo_no = no;
}

void lista_inserir_no_ordenado(No* lista, No* no) {
    if (no->valor <= lista->valor) {
        inserir_no_inicioLista(lista , no);
    } else {
        while (lista->proximo_no != NULL) {
            if (lista->proximo_no->valor > no->valor) {
                inserir_no_entre_dois_nos(lista, no);
                return;
            }
            lista = lista->proximo_no;
        }
        lista->proximo_no = no;
    }
}

void imprimir_lista(No *lista) {
    if (lista == NULL) return;
    
    while (lista != NULL) {
        printf("%.2f\n", lista->valor);
        lista = lista->proximo_no;
    }
}