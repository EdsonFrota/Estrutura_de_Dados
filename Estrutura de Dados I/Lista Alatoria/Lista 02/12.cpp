 /*Escreva uma função para remover de uma lista encadeada contendo números inteiros,
todas as células que contêm o número y passado como parâmetro.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct strLista
{
    int num;
    struct strLista *prox;
} Lista;

void grupo();
void inserirLista(int num);
void inserirManual();
void inserirAutomatico(int val);
void remover(int num);
void imprimir();
void limpar();

Lista *inicio = NULL;
int qt=0;

int main()
{
    int op,val,num;

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

    printf("\nInforme o valor para remover da lista: ");
    scanf("%d",&num);

    remover(num);

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

    if (novo == NULL)
    {
        printf("ERRO: Memória insuficiente !\n");
        return;
    }

    novo->num = num;
    novo->prox = NULL;


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

void remover(int num)
{

    if(inicio == NULL)
    {
        printf("\nLista vazia");
        return;
    }

    Lista *aux = inicio;
    Lista *pai = NULL;

    imprimir();


    while(aux != NULL)
    {
        if(aux->num == num)
        {
            qt--;
            if(pai == NULL)
            {
                inicio = aux->prox;
                free(aux);
                aux=inicio;
                continue;
            }
            else
            {
                pai->prox = aux->prox;
                free(aux);
                aux = pai->prox;
                continue;
            }
        }
        pai = aux;
        aux = aux->prox;
    }

    printf("\n\nValor a ser removido: %d",num);
    if(qt == 0)
    {
        printf("\n-> A lista so continha o valor %d. Todos os valores foram removidos!\n",num);
        return;
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
