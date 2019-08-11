/*1. Escreva uma função que conte o número de células de uma lista encadeada. Faça duas
versões: uma iterativa e uma recursiva.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Algo{
	int num;
	struct Algo *prox;
	struct Algo *ant;
}Algo;

Algo *inicio;

void addFim(){
	Algo *novo = (Algo *)malloc(sizeof(Algo));
	if(novo == NULL){
		printf("ERRO");
	}
	printf("Numero: ");
	scanf("%d", &novo->num);
	novo->prox = NULL;
	if(inicio == NULL){
		inicio = novo;
		return;
	}

	Algo *fim = inicio;
	while(fim->prox != NULL){
		fim = fim->prox;
	}
	fim->prox = novo;
}

void listarR (Algo *a) {
   printf("\n");
   if (a != NULL) {
      printf ("\n%d", a->num);
      listarR (a->prox);
   }
}

void listar(){
	int total = 0;
	Algo *run = inicio;
	printf("\n");
	while(run != NULL){
		total++;
		printf("\n%d", run->num);
		run = run->prox;
	}
}



int main(){
	char op, op2;
	do{
		printf("\nAdicionar novo? ");
		do{
			scanf("%c", &op);
		}while(op != 's' && op != 'n');
		switch(op){
			case 's':
				addFim();
				break;
			case 'n':
				break;
		}
	}while(op != 'n');
	printf("\nListagem Iterativa: ");
	listar();
	printf("\nListagem Recursiva: ");
	listarR(inicio);
}

