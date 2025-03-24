#ifndef LISTA_H
#define LISTA_H

typedef struct noFila
{
    int info; 
    struct noFila *prox;
}node;

node *criarLista();
int listaVazia(node *lista);
void liberaLista(node *lista);
void imprimeLista(node *lista);
int tamanhoLista(node *lista);
node *criaNode(int info);
void insereNode(node **lista, node *novoNo);
node *procuraElemento(node *lista, int valor);
node *procuraElementoPosicao(node *lista, int posicao);
node *removePosicao(node **lista, int posicao);
int inserirNoPosicaoX(node **lista, node *novoNo, int posicao);
#endif