 /*Escrever uma função para remover elementos repetidos de uma lista encadeada.*/

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

typedef struct lista{
	int num;
	struct lista *prox;
}Lista;

void grupo();
void inserirLista(int num);
void inserirManual();
void inserirAutomatico(int val);
void eliminarRepetidos();
Lista* buscarRepetido(Lista *elemento);
void imprimir();
void limpar();

Lista *inicio = NULL;


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

    eliminarRepetidos();

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

void inserirLista(int num){
	Lista *novo = (Lista *) malloc(sizeof(Lista));

	if(novo == NULL){
        	printf("ERRO: Memória insuficiente !\n");
		return;
	}

	novo->num = num;
	novo->prox = NULL;

	if(inicio == NULL){
		inicio = novo;
		return;
	}

	Lista *aux = inicio;

	while(aux->prox != NULL){
		aux = aux->prox;
	}

	aux->prox = novo;
}

void eliminarRepetidos(){
	Lista *aux = inicio;
	Lista *temp = NULL;
	if(aux == NULL){
		printf("\n\nLista vazia");
		return;
	}

	imprimir();
	while(aux != NULL){
		temp = buscarRepetido(aux);

		if(temp != NULL){
			Lista *l = temp->prox;

			if(l->prox != NULL){
				temp->prox = l->prox;
			}else{
				temp->prox = NULL;
			}

			free(l);

			continue;

		}

		aux = aux->prox;


	}
	imprimir();

}

// retorna o pai
Lista* buscarRepetido(Lista *elemento){
	if(elemento->prox == NULL){
		return NULL;
	}

	Lista *aux = elemento->prox;
	Lista *temp = elemento;
	while(aux != NULL){
		if(aux->num == elemento->num){
			return temp;
		}
		temp = aux;
		aux = aux->prox;

	}
	return NULL;
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
