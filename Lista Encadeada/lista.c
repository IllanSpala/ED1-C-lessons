#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

noLista *criarLista() {
    return NULL;
}

int listaVazia(noLista *lista) {
    if (lista == NULL) {
        return 1;
    }
    return 0;
}

void liberaLista(noLista *lista) {
    noLista *aux;
    while (lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

void imprimeLista(noLista *lista){
    noLista *aux = lista;
    printf("lista: ");
    while (aux != NULL){
        printf(" %d ->",aux->info);
        aux = aux->prox;
    }
}

int tamanhoLista(noLista *lista){
    int i;
    noLista *aux;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

noLista *criaNoLista(int info){
    noLista *no;
    no = malloc(sizeof(noLista));
    no->info = info;
    no->prox = NULL;
    return no;
}

void insereNoLista(noLista **lista, noLista *novoNo){
    noLista *aux;
    aux = *lista;
    if(*lista == NULL){
        *lista = novoNo;
    }
    else{
        while(aux->prox != NULL){
            aux = aux->prox;            
        }
         aux->prox = novoNo;
    }
}

noLista *procuraElemento(noLista *lista, int valor){
    noLista *aux = lista;
    if(listaVazia(lista) == 0){

        while (aux != NULL){
            if (aux->info == valor){
                return aux;
             }
            if (aux->prox != NULL){
                aux = aux->prox;
            }else{
                break;
            }
        }
    printf("\n->elemento não encontrado!");
    return NULL;
    }
        else{   
            printf("lista vazia");
         }
}

noLista *procuraElementoPosicao(noLista *lista, int posicao){
        if(listaVazia(lista) == 1){
            printf("Lista vazia\n");
            return NULL;
        }else{
            noLista *aux = lista;
            if(posicao>0){
                for(int i = 1; i < posicao; i++){
                    if(aux->prox != NULL){
                        aux = aux -> prox;
                    }else{
                        printf("\n->posicao nao existe ainda porra");
                        return NULL;
                    }
                }
            return aux;
            }else{
                return NULL;
            }
        }
}

int inserirNoPosicaoX(noLista **lista, noLista *novoNo, int posicao){
    noLista *aux1 = procuraElementoPosicao(*lista, posicao), *aux2 = procuraElementoPosicao(*lista, posicao -1);
    
    if(aux2 == NULL){
        *lista = novoNo;
        novoNo->prox = aux1;
        return 1;
    }else{
        if(aux1 != NULL){
            aux2->prox = novoNo;
            novoNo->prox = aux1;
            return 1;
        }if(aux1 == NULL){
            insereNoLista(lista, novoNo);
        }
    }
    return 0;
}

noLista *removePosicao(noLista **lista, int posicao){
    noLista *aux1 = procuraElementoPosicao(*lista, posicao -1);
    noLista *escolhaDel = procuraElementoPosicao(*lista, posicao);
    noLista *aux2 = procuraElementoPosicao(*lista, posicao+1);

    if(posicao == 1){
        *lista = aux2;
        return aux2;
    }

    aux1->prox = aux2;
    return escolhaDel;
}