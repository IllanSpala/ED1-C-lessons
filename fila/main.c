#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    fila* minhaFila = (fila*)malloc(sizeof(fila));
    criaFila(minhaFila);

    // Adding elements to queue
    colocarFila(minhaFila, 666);
    colocarFila(minhaFila, 10);
    colocarFila(minhaFila, 78);

    // Printing queue
    printf("Queue elements: ");
    imprimeFila(minhaFila);
    printf("\n");

    // Removing an element
    int removedValue = removeFila(minhaFila);
    printf("Removed value: %d\n", removedValue);

    // Printing queue after removal
    printf("Queue after removal: ");
    imprimeFila(minhaFila);
    printf("\n");

    // Getting first element
    printf("First element: %d\n", primeiroElemFila(minhaFila));

    // Deleting queue
    deletaFila(minhaFila);
    free(minhaFila);

    return 0;
}