/*(3) Escreva uma função que insira um novo elemento em uma lista
encadeada sem cabeça. (Será preciso tomar algumas decisões de
projeto antes de começar a programar.)*/

#include<stdio.h>

    void insere (int x, celula *p)
    {
        celula *nova, *q = ini;
        nova = malloc (sizeof (celula));
        nova->conteudo = x;
        if (p == ini)
        {
            ini = nova;
            ini->prox = p;
        }
        else
        {
            while (q->prox != p)
                q = q->prox;
            nova->prox = q->prox;
            q->prox = nova;
        }
    }

