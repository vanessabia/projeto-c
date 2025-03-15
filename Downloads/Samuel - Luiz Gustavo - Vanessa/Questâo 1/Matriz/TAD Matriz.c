#include <stdio.h>
#include <conio.h>
const int tam = 16;

void zerarMatriz(int *vet){
    int k,j;
    for(k=1;k<=tam/4;k++){
        for(j=1;j<=tam/4;j++){
            adicionaElemento(vet,0,k,j);
        }
    }
}

void adicionaElemento(int *vetor, int numero, int linha, int coluna){
    vetor[(linha-1)*(tam/4)+coluna-1] = numero;
}

int buscaElemento(int *vet, int linha, int coluna){
    return vet[((linha-1)*(tam/4))+coluna-1];
}

void imprimirMatriz_zerada(int *vet, int linha, int coluna){
    int k,j;
     for(k=1;k<=linha;k++){
        for(j=1;j<=coluna;j++){
            printf("%d  ", buscaElemento(vet,k,j));
        }
        printf("\n");
     }
     printf("\n");
}

void imprimirMatriz(int *vet, int linha, int coluna){
    int k,j;
    for(k=1;k<=linha;k++){
        for(j=1;j<=coluna;j++){
            printf("%d ", buscaElemento(vet,k,j));
        }
        printf("\n");
    }
    printf("\n");
}

void main(){
	int matriz[tam];

    zerarMatriz(matriz);
    printf("Matriz Zerada:\n");
    imprimirMatriz_zerada(matriz, tam / 4, tam / 4);

    printf("Preenchendo a matriz com valores...\n");
    int contador = 1;
    int i,j;
    for (i = 1; i <= tam / 4; i++) {
        for (j = 1; j <= tam / 4; j++) {
            adicionaElemento(matriz, contador++, i, j);
        }
    }

    printf("Matriz Preenchida:\n");
    imprimirMatriz(matriz, tam / 4, tam / 4);

    int linha = 2, coluna = 3;
    printf("Elemento na posicao (%d, %d): %d\n", linha, coluna, buscaElemento(matriz, linha, coluna));
}
