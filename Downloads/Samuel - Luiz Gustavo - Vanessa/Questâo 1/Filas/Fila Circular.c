#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TamMax 5
struct TipoPessoa{
	char nome[50];
	char cpf[12];
};

struct TipoFilaCircular{
	int inicio;
	int fim;
	int qntd;
	struct TipoPessoa elementos[TamMax];
};

void InicializarFilaCircular(struct TipoFilaCircular* fila){
	fila->inicio = 0;
	fila->fim = -1;
	fila->qntd = 0;
}


int FilaCircularCheia(struct TipoFilaCircular* fila){
	return (fila->qntd == TamMax);
}

int FilaCircularVazia(struct TipoFilaCircular* fila){
	return (fila->qntd == 0);
}

int EnfileirarFilaCircular(struct TipoFilaCircular* fila, struct TipoPessoa p){
	if(fila->qntd == TamMax){
		printf("ERRO: Fila Cheia.\n");
		return 0;
	}
	if(fila->fim + 1 == TamMax){
		fila->fim = 0;
	}
	else{
		fila->fim ++;	
	}
	fila->elementos[fila->fim] = p;
	fila-> qntd ++;
	return 1;
}

int DesenfileirarFilaCircular(struct TipoFilaCircular* fila, struct TipoPessoa* p) {
    if (FilaCircularVazia(fila)) {
        printf("ERRO: Fila Vazia.\n");
        return 0;
    }
    *p = fila->elementos[fila->inicio]; 
    if (fila->inicio + 1 == TamMax) {
        fila->inicio = 0; 
    } else {
        fila->inicio++;
    }
    fila->qntd--;
    return 1; 
}

void imprimirFilaCircular(struct TipoFilaCircular* fila) {
    if (FilaCircularVazia(fila)) {
        printf("Fila Vazia.\n");
        return;
    }
    int i = fila->inicio;
    int k;
    for (k = 0; k < fila->qntd; k++) {
        printf("Nome: %s, CPF: %s\n", fila->elementos[i].nome, fila->elementos[i].cpf);
        i = (i + 1) % TamMax; 
    }
}

void main(){
	
	struct TipoFilaCircular fila;
	InicializarFilaCircular(&fila);

    struct TipoPessoa p1 = {"Arrascaeta", "12011299800"};
    struct TipoPessoa p2 = {"Bruno Henrique", "13120065491"};
    struct TipoPessoa p3 = {"Gabriel", "13720362481"};
    struct TipoPessoa p4 = {"Gerson", "10122063477"};
    struct TipoPessoa p5 = {"Pedro", "12155500421"};
    
    EnfileirarFilaCircular(&fila, p1);
    EnfileirarFilaCircular(&fila, p2);
    EnfileirarFilaCircular(&fila, p3);
    EnfileirarFilaCircular(&fila, p4);
    EnfileirarFilaCircular(&fila, p5);
    
    printf("Fila:\n");
    imprimirFilaCircular(&fila);
    
       printf("\nMovimentando a fila ao desenfileirar:\n");
    struct TipoPessoa desenfileirado;
    while (!FilaCircularVazia(&fila)) {
        if (DesenfileirarFilaCircular(&fila, &desenfileirado)) {
            printf("\nDesenfileirado -> Nome: %s, CPF: %s\n", desenfileirado.nome, desenfileirado.cpf);
        	printf("Fila atual:\n");
			imprimirFilaCircular(&fila);
		}
    }
}


