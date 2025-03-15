#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct {
    float dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int empilhar(Pilha *p, float valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return 0;
    }
    p->dados[++(p->topo)] = valor;
    return 1;
}

int desempilhar(Pilha *p, float *valor) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    *valor = p->dados[(p->topo)--];
    return 1;
}

int ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

float operar(float a, float b, char operador) {
    switch (operador) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default:
            printf("Erro: Operador invalido!\n");
            exit(1);
    }
}

float resolverNPI(char *expressao) {
    Pilha pilha;
    inicializarPilha(&pilha);

    char *token = strtok(expressao, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            
            empilhar(&pilha, atof(token));
        } else if (ehOperador(token[0]) && strlen(token) == 1) {
         
            float b, a;
            desempilhar(&pilha, &b);
            desempilhar(&pilha, &a);
            float resultado = operar(a, b, token[0]);
            empilhar(&pilha, resultado);
        } else {
            printf("Erro: Token invalido '%s'\n", token);
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    float resultadoFinal;
    desempilhar(&pilha, &resultadoFinal);

    if (!pilhaVazia(&pilha)) {
        printf("Erro: Expressao mal formada!\n");
        exit(1);
    }

    return resultadoFinal;
}

int main() {
    char expressao[MAX];
    printf("Digite a expressao em notacao polaca invertida  (separada por espacos): ");
    fgets(expressao, MAX, stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    float resultado = resolverNPI(expressao);
    printf("Resultado: %.2f\n", resultado);

    return 0;
}
