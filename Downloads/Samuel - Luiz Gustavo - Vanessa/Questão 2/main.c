#include <stdio.h>
#include "lista_estatica.h"
#include "lista_dinamica.h"

int main() {
    ListaEstatica listaEstatica;
    ListaDinamica listaDinamica;

    inicializarListaEstatica(&listaEstatica);
    inicializarListaDinamica(&listaDinamica);

    Funcionario f1 = {1, "João", "Gerente", 5000.00};
    Funcionario f2 = {2, "Maria", "Analista", 4000.00};

    inserirFuncionarioListaEstatica(&listaEstatica, f1);
    inserirFuncionarioListaEstatica(&listaEstatica, f2);

    inserirFuncionarioListaDinamica(&listaDinamica, f1);
    inserirFuncionarioListaDinamica(&listaDinamica, f2);

    printf("Lista Estática:\n");
    imprimirListaEstatica(&listaEstatica);

    printf("\nLista Dinâmica:\n");
    imprimirListaDinamica(&listaDinamica);

    salvarListaEstaticaEmArquivo(&listaEstatica, "lista_estatica.csv");
    salvarListaDinamicaEmArquivo(&listaDinamica, "lista_dinamica.csv");

    return 0;
}

