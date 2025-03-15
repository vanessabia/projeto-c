#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include "funcionario.h"

typedef struct No {
    Funcionario funcionario;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} ListaDinamica;

void inicializarListaDinamica(ListaDinamica *lista);
void inserirFuncionarioListaDinamica(ListaDinamica *lista, Funcionario f);
void imprimirListaDinamica(const ListaDinamica *lista);
void salvarListaDinamicaEmArquivo(const ListaDinamica *lista, const char *nomeArquivo);
void carregarListaDinamicaDeArquivo(ListaDinamica *lista, const char *nomeArquivo);

#endif

