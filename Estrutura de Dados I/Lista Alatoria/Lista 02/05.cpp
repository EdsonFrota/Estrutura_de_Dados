/*Seja uma lista encadeada que contém números inteiros. Faça as seguintes funções:
a) Verifique se a lista encadeada está em ordem crescente.
b) Encontre todas as células que contenham o menor número da lista.*/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct lista{
	int n;
	struct lista *prox;
}lista;

lista *inicioDaLista;

void printList(lista *lista);
void Freedom(lista *whilly);
lista* copiaLista(lista *l);

void ordCrescente(lista *lista);
int menorN(lista *lista);


int main(int argc, char *argv[]) {
	lista *proximoElemento;

	inicioDaLista = (lista *)malloc(sizeof(lista));
	proximoElemento = inicioDaLista;

	int op;
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

	printList(inicioDaLista);
	ordCrescente(inicioDaLista);
	printf("\nMenor elemento: %d\n", menorN(inicioDaLista));

    int listaA, listaB;
	Freedom(inicioDaLista);
	Freedom(listaA);
	Freedom(listaB);

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

lista* copiaLista(lista *l){
	lista* l2;
	l2 = (lista *)malloc(sizeof(lista));

	lista *proximoElemento;
	proximoElemento = l2;

	while(1){
		proximoElemento->n=l->n;
		proximoElemento->prox = (lista *)malloc(sizeof(lista));
		l = l->prox;
		if(l==NULL){
			proximoElemento->prox=NULL;
			return l2;
		}
		proximoElemento = proximoElemento->prox;
	}
	return l2;
}

void ordCrescente(lista *lista){
	int cres = 0;
	do{
		if(lista->prox == NULL){
		}else{
			if((lista->n) > (lista->prox->n)){
				cres = 1;
			}
		}
		lista = lista->prox;
	}while(lista != NULL);
	if(cres == 0){
		printf("\nA lista esta em ordem crescente");
	}
	if(cres == 1){
		printf("\nA lista Nao esta em ordem crescente");
	}
}
//Ex05
int menorN(lista *lista){
	int aux;
	int flag = 0;
	do{
		if(flag == 0){
			aux = lista->n;
			flag = 1;
		}else{
			if(lista->n < aux){
				aux = lista->n;
			}
		}
		lista = lista->prox;
	}while(lista != NULL);
	return aux;
}
