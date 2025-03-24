#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    node *lista1, *no, *no2, *no3;
    no = criaNode(1);
    no2 = criaNode (666);
    no3 = criaNode (42);
    lista1 = criarLista();
    insereNode(&lista1, no);
    insereNode(&lista1, no2);
    inserirNoPosicaoX(&lista1, no3, 3);
    printf("\n");
    imprimeLista(lista1);
    
    procuraElemento(lista1, 6666); //if return aux (0) VDD
    procuraElementoPosicao(lista1, 5);
    removePosicao(&lista1, 2);
    printf("\n->removendo elemento\n");
    imprimeLista(lista1);

}