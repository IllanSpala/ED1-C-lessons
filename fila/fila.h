#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>
#include "../lista\lista.h"

typedef struct fila{
    node* primeiro;
    node* ultimo;
}fila;

void criaFila(fila* fila);

int filaVazia(fila* fila);

void colocarFila(fila* fila, int valor);

int removeFila(fila* fila);

int primeiroElemFila(fila* fila);

void imprimeFila(fila* fila);

void deletaFila(fila* fila);

#endif