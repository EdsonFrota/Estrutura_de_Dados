/*(10) Escreva uma função que inverte a ordem das células de uma lista encadeada
(a primeira célula passa a ser a última, a segunda passa a ser a penúltima etc.).
Faça isso sem usar espaço auxiliar; apenas altere os ponteiros.*/

#include<stdio.h>
void inverte(pessoa *p)
{
    pessoa *aux1, *aux2;
    aux1 = p;
    aux2 = p->prox;
    while(aux2->prox != NULL)
    {
        aux1->prox = aux1;
        aux1 = aux2;
        aux2 = aux2->prox;
    }
    p = aux2;
}
