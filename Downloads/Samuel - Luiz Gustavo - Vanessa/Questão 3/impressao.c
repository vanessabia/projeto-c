#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  

typedef struct {
    int prioridade;  
    int id;        
} Requisicao;


typedef struct {
    Requisicao fila[MAX_SIZE];  
    int inicio;                 
    int fim;                    
    int tamanho;                
} Fila;

Fila *CriarFila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    return fila;
}

void RemoverFila(Fila *fila) {
    if (fila->tamanho == 0) {
        printf("\nA fila esta vazia!\n");
        return;
    }

    printf("\nRequisicao do usuario %d removida da fila.\n", fila->fila[fila->inicio].id);
    fila->inicio = (fila->inicio + 1) % MAX_SIZE;  
    fila->tamanho--;  
}

void AdicionarFila(Fila *fila, int id, int prioridade) {
    if (fila->tamanho == MAX_SIZE) {
        printf("\nFila cheia! Nao e possivel adicionar mais requisicoes.\n");
        return;
    }

    Requisicao novaRequisicao;
    novaRequisicao.id = id;
    novaRequisicao.prioridade = prioridade;

    int i = fila->fim - 1;
    while (i >= fila->inicio && fila->fila[i].prioridade > prioridade) {
        fila->fila[(i + 1) % MAX_SIZE] = fila->fila[i];  
        i = (i - 1 + MAX_SIZE) % MAX_SIZE;
    }

    fila->fila[(i + 1) % MAX_SIZE] = novaRequisicao;  
    fila->fim = (fila->fim + 1) % MAX_SIZE; 
    fila->tamanho++; 
    printf("\nRequisicao do usuario %d com prioridade %d adicionada a fila.\n", id, prioridade);
}

void ImprimirFila(Fila *fila) {
    if (fila->tamanho == 0) {
        printf("\nA fila esta vazia!\n");
        return;
    }

    printf("\nFila de requisicoes:\n");
    int i = fila->inicio;
    for (int j = 0; j < fila->tamanho; j++) {
        printf("Usuario %d, Prioridade %d\n", fila->fila[i].id, fila->fila[i].prioridade);
        i = (i + 1) % MAX_SIZE;
    }
}

int main() {
    Fila *fila = CriarFila();  

    int opcao;
    do {
        printf("\n========= MENU =========\n");
        printf("1 - Adicionar impressao\n");
        printf("2 - Remover impressao\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int num, prioridade;
                printf("\nInforme o Numero do usuario: ");
                scanf("%d", &num);
                printf("Informe a prioridade (1 - Diretor, 2 - Coordenador, 3 - Funcionario): ");
                scanf("%d", &prioridade);
                AdicionarFila(fila, num, prioridade);
                break;
            }
            case 2:
                RemoverFila(fila);
                break;
            case 3:
                ImprimirFila(fila);
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    free(fila);  
    return 0;
}