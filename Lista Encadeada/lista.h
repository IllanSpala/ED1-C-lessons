#ifndef LISTA_H
#define LISTA_H

typedef struct noLista
{
    int info; 
    struct noLista *prox;
}noLista;

noLista *criarLista();
int listaVazia(noLista *lista);
void liberaLista(noLista *lista);
void imprimeLista(noLista *lista);
int tamanhoLista(noLista *lista);
noLista *criaNoLista(int info);
void insereNoLista(noLista **lista, noLista *novoNo);
noLista *procuraElemento(noLista *lista, int valor);
noLista *procuraElementoPosicao(noLista *lista, int posicao);
int inserirNoPosicaoX(noLista **lista, noLista *novoNo, int posicao);
#endif