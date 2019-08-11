/*Escreva uma função que troque de posição duas células de uma mesma lista encadeada./*/

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>


typedef struct strLista
{
    int num;
    struct strLista *prox;
} Lista;

void grupo();
void limpar();
void inserirLista(int num);
void inserirManual();
void inserirAutomatico(int val);
void trocar(int num1, int num2);
void trocaVizinhos(Lista *pai1,Lista *pai2, Lista *filho1, Lista *filho2);
void trocaNormal(Lista *pai1,Lista *pai2, Lista *filho1, Lista *filho2);
Lista* buscaPai(int num);
void imprimir();
void limpar();

Lista *inicio = NULL;
int qt=0;

int main()
{
    setlocale(LC_ALL, "");
    int op,val,num1,num2;

    grupo();
    printf("Olá, o que você deseja?\n\n");
    printf("[1]Inserir valores manualmente\n");
    printf("[2]Inserir uma quantidade definida de valores\n");
    scanf("%d",&op);

    switch(op)
    {
    case 1:
        inserirManual();
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

    printf("\nInforme o PRIMEIRO valor para trocar a posição: ");
    scanf("%d",&num1);
    printf("\nInforme o SEGUNDO valor para trocar a posição: ");
    scanf("%d",&num2);

    trocar(num1,num2);

    limpar();

    return 0;
}

void inserirManual()
{
    int val;

    do
    {
        printf("\nInforme o valor (-1 para finalizar): ");
        scanf("%d",&val);

        if(val != -1)
        {
            inserirLista(val);
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
        inserirLista(i);
    }
}

void inserirLista(int num)
{

    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->num = num;
    novo->prox = NULL;

    if (novo == NULL)
    {
        printf("ERRO: Memória insuficiente !\n");
        return;
    }

    if(inicio == NULL)
    {
        inicio = novo;
        qt++;
        return;
    }

    Lista *aux = inicio;

    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = novo;
    qt++;
}

Lista* buscaPai(int num)
{
    Lista *aux = inicio;
    Lista *temp = NULL;

    while(aux != NULL)
    {
        if(aux->num == num)
        {
            if(temp == NULL)
            {
                return NULL;
            }
            else
            {
                return temp;
            }
        }
        temp = aux;
        aux = aux->prox;
    }

    printf("\nValor \"%d\" não encontrado\n",num);
    exit(0);
}
void trocar(int num1, int num2)
{

    Lista *pai1, *pai2, *filho1, *filho2, *temp;
    imprimir();

    if(inicio == NULL)
    {
        printf("\nLista vazia");
        return;
    }


    pai1 = buscaPai(num1);


    if(pai1 != NULL)
    {
        filho1 = (pai1->prox != NULL ? pai1->prox : NULL);
    }
    else
    {
        filho1 = inicio;
    }

    pai2 = buscaPai(num2);


    if(pai2 != NULL)
    {
        filho2 = (pai2->prox != NULL ? pai2->prox : NULL);
    }
    else
    {
        filho2 = inicio;
    }

    if(filho1 == pai2)
    {
        trocaVizinhos(pai1,pai2,filho1,filho2);
        return;
    }

    if(filho2 == pai1)
    {
        trocaVizinhos(pai2,pai1,filho2,filho1);
        return;
    }

    temp = filho1->prox;


    filho1->prox = (filho2->prox != NULL ? filho2->prox : NULL);

    filho2->prox = temp;


    if(pai1 != NULL)
    {
        pai1->prox = filho2;
    }
    else
    {
        inicio = filho2;
    }

    if(pai2 != NULL)
    {
        pai2->prox = filho1;
    }
    else
    {
        inicio = filho1;
    }

    imprimir();

}

void trocaVizinhos(Lista *pai1,Lista *pai2, Lista *filho1, Lista *filho2)
{
    filho1->prox = (filho2->prox != NULL ? filho2->prox : NULL);
    filho2->prox = filho1;
    if(pai1!=NULL)
    {
        pai1->prox = filho2;
    }
    else
    {
        inicio = filho2;
    }
    imprimir();

}


void imprimir()
{
    Lista *aux = inicio;

    printf("\n ############ VALORES NA LISTA ############\n");

    while(aux != NULL)
    {
        printf(" %d ",aux->num);
        aux = aux->prox;
    }

}

void limpar()
{
    Lista *aux = inicio;
    Lista *temp;

    while(aux != NULL)
    {
        temp = aux->prox;
        free(aux);
        aux = temp;

    }

}
void grupo() {

}
