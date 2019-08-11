/*Escreva uma função que receba uma lista encadeada e devolva o endereço de uma célula
que esteja o mais próximo possível do meio da lista. Faça isso sem contar explicitamente o
número de células da lista./*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int n;
	struct lista *prox;
}lista;

lista *meioDaLista(lista *a){
	lista *aux1=NULL;
	lista *aux2=NULL;
	aux1 = a;
	aux2 = a;

	while(aux1!=NULL){
		aux1 = aux1->prox;
		if(aux1!=NULL){
			aux1 = aux1->prox;
			aux2 = aux2->prox;
		}
	}
	return aux2;
}

