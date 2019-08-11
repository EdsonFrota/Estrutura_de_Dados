#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No
{

    int valor;
    struct No *direita;
    struct No *esquerda;

} No;

No *raiz = NULL;


int inserir(int numero)
{

    No* novo = (No *)malloc(sizeof(No));
    if(novo == NULL)
    {
        return (0);
    }


    novo -> valor = numero;
    novo -> esquerda = novo -> direita = NULL;

    if(raiz == NULL)
    {
        raiz = novo;
        return (1);
    }

    No* pai = NULL;
    No* x = raiz;

    while(x != NULL)
    {
        pai = x;
        if(x -> valor > numero)
        {
            x = x -> esquerda;
        }


        else
        {
            x = x -> direita;
        }

    }
    if(pai -> valor > numero)
    {
        pai -> esquerda = novo;
    }

    else
    {
        pai -> direita = novo;
    }


    return (1);

}

No* buscar(int n)
{
    No* x = raiz;
    while(x != NULL)
    {
        if(x -> valor == n)
        {
            return (x);
        }
        if(x -> valor > n)
        {
            x = x -> esquerda;
        }
        else
        {
            x = x -> direita;
        }
    }
    return (NULL);
}

int eliminar(int n)
{

    if(raiz == NULL)
        return (0);


    No* noEliminado = raiz;
    No* paiNoEliminado = NULL;
    while(noEliminado != NULL && noEliminado -> valor != n)
    {
        paiNoEliminado = noEliminado;
        if(noEliminado -> valor > n)
        {
            noEliminado = noEliminado -> esquerda;
        }
        else
        {
            noEliminado = noEliminado -> direita;
        }
    }


    if(noEliminado == NULL)
    {
        return (0);
    }


    No* paiSubstituto = NULL;
    No* noSubstituto = NULL;
    if(noEliminado -> direita != NULL)
    {
        paiSubstituto = noEliminado;
        noSubstituto = noEliminado -> direita;
        while(noSubstituto -> esquerda != NULL)
        {
            paiSubstituto = noSubstituto;
            noSubstituto = noSubstituto -> esquerda;
        }
    }
    else
    {
        if(noEliminado -> esquerda != NULL)
        {
            paiSubstituto = noEliminado;
            noSubstituto = noEliminado -> esquerda;
            while(noSubstituto -> direita != NULL)
            {
                paiSubstituto = noSubstituto;
                noSubstituto = noSubstituto -> direita;
            }
        }
    }


    if(noSubstituto == NULL)
    {
        if(noEliminado == raiz)
            raiz = NULL;

        if(paiNoEliminado != NULL)
        {
            if(paiNoEliminado -> direita == noEliminado)
                paiNoEliminado -> direita = NULL;
            else
                paiNoEliminado -> esquerda = NULL;
        }
        free(noEliminado);
        return (1);
    }


    if(paiSubstituto != NULL)
    {
        if(paiSubstituto -> direita == noSubstituto)
            paiSubstituto -> direita = noSubstituto -> direita;
        else
            paiSubstituto -> esquerda = noSubstituto -> esquerda;
    }
    noEliminado -> valor = noSubstituto -> valor;
    free(noSubstituto);
    return (1);
}
int main()
{

    setlocale(LC_ALL, "Portuguese");
    int opcao, elemento, elemento_removido, elemento_pesquisado;

    do
    {

        printf(" DIGITE UMA OPÇÃO: ");
        printf("\n1 - INSERIR UM ELEMENTO");
        printf("\n2 - REMOVER UM ELEMENTO");
        printf("\n3 - PESQUISAR UM VALOR");
        printf("\n4 - SAIR");
        printf("\n");
        scanf("%i", &opcao);

        system("cls");

        switch(opcao)
        {

        case 1:
            printf("----------INSERIR ELEMENTO----------");
            printf("\nElemento a ser inserido: ");
            scanf("%i", &elemento);
            inserir(elemento);
            printf("--------------------------\n");
            break;

        case 2:
            printf("----------REMOVER ELEMENTO---------");
            printf("\nElemento a ser removido: ");
            scanf("%i", &elemento_removido);
            eliminar(elemento_removido);
            if(eliminar(elemento_removido) == 0)
            {
                printf(" \nO Número %i não foi encontrado na árvore\n ",elemento);
            }
            else
            {
                printf(" \nO Número %i foi encontrado e eliminado da árvore\n ",elemento);
            }

            break;

        case 3:
            printf("----------PESQUISAR ELEMENTO----------");
            printf("\nElemento a ser pesquisado: ");
            scanf("%i", &elemento_pesquisado);
            buscar(elemento_pesquisado);
            if(buscar(elemento_pesquisado) == NULL )
            {
                printf(" \nO elemento %i se encontra na árvore\n ",elemento);
            }
            else
            {
                printf(" \nO elemento %ise encontra na árvore\n ",elemento);
            }

            break;

        }
    }
    while( opcao != 4 );

    return (0);
}
