/*(6) Escreva uma função que faça uma cópia de uma lista dada como parâmetro e
retorne a nova lista.*/

#include<stdio.h>

pessoa copiar(pessoa *lista1, pessoa *lista2)
{
    pessoa *p,*q;
    q = lista2;
    for(p = lista1; p->prox != NULL; p = p->prox)
    {
        q->num = p->num;
        q = q->prox;
    }
}
