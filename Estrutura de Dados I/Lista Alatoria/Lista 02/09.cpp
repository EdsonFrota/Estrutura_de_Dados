/*Escreva uma função que insira em uma lista encadeada uma nova célula com conteúdo x
imediatamente depois da k-ésima célula.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Algo{
	int num;
	struct Algo *prox;
}Algo;

Algo *inicio;

void addFim(){
	Algo *novo = (Algo *)malloc(sizeof(Algo));
	if(novo == NULL){
		printf("\nERRO\n");
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

bool estaOrdenada(){
    if (inicio != NULL){
        Algo *a = inicio;
        while (a->prox != NULL){
            if (a->num > a->prox->num)
                return false;
            a = a->prox;
        }
    }
    return true;
}

int menorN(){
	int menor;
	if (inicio != NULL){
        Algo *a = inicio;
        Algo *aux;
		while (a->prox != NULL){
            if (a->num > a->prox->num){
                menor = a->prox->num;
            }
            a = a->prox;
        }
    }
    return menor;
}

void listar(){
	int i=1;
	printf("\nLista\n");
	Algo *run = inicio;
	while(run != NULL){
		printf("\n %d: %d", i, run->num);
		run = run->prox;
		i++;
	}
}

Algo* buscar(int x, Algo *a){
	a = inicio;
	while(a != NULL && a->num != x){
		if(a->num == x){
			return a;
		}
		a = a->prox;
	}
	return NULL;
}

void remove(Algo *p){
   Algo *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}

void insereEsp(Algo *b, int x){
	int i = 2;
	Algo *a = inicio;
	Algo *aux;
	while(a != NULL){
		if(i == x){
			aux = a->prox;
			a->prox = b;
			b->prox = aux;
		}
		a = a->prox;
		i++;
	}
}

int main(){
	char op, busca;
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
	Algo *p = (Algo*)malloc(sizeof(Algo));
	p->num = -255;
	insereEsp(p, 3);
	listar();
	free(p);
}
