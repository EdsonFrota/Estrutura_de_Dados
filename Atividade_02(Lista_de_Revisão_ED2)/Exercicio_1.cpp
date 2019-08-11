/*(1) Escreva uma versão da função busca para listas sem cabeça.*/

#include<stdio.h>

    busca(int x, celula *inicio)
    {
        celula*p;
        p = inicio;
        while(p != NULL && p->conteudo !x)
        {
            p = p->prox;
            return(p);
        }
    }


