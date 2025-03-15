#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct {
    int id;
    char nome[50];
    char cargo[50];
    float salario;
} Funcionario;

// Funções auxiliares
void imprimirFuncionario(const Funcionario *f);
void salvarFuncionarioEmArquivo(FILE *arquivo, const Funcionario *f);
int carregarFuncionarioDeArquivo(FILE *arquivo, Funcionario *f);

#endif
#include <stdio.h>
#include "funcionario.h"

void imprimirFuncionario(const Funcionario *f) {
    printf("ID: %d, Nome: %s, Cargo: %s, Salario: %.2f\n", f->id, f->nome, f->cargo, f->salario);
}

void salvarFuncionarioEmArquivo(FILE *arquivo, const Funcionario *f) {
    fprintf(arquivo, "%d,%s,%s,%.2f\n", f->id, f->nome, f->cargo, f->salario);
}

int carregarFuncionarioDeArquivo(FILE *arquivo, Funcionario *f) {
    return fscanf(arquivo, "%d,%49[^,],%49[^,],%f\n", &f->id, f->nome, f->cargo, &f->salario);
}

