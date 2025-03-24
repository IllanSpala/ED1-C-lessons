#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    noLista *lista1, *no, *no2, *no3;
    no = criaNoLista(1);
    no2 = criaNoLista (666);
    no3 = criaNoLista (42);
    lista1 = criarLista();
    insereNoLista(&lista1, no);
    insereNoLista(&lista1, no2);
    inserirNoPosicaoX(&lista1, no3, 3);
    imprimeLista(lista1);

    procuraElemento(lista1, 6666); //if return aux (0) VDD
    procuraElementoPosicao(lista1, 5);
    removePosicao(&lista1, 2);
    printf("\n->removendo elemento\n");
    imprimeLista(lista1);

}