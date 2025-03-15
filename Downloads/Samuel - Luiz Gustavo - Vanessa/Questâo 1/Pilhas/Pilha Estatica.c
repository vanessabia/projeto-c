#include <stdio.h>
#include <stdlib.h>

#define N 50

typedef struct pilha {
    int n;          
    float vet[N];   
} Pilha;


Pilha* PilhaCria(void) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    p->n = 0;
    return p;
}

int pilha_vazia(Pilha* p) {
    return (p->n == 0);
}

void pilha_push(Pilha* p, float v) {
    if (p->n == N) { 
        printf("A capacidade da pilha esgotou.\n");
        exit(1);
    }
    p->vet[p->n] = v; 
    p->n++;
}

float pilha_pop(Pilha* p) {
    if (pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    float v = p->vet[p->n - 1]; 
    p->n--;
    return v;
}

void imprimir_pilha(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("A pilha esta vazia.\n");
        return;
    }
    printf("\nElementos da pilha (do topo para a base):\n");
    int i;
	for (i = p->n - 1; i >= 0; i--) {
        printf("%.2f\n", p->vet[i]);
    }
}

int main(void) {
    Pilha* p = PilhaCria();

    pilha_push(p, 10.5);
    pilha_push(p, 20.0);
    pilha_push(p, 30.7);
    imprimir_pilha(p);
    
    printf("\nElemento desempilhado: %.2f\n",pilha_pop(p));
	
	imprimir_pilha(p);
	
    free(p);

    return 0;
}

