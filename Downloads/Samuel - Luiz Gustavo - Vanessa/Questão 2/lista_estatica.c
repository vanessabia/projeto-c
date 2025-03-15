#include <stdio.h>
#include "lista_estatica.h"

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->tamanho = 0;
}

int inserirFuncionarioListaEstatica(ListaEstatica *lista, Funcionario f) {
    if (lista->tamanho >= TAM_MAX) return 0; 
    lista->funcionarios[lista->tamanho++] = f;
    return 1;
}

void imprimirListaEstatica(const ListaEstatica *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        imprimirFuncionario(&lista->funcionarios[i]);
    }
}

void salvarListaEstaticaEmArquivo(const ListaEstatica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) return;

    for (int i = 0; i < lista->tamanho; i++) {
        salvarFuncionarioEmArquivo(arquivo, &lista->funcionarios[i]);
    }

    fclose(arquivo);
}

void carregarListaEstaticaDeArquivo(ListaEstatica *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) return;

    lista->tamanho = 0;
    while (carregarFuncionarioDeArquivo(arquivo, &lista->funcionarios[lista->tamanho])) {
        lista->tamanho++;
    }

    fclose(arquivo);
}

