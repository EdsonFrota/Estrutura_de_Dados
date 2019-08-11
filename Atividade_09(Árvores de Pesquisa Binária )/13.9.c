#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
	
	int valor;
	struct No *esq;
	struct No *dir;
	
}No;

struct No *root = NULL;

int inserir(int num){

	No* novo = (No *)malloc(sizeof(No));
	if(novo == NULL)
		return 0;
	
	novo->valor = num;
	novo->esq = novo->dir = NULL;

	if(root == NULL){

		root = novo;	
		return 1;

	}

	No* pai = NULL;
	No* p = root;

	while(p != NULL)
    	{
        	pai = p;
        	if(p->valor > num)
            		p = p->esq;

       		 else
            		p = p->dir;
    	}
    	if(pai->valor > num)
        	pai->esq = novo;
    	else
        	pai->dir = novo;

    	return 1;

}

void mostrar(){

	if(root == NULL)
		printf("A árvore está vazia\n");
	else
		ordemDecrescente(root);
}

void ordemDecrescente(No *p){
	
	if(p != NULL){
		
		ordemDecrescente(p->dir);
		printf("%d->", p->valor);
		ordemDecrescente(p->esq);
		

	}

}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	int op, n;
	
	do{

	printf("\nOpções: \n");
	printf("  [1] Inserir\n");
	printf("  [2] Exibir elementos da árvore em ordem decrescente: \n");
	printf("  [3] Sair\n");
	scanf("%d", &op);
	system("cls");

	switch(op){

		case 1: 
			
			printf("OPÇÃO 1\n");
			printf("Digite um número: ");
			scanf("%d", &n);
			inserir(n);
			system("cls");
			break;

		case 2:
			
			printf("OPÇÃO 2\n");
			mostrar();
			break;

	}
	
	}while(op != 3 );
	
	
	return 0;
	
}
