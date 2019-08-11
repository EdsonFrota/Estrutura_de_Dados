 /*Uma lista encadeada circular é uma lista encadeada cujo último elemento aponta para o
primeiro:

Vantagem: cada elemento é acessível a partir de qualquer outro. Numa lista circular,
não faz mais sentido se falar em primeiro ou último elemento. Porém, devemos saber,
durante um percurso na lista, se já demos uma volta completa, para evitarmos loops
infinitos. Para isso, assumimos a existência de um registro especial, chamado Cabeça
de Lista, cujo campo de informação não pertence ao conjunto de elementos da lista
(poderia até servir de sentinela numa busca):

Situação lista circular vazia:

Construa algoritmos para:
a. Contar o número de elementos numa lista circular;
b. Inserir um elemento à esquerda da cabeça da lista;
c. Eliminar o elemento de valor x;
d. Concatenar duas listas circulares;

e. Intercalar duas listas ordenadas;
f. Fazer uma cópia da lista;/*/

#include<stdio.h>

struct ListaC
{
    int data;
    struct ListaC *prox;
};

typedef struct ListaC listac;

listac* cria(int data)
{
    listac* retorno = (listac*) malloc(sizeof(listac));
    retorno->data = data;
    retorno->prox = retorno;
    return retorno;
}

void escreve(listac* lista)
{

    if(lista == NULL)

    {

        printf("Lista vazia!");

        return;

    }

    listac* loop = lista;

    void insere(listac* lista, int data)
    {

        if(lista == NULL) return;

        listac* loop;

        for(loop = lista; loop->prox != lista; loop = loop->prox);

        loop = loop->prox = (listac*) malloc(sizeof(listac));

        loop->data = data;

        loop->prox = lista;

    }
