/*Escreva uma função que verifique se duas listas encadeadas têm o mesmo conteúdo (não
necessariamente na mesma ordem)./*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


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
void comparar();
void imprimir(Lista *in, char titulo[]);
void limpar(Lista *in);

Lista *inicio1 = NULL;
Lista *inicio2 = NULL;
int qt1=0,qt2=0;

int main()
{

    setlocale(LC_ALL, "");
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
            return 0;
        }
        inserirAutomatico(val);
        break;
    default:
        return 0;
    }


    comparar();


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
        qt1++;
        return;
    }

    Lista *aux = inicio1;

    while(aux->prox != NULL)
    {

        aux = aux->prox;
    }

    aux->prox = novo;
    qt1++;
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
        qt2++;
        return;
    }

    Lista *aux = inicio2;

    while(aux->prox != NULL)
    {

        aux = aux->prox;
    }

    aux->prox = novo;
    qt2++;
}

void comparar()
{
    imprimir(inicio1, "############ VALORES NA LISTA 1 ############");
    imprimir(inicio2, "############ VALORES NA LISTA 2 ############");

    if(qt1!=qt2)
    {
        printf("\n -> As listas são diferentes");
        return;
    }

    Lista *aux1 = inicio1;
    Lista *aux2 = inicio2;

    while(aux1 != NULL)
    {
        if(aux1->num == aux2->num)
        {
	    // para não haver comparação "repetida"
	    // exemplo: l1: 1 3 3 / l2: 1 3 1
            // o método é ludibriado com os valores iguais
	    aux2->num = -1;
            aux2 = inicio2;
            aux1 = aux1->prox;
            continue;
        }

        aux2 = aux2->prox;

        if(aux2 == NULL)
        {
            printf("\n -> As listas são diferentes");
            return;
        }
    }

    printf("\n -> As listas são iguais");
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
