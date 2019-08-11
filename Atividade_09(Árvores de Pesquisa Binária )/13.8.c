#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
	int num;
	struct No *esq;
	struct No *dir;
}No;

No* root = NULL;
int aux = 0;

int inserir(int n){
	No* novo = (No *)malloc(sizeof(No));
	if(novo == NULL)
		return 0;

	novo->num = n;
	novo->esq = novo->dir = NULL;

	if(root == NULL){
		root = novo;
		return 1;
	}

	No* pai = NULL;
	No* p = root;
	while(p != NULL){
        	pai = p;
        	if(p->num > n)
            		p = p->esq;

       		 else
            		p = p->dir;
    	}
    	if(pai->num > n)
        	pai->esq = novo;
    	else
        	pai->dir = novo;

    	return 1;

}

void valor(No *p){
	int resul;

	if(p != NULL){

		valor(p->esq);
		resul = resul + p->num;
		valor(p->dir);

	}
	printf("Resultado: %d", resul);
}

int main(){

	setlocale(LC_ALL, "Portuguese");

	inserir(*);
	inserir(/);
	inserir(+);
	inserir(5);
	inserir(3);
	inserir(4);
	inserir(-);
	inserir(6);
	inserir(1);

	valor(root);

}


