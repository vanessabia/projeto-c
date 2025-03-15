#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

void inicializarListaDinamica(ListaDinamica *lista) {
    lista->inicio = NULL;
}

void inserirFuncionarioListaDinamica(ListaDinamica *lista, Funcionario f) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) return; 
    novo->funcionario = f;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void imprimirListaDinamica(const ListaDinamica *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        imprimirFuncionario(&atual->funcionario);
        atual = atual->prox;
    }
}

void salvarListaDinamicaEmArquivo(const ListaDinamica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) return;

    No *atual = lista->inicio;
    while (atual != NULL) {
        salvarFuncionarioEmArquivo(arquivo, &atual->funcionario);
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarListaDinamicaDeArquivo(ListaDinamica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) return;

    Funcionario f;
    while (carregarFuncionarioDeArquivo(arquivo, &f)) {
        inserirFuncionarioListaDinamica(lista, f);
    }

    fclose(arquivo);
}

