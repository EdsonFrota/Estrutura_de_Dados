/*(9) Escreva uma função que verifica se duas listas dadas são iguais, ou melhor, se
têm o mesmo conteúdo.*/

#include<stdio.h>
int compara(pessoa *p1, pessoa *p2)
{
    int n = 0;
    pessoa *p,*q;
    q = p2;
    for(p = p1; p->prox != NULL; p = p->prox)
    {
        if(q->num != p->num)
            n++;
        q = q->prox;
    }
    return n;
}
