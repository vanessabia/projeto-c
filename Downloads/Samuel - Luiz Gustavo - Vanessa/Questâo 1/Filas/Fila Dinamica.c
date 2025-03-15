#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TipoPessoa {
    char nome[50];
    char cpf[12];
};

struct No {
    struct TipoPessoa pessoa;
    struct No* prox; 
};

struct TipoFilaDinamica {
    struct No* inicio; 
    struct No* fim;    
};

void InicializarFilaDinamica(struct TipoFilaDinamica* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int FilaDinamicaVazia(struct TipoFilaDinamica* fila) {
    return (fila->inicio == NULL);
}

int EnfileirarFilaDinamica(struct TipoFilaDinamica* fila, struct TipoPessoa p) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0;
    }
    novo->pessoa = p;
    novo->prox = NULL; 

    if (FilaDinamicaVazia(fila)) {
        fila->inicio = novo; 
    } else {
        fila->fim->prox = novo; 
    }
    fila->fim = novo; 
    return 1;
}

int DesenfileirarFilaDinamica(struct TipoFilaDinamica* fila, struct TipoPessoa* p) {
    if (FilaDinamicaVazia(fila)) {
        printf("ERRO: Fila Vazia.\n");
        return 0;
    }
    struct No* temp = fila->inicio; 
    *p = temp->pessoa;             
    fila->inicio = temp->prox;     
    if (fila->inicio == NULL) {    
        fila->fim = NULL;
    }
    free(temp); 
    return 1;
}

void ImprimirFilaDinamica(struct TipoFilaDinamica* fila) {
    if (FilaDinamicaVazia(fila)) {
        printf("Fila Vazia.\n");
        return;
    }
    struct No* atual = fila->inicio;
    while (atual != NULL) {
        printf("Nome: %s, CPF: %s\n", atual->pessoa.nome, atual->pessoa.cpf);
        atual = atual->prox;
    }
}

int main() {
    struct TipoFilaDinamica fila;
    InicializarFilaDinamica(&fila);

    struct TipoPessoa p1 = {"Arrascaeta", "12011299800"};
    struct TipoPessoa p2 = {"Bruno Henrique", "13120065491"};
    struct TipoPessoa p3 = {"Gabriel", "13720362481"};
    struct TipoPessoa p4 = {"Gerson", "10122063477"};
    struct TipoPessoa p5 = {"Pedro", "12155500421"};

    EnfileirarFilaDinamica(&fila, p1);
    EnfileirarFilaDinamica(&fila, p2);
    EnfileirarFilaDinamica(&fila, p3);
    EnfileirarFilaDinamica(&fila, p4);
    EnfileirarFilaDinamica(&fila, p5);

    printf("Fila Inicial:\n");
    ImprimirFilaDinamica(&fila);

    printf("\nMovimentando a fila ao desenfileirar:\n");
    struct TipoPessoa desenfileirado;
    while (!FilaDinamicaVazia(&fila)) {
        if (DesenfileirarFilaDinamica(&fila, &desenfileirado)) {
            printf("\nDesenfileirado -> Nome: %s, CPF: %s\n", desenfileirado.nome, desenfileirado.cpf);
            printf("Fila Atual:\n");
            ImprimirFilaDinamica(&fila);
        }
    }

    return 0;
}

