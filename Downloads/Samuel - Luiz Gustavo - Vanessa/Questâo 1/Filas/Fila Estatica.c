#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TamMax 5

struct TipoPessoa {
    char nome[50];
    char cpf[12];
};

struct TipoFilaEstatica {
    int inicio;
    int fim;
    struct TipoPessoa elementos[TamMax];
};

void InicializarFilaEstatica(struct TipoFilaEstatica* fila) {
    fila->inicio = 0;
    fila->fim = -1; 
}

int FilaEstaticaCheia(struct TipoFilaEstatica* fila) {
    return (fila->fim == TamMax - 1);
}

int FilaEstaticaVazia(struct TipoFilaEstatica* fila) {
    return (fila->inicio > fila->fim);
}

int EnfileirarFilaEstatica(struct TipoFilaEstatica* fila, struct TipoPessoa p) {
    if (FilaEstaticaCheia(fila)) {
        printf("ERRO: Fila Cheia.\n");
        return 0;
    }
    fila->fim++;
    fila->elementos[fila->fim] = p; 
    return 1;
}

int DesenfileirarFilaEstatica(struct TipoFilaEstatica* fila, struct TipoPessoa* p) {
    if (FilaEstaticaVazia(fila)) {
        printf("ERRO: Fila Vazia.\n");
        return 0;
    }
    *p = fila->elementos[fila->inicio];
    fila->inicio++;
    return 1;
}

void ImprimirFilaEstatica(struct TipoFilaEstatica* fila) {
    if (FilaEstaticaVazia(fila)) {
        printf("Fila Vazia.\n");
        return;
    }
    int i;
    for (i = fila->inicio; i <= fila->fim; i++) {
        printf("Nome: %s, CPF: %s\n", fila->elementos[i].nome, fila->elementos[i].cpf);
    }
}

void main() {
    struct TipoFilaEstatica fila;
    InicializarFilaEstatica(&fila);

    struct TipoPessoa p1 = {"Arrascaeta", "12011299800"};
    struct TipoPessoa p2 = {"Bruno Henrique", "13120065491"};
    struct TipoPessoa p3 = {"Gabriel", "13720362481"};
    struct TipoPessoa p4 = {"Gerson", "10122063477"};
    struct TipoPessoa p5 = {"Pedro", "12155500421"};

    EnfileirarFilaEstatica(&fila, p1);
    EnfileirarFilaEstatica(&fila, p2);
    EnfileirarFilaEstatica(&fila, p3);
    EnfileirarFilaEstatica(&fila, p4);
    EnfileirarFilaEstatica(&fila, p5);

    printf("Fila Inicial:\n");
    ImprimirFilaEstatica(&fila);

    printf("\nMovimentando a fila ao desenfileirar:\n");
    struct TipoPessoa desenfileirado;
    while (!FilaEstaticaVazia(&fila)) {
        if (DesenfileirarFilaEstatica(&fila, &desenfileirado)) {
            printf("\nDesenfileirado -> Nome: %s, CPF: %s\n", desenfileirado.nome, desenfileirado.cpf);
            printf("Fila Atual:\n");
            ImprimirFilaEstatica(&fila);
        }
    }
}

