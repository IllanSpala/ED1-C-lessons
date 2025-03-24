#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

node *criarLista() {
    return NULL;
}

int listaVazia(node *lista) {
    if (lista == NULL) {
        return 1;
    }
    return 0;
}

void liberaLista(node *lista) {
    node *aux;
    while (lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

void imprimeLista(node *lista){
    node *aux = lista;
    printf("lista: ");
    while (aux != NULL){
        printf(" %d ->",aux->info);
        aux = aux->prox;
    }
}

int tamanhoLista(node *lista){
    int i;
    node *aux;
    while(aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

node *criaNode(int info){
    node *no;
    no = malloc(sizeof(node));
    no->info = info;
    no->prox = NULL;
    return no;
}

void insereNode(node **lista, node *novoNo){
    node *aux;
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

node *procuraElemento(node *lista, int valor){
    node *aux = lista;
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
         return 0;
}

node *procuraElementoPosicao(node *lista, int posicao){
        if(listaVazia(lista) == 1){
            printf("Lista vazia\n");
            return NULL;
        }else{
            node *aux = lista;
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

int inserirNoPosicaoX(node **lista, node *novoNo, int posicao){
    node *aux1 = procuraElementoPosicao(*lista, posicao), *aux2 = procuraElementoPosicao(*lista, posicao -1);
    
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
            insereNode(lista, novoNo);
        }
    }
    return 0;
}

node *removePosicao(node **lista, int posicao){
    node *aux1 = procuraElementoPosicao(*lista, posicao -1);
    node *escolhaDel = procuraElementoPosicao(*lista, posicao);
    node *aux2 = procuraElementoPosicao(*lista, posicao+1);

    if(posicao == 1){
        *lista = aux2;
        return aux2;
    }

    aux1->prox = aux2;
    return escolhaDel;
}