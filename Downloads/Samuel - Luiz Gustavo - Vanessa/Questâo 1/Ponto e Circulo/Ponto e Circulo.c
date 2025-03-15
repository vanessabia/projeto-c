#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y, raio;
} Circulo;

typedef struct {
    float x, y;
} ponto;


Circulo* cria_circulo(float x, float y, float raio) {
    Circulo *c = (Circulo*) malloc(sizeof(Circulo));
    if (c == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    c->x = x;
    c->y = y;
    c->raio = raio;
    return c;
}

void libera_circulo(Circulo *c) {
    free(c);
}

int ponto_dentro_circulo(Circulo *c, float px, float py) {
    float dx = px - c->x;
    float dy = py - c->y;
    float distancia = dx * dx + dy * dy;
    return distancia <= c->raio * c->raio;
}

ponto* CriarPonto(float x, float y) {
    ponto *novoPonto = (ponto*)malloc(sizeof(ponto));
    if (novoPonto == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    novoPonto->x = x;
    novoPonto->y = y;
    return novoPonto;
}

void LiberaPonto(ponto *p) {
    free(p);
}

void Acessa(ponto *p, float *x, float *y) {
    *x = p->x;
    *y = p->y;
}

void Atribui(ponto *p, float x, float y) {
    p->x = x;
    p->y = y;
}

float Distancia(ponto *p1, ponto *p2) {
    return sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
}

void main(void) {
    Circulo *c = cria_circulo(0, 0, 5);
    
    if (ponto_dentro_circulo(c, 3, 4)) {
        printf("O ponto esta dentro do circulo.\n");
    } else {
        printf("O ponto nao esta dentro do circulo.\n");
    }

    libera_circulo(c);

    // Criando dois pontos
    ponto *p = CriarPonto(2, 5);
    ponto *q = CriarPonto(3, 4);

    Atribui(p, 3, 6);

    printf("A distancia entre os pontos eh: %.2f\n", Distancia(p, q));
    
    LiberaPonto(p);
    LiberaPonto(q);

}

