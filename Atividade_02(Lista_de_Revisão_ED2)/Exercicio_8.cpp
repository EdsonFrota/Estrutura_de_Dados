/*(8) Escreva uma função que conta o número de células de uma lista encadeada.*/

#include<stdio.h>
int contar(pessoa *p)
{
    pessoa *run;
    int n;
    while(run->prox != NULL)
    {
        run = run->prox;
        n++;
    }
    return n;
}
