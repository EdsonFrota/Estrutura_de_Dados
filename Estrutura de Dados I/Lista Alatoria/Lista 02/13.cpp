/*Escrever uma função que, dado uma lista encadeada L desordenada, cria uma lista K
ordenada, com os mesmos nós da lista L. A função remove os elementos da lista L, sempre
do maior para o menor, e insere-os no início da lista K, que dessa forma torna-se uma lista
ordenada (em ordem crescente). Obs: não devem ser criados nós extras, vocês devem
utilizar os mesmos nós alocados para a lista L. No final do processo, a lista L estará vazia e a
lista K conterá os nós anteriormente alocados para a lista L.*/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct lista{
	int n;
	struct lista *prox;
}lista;

lista *ordenada;

void printList(lista *lista);
void Freedom(lista *whilly);
void concatenarListas(lista *lista1, lista *lista2);

lista *addFinal(lista *inicio, lista *elemento);
lista *ordena(lista *inicio);
void fundirListas(lista *l1, lista *l2);

int main(int argc, char *argv[]) {
	ordenada=NULL;

	lista *inicioDaLista1;
	lista *proximoElemento;
	inicioDaLista1 = (lista *)malloc(sizeof(lista));
	proximoElemento = inicioDaLista1;

	int op;
	printf("\tLista1\n");
	do{
		printf("Contetudo(int) ");
		scanf("%d", &proximoElemento->n);
		printf("0 para finalizar, qualquer outro numero para continuar");
		scanf("%d", &op);
		if(op!=0){
			proximoElemento->prox = (lista *)malloc(sizeof(lista));
			if(proximoElemento == NULL){
				printf("maluco FUDEU!!!");
				exit(1);
			}
			proximoElemento = proximoElemento->prox;
		}

	}while(op!=0);
	proximoElemento->prox = NULL;

	printf("\nLista1 original");
	printList(inicioDaLista1);
	inicioDaLista1=ordena(inicioDaLista1);
	printf("\nLista1 ordenada");
	printList(inicioDaLista1);
	Freedom(ordenada);
	ordenada=NULL;

	lista *inicioDaLista2;
	inicioDaLista2 = (lista *)malloc(sizeof(lista));
	proximoElemento = inicioDaLista2;
	op=1;
	printf("\n\tList2\n");
	do{
		printf("Contetudo(int) ");
		scanf("%d", &proximoElemento->n);
		printf("0 para finalizar, qualquer outro numero para continuar");
		scanf("%d", &op);
		if(op!=0){
			proximoElemento->prox = (lista *)malloc(sizeof(lista));
			if(proximoElemento == NULL){
				printf("maluco FUDEU!!!");
				exit(1);
			}
			proximoElemento = proximoElemento->prox;
		}

	}while(op!=0);
	proximoElemento->prox = NULL;

	printf("\nLista2 original");
	printList(inicioDaLista2);
	inicioDaLista2=ordena(inicioDaLista2);
	printf("\nLista2 ordenada");
	printList(inicioDaLista2);
	Freedom(ordenada);
	ordenada=NULL;

	printf("\nFusao das duas listas");
	fundirListas(inicioDaLista1,inicioDaLista2);
	printList(inicioDaLista1);

	Freedom(inicioDaLista1);
	Freedom(inicioDaLista2);
	return 0;
}

void printList(lista *lista){
	printf("\n");
	while(lista!=NULL){
		printf("%d ",lista->n);
		lista = lista->prox;
	}
}
void Freedom(lista *whilly){
	lista *prox;
    while (whilly){
    	prox = whilly->prox;
        free(whilly);
        whilly = prox;
    }
}
void concatenarListas(lista *lista1, lista *lista2){
	while(1){
		if(lista1->prox == NULL){
			lista1->prox=lista2;
			return;
		}
		lista1 = lista1->prox;
	}
}

lista *addFinal(lista *inicio, lista *elemento){
	if(inicio==NULL){
		inicio=elemento;
		return inicio;
	}else{
		lista *l;
		l=inicio;
		while(l->prox!=NULL){
			l=l->prox;
		}
		l->prox=elemento;
		return inicio;
	}
}

lista *ordena(lista *inicio){
	lista *aux, *auxAnt, *maior;
	aux=inicio;
	maior=inicio;


	while(aux!=NULL){
		if(aux->n<maior->n){
			maior=aux;
		}
		aux=aux->prox;
	}
	aux=inicio;
	while(aux!=NULL){
		if(aux==maior){
			if(aux==inicio){
				inicio=aux->prox;
				maior->prox=NULL;
				ordenada=addFinal(ordenada, maior);
				free(aux);
				break;
			}else{
				auxAnt->prox=aux->prox;
				maior->prox=NULL;
				ordenada=addFinal(ordenada, maior);
				free(aux);
				break;
			}
		}else{
			auxAnt=aux;
			aux=aux->prox;
		}
	}
	aux=inicio;
	if(inicio!=NULL){
		inicio=ordena(inicio);
	}
	return ordenada;
}

void fundirListas(lista *l1, lista *l2){
	concatenarListas(l1,l2);
	l1=ordena(l1);
	Freedom(ordenada);
	ordenada=NULL;
}
void grupo() {

}
