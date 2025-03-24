#include "fila.h"
#include "../lista/lista.h"


void criaFila(fila* fila){
    if(fila != NULL ){
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
}

int filaVazia(fila* fila){
    if(fila->primeiro == NULL){
        return 1;
    }else{
        return 0;
    }
}

void colocarFila(fila* fila, int valor){
    node *no = criaNode(valor);
    if(filaVazia(fila) == 1){
        fila->primeiro = no;
        fila ->ultimo = no;
    }else{
        node *aux = fila->ultimo;
        aux->prox = no;
        fila->ultimo = no;
    }
}

int removeFila(fila* fila){
    node *aux = fila->primeiro;
    if(aux == NULL) return -1;
    fila->primeiro = fila->primeiro->prox;
    printf("\naux: %d", aux->info);
    int valor = aux->info;
    free(aux);
    return valor;
}

void deletaFila(fila* fila){
    while(fila->primeiro!=NULL){
        removeFila(fila);
    }
    if (filaVazia(fila)) printf("fila deletada!");
}

int primeiroElemFila(fila* fila){
    return fila->primeiro !=NULL ? fila->primeiro->info : -1;
}

void imprimeFila(fila* fila){
    node *aux = fila->primeiro;
    while(aux != NULL){
        printf("%d", aux->info);
        aux = aux->prox;
    }
}