#include<stdio.h>

typedef struct No_A
{
    int valor;
    struct No_A *esquerda;
    struct No_A *direita;
} No_A;

No_A* raiz = NULL;
int y = 0;

int inserir_elemento( int num )
{
    No_A* novo = ( No_A * )malloc(sizeof( No_A ));
    if( novo == NULL )
        return (0);

    novo -> valor = num;
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
        if( x -> valor > num )
        {
            x = x -> esquerda;
        }


        else
        {
            x = x->direita;
        }
    }
    if( pai -> valor > num )
    {
        pai -> esquerda = novo;
    }
    else
    {
        pai -> direita = novo;
    }

    return (1);

}

int Total_de_Folhas( No_A *x )
{
    if( x == NULL )
    {
        return (0);
    }

    if( ( x->esquerda == NULL) && (x->direita == NULL ) )
    {
        return (1);
    }
    return ( Total_de_Folhas( x->esquerda ) + Total_de_Folhas( x -> direita ));
}

int main()
{

    int x;
    for( x = 4; x < 10; x++ )
    {

        inserir_elemento( x+1 );

    }

    int y = Total_de_Folhas( raiz );

    printf("\n Total de folhas da arvore: %i.\n", y);

    return (0);

}
