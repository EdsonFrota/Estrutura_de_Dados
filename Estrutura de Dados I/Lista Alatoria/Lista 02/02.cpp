/*A altura de uma célula c em uma lista encadeada é a distância entre c e o fim da lista. Mais
precisamente, a altura de c é o número de passos do caminho que leva de c até a última
célula da lista. Escreva uma função que calcule a altura de uma dada célula.*/

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
void pesquisar(int num);
void imprimir();
void limpar();

Lista *inicio = NULL;
int qt=0;

int main()
{
    setlocale(LC_ALL, "");
    int op,val,pesquisa;

    grupo();
    printf("O você deseja?\n\n");
    printf("[1]Inserir valores manualmente\n");
    printf("[2]Inserir uma quantidade definida de valores\n");
    scanf("%d",&op);

    switch(op)
    {
    case 1:
        inserirManual();
        break;
    case 2:
        printf("\n\nQuantos valores?: ");
        scanf("%d",&val);
        inserirAutomatico(val);
        break;
    default:
        return 0;
    }

    printf("\nInforme para pesquisar a sua altura: ");
    scanf("%d",&pesquisa);
    pesquisar(pesquisa);

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

void pesquisar(int num)
{
    Lista *aux = inicio;
    int cont=0,i=0, *vet;

    vet = (int *)malloc(qt*sizeof(int));

    while(aux != NULL)
    {

        if(aux->num == num)
        {
            vet[i] = cont;
            i++;
        }
        cont++;
        aux = aux->prox;
    }

    imprimir();

    printf("\n\n ######## VALOR PESQUISADO: %d #######",num);

    if(i == 0)
    {
        printf("\n\n Este valor não está na lista\n\n");
        return;
    }
    else
    {
        printf("\n\n %d %s", i, (i>1? "ocorrências encontradas. Alturas:": "ocorrência encontrada. Altura:"));
    }

    int j;
    for (j = 0; j < i; ++j)
    {

        printf("\n -> %d ", (cont - vet[j]));

    }

    printf("\n");
    free(vet);
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
void grupo()
{


}
