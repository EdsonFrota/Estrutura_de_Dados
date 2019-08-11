/* Considerando listas de valores inteiros, implemente uma função que receba como
parâmetro uma lista encadeada e um valor inteiro n, e divida a lista em duas, de tal forma
que a segunda lista comece no primeiro nó logo após a primeira ocorrência de n na lista
original. A figura a seguir ilustra essa separação:

Essa função deve obedecer ao protótipo:

Lista* separa (Lista* l, int n);

A função deve retornar um ponteiro para a segunda subdivisão da lista original, enquanto l
deve continuar apontando para o primeiro elemento da primeira subdivisão da lista.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

Lista *separa (Lista *l, int n)
{
    Lista *p; /* variável auxiliar para percorrer a lista */
    Lista *q; /* variável auxiliar para nova lista */
    for (p = l; p != NULL ; p = p->prox)
        if (p->info == n)
        {
            q = p->prox;
            p->prox = NULL;
            return q;
        }
    return NULL;
}
