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

int Maior(int a, int b)
{
    if(a > b)
    {
        return (a);
    }
    else
    {
        return b;
    }

}

int Altura_Arvore(No_A *p)
{
    if((p == NULL) || (p->esquerda == NULL && p->direita == NULL))
    {
        return (0);
    }
    else
    {
        return (1 + maior(altura(p->esquerda), altura(p->direita)));
    }
}

int main()
{

    int x;
    for(x = 4; x < 10; x++)
    {

        inserir( x + 1 );

    }

    y = Altura_Arvore( raiz );;

    printf("\n Altura da arvore: %i.\n", y);

}
