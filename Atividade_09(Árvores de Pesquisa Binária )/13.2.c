#include<stdio.h>
typedef struct No_A
{
    int valor;
    struct No_A *esquerda;
    struct No_A *direita;
} No_A;

No_A* raiz = NULL;
int y = 0;

int inserir_elemento( int numero )
{
    No_A* novo = ( No_A *)malloc(sizeof(No_A));
    if( novo == NULL )
        return (0);

    novo -> valor = numero;
    novo -> esquerda = novo -> direita = NULL;

    if( raiz == NULL )
    {
        raiz = novo;
        return (1);
    }

    No_A* pai = NULL;
    No_A* x = raiz;
    while( x != NULL )
    {
        pai = x;
        if( x -> valor > numero )
        {
            x = x -> esquerda;
        }

        else
        {
            x = x -> direita;
        }
    }
    if( pai -> valor > numero )
    {
        pai -> esquerda = novo;
    }
    else
    {
        pai -> direita = novo;
    }
    return (1);
}

void nos( No_A *raiz )
{
    y = y + 1;
}

void ordem(No_A *x)
{
    if( x != NULL)
    {

        ordem( x -> esquerda );
        nos( raiz );
        ordem( x -> direita );

    }
}
int main()
{
    int x;
    for(x = 4; x < 10; x++)
    {
        inserir_elemento( x+1 );
    }

    ordem( raiz );

    printf("\n A arvore possui um total de %i nos.\n", y);

    return(0);
}

