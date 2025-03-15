#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    float info;
    struct elemento *prox;
} Elemento;

typedef struct pilha {
    Elemento* prim; 
} Pilha;

Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro ao alocar memoria para a pilha.\n");
        exit(1);
    }
    p->prim = NULL; 
    return p;
}

int pilha_vazia(Pilha* p) {
    return (p->prim == NULL);
}

void pilha_push(Pilha* p, float v) {
    Elemento* n = (Elemento*)malloc(sizeof(Elemento));
    if (n == NULL) {
        printf("Erro ao alocar memoria para o elemento.\n");
        exit(1);
    }
    n->info = v;      	
    n->prox = p->prim; 	
    p->prim = n;     	
}


float pilha_pop(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1); 	
    }
    Elemento* t = p->prim; 
    float v = t->info;     
    p->prim = t->prox;     
    free(t);               
    return v;
}

void imprimir_pilha(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("A pilha est� vazia.\n");
        return;
    }
    Elemento* temp = p->prim;
    printf("Pilha: ");
    while (temp != NULL) {
        printf("%.2f\n", temp->info);
        temp = temp->prox;
    }
    printf("\n");
}

void pilha_libera(Pilha* p) {
    Elemento *t, *q = p->prim;
    while (q != NULL) {
        t = q->prox;
        free(q);
        q = t;
    }
    free(p); 
}

int main(void) {
	
    Pilha* p = pilha_cria();
    
    printf("Empilhando valores na pilha\n");
    pilha_push(p, 10.5);
    pilha_push(p, 8.2);
    pilha_push(p, 2.3);
    
    imprimir_pilha(p);
  
    printf("Desempilhando valores da pilha:\n");
    printf("Valor removido: %.2f\n", pilha_pop(p));
    printf("Valor removido: %.2f\n", pilha_pop(p));
    
    imprimir_pilha(p);

    if (pilha_vazia(p)) {
        printf("A pilha est� vazia.\n");
    } else {
        printf("A pilha nao esta vazia.\n");
    }
    
    pilha_libera(p);
    return 0;
}

