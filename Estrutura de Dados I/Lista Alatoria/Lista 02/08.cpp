 /*Escreva uma função que concatene duas listas encadeadas (isto é, engate a segunda no fim
da primeira)./*/

#include <stdio.h>
#include <stdlib.h>


typedef struct strLista
{
    int num;
    struct strLista *prox;
} Lista;

void grupo();
void limpar(Lista *in);
void inserirLista1(int num);
void inserirLista2(int num);
void inserirManual(int qual);
void inserirAutomatico(int val);
void concatenar();
void imprimir(Lista *in, char titulo[]);
void limpar();

Lista *inicio1 = NULL;
Lista *inicio2 = NULL;

int main()
{
    int op,val;

    grupo();
    printf("O que você deseja?\n\n");
    printf("[1]Inserir valores manualmente\n");
    printf("[2]Inserir uma quantidade definida de valores\n");
    scanf("%d",&op);

    switch(op)
    {
    case 1:
        inserirManual(1);
        inserirManual(2);
        break;
    case 2:
        printf("\n\nQuantos valores deseja?: ");
        scanf("%d",&val);

        if(val <= 0 )
        {
            printf("\n\n VALOR INVÁLIDO ");

        }
        inserirAutomatico(val);
        break;
    default:
        return 0;
    }


    concatenar();


    limpar(inicio1);
    limpar(inicio2);

    return 0;
}

void inserirManual(int qual)
{
    int val;

    do
    {
        printf("\nInforme o valor para a lista %d (-1 para finalizar): ",qual);
        scanf("%d",&val);

        if(val != -1)
        {
            if(qual == 1)
            {
                inserirLista1(val);
            }
            else
            {
                inserirLista2(val);
            }

        }
        else
        {
            break;
        }
    }
    while(1);
}

void inserirAutomatico(int val)
{
    int i = 0;

    for(i=0; i<val; i++)
    {
        inserirLista1(i);
        inserirLista2(i);
    }
}

void inserirLista1(int num)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->num = num;
    novo->prox = NULL;

    if (novo == NULL)
    {
        printf("ERRO: Memória insuficiente !\n");
        return;
    }

    if(inicio1 == NULL)
    {
        inicio1 = novo;
        return;
    }

    Lista *aux = inicio1;

    while(aux->prox != NULL)
    {

        aux = aux->prox;
    }

    aux->prox = novo;
}

void inserirLista2(int num)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->num = num;
    novo->prox = NULL;

    if (novo == NULL)
    {
        printf("ERRO: Memória insuficiente !\n");
        return;
    }

    if(inicio2 == NULL)
    {

        inicio2 = novo;
        return;
    }

    Lista *aux = inicio2;

    while(aux->prox != NULL)
    {

        aux = aux->prox;
    }

    aux->prox = novo;
}

void concatenar()
{
    imprimir(inicio1, "############ VALORES NA LISTA 1 ############");
    imprimir(inicio2, "############ VALORES NA LISTA 2 ############");


    Lista *aux1 = inicio1;


    while(aux1->prox != NULL)
    {
        aux1 = aux1->prox;
    }
    aux1->prox = inicio2;

    imprimir(inicio1, "####### VALORES NA LISTA Concatenada #######");
    return;
}

void imprimir(Lista *in, char titulo[])
{
    Lista *aux = in;

    printf("\n %s\n",titulo);

    while(aux != NULL)
    {
        printf(" %d ",aux->num);
        aux = aux->prox;
    }

}


void limpar(Lista *in)
{
    Lista *aux = in;
    Lista *temp;

    while(aux != NULL)
    {
        temp = aux->prox;
        free(aux);
        aux = temp;

    }
}
