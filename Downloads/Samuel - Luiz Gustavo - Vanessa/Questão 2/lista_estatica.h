#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#include "funcionario.h"

#define TAM_MAX 100

typedef struct {
    Funcionario funcionarios[TAM_MAX];
    int tamanho;
} ListaEstatica;

void inicializarListaEstatica(ListaEstatica *lista);
int inserirFuncionarioListaEstatica(ListaEstatica *lista, Funcionario f);
void imprimirListaEstatica(const ListaEstatica *lista);
void salvarListaEstaticaEmArquivo(const ListaEstatica *lista, const char *nomeArquivo);
void carregarListaEstaticaDeArquivo(ListaEstatica *lista, const char *nomeArquivo);

#endif

