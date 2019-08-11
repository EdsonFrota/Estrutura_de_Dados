#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
	
	int valor;
	struct No *dir;
	struct No *esq;
	
}No;

struct No *root = NULL;
struct No *root1 = NULL;

int inserir1(int num){

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

int inserir2(int num){

	No* novo1 = (No *)malloc(sizeof(No));
	if(novo1 == NULL)
		return 0;
	
	novo1->valor = num;
	novo1->esq = novo1->dir = NULL;

	if(root1 == NULL){

		root1 = novo1;	
		return 1;

	}

	No* pai = NULL;
	No* p = root1;

	while(p != NULL)
    	{
        	pai = p;
        	if(p->valor > num)
            		p = p->esq;

       		 else
            		p = p->dir;
    	}
    	if(pai->valor > num)
        	pai->esq = novo1;
    	else
        	pai->dir = novo1;

    	return 1;

}

int verificarIgualdade(No *p, No *q){
	
	if( p == NULL && q == NULL)
		return 1;
	if( p == NULL || q == NULL)
		return 0;
	if(( p->valor == q->valor) && verificarIgualdade( p->esq, q->esq ) && verificarIgualdade( p->dir, q->dir ));
		return 1;
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	int op, n, n1;
	
	do{

	printf("\nOpções: \n");
	printf("  [1] Inserir elemento\n");
	printf("  [2] Verificar se as duas árvores são iguais\n");
	printf("  [3] Sair\n");
	scanf("%d", &op);
	system("cls");

	switch(op){

		case 1: printf("OPÇÃO 1\n");
			printf("Digite um número para a PRIMEIRA árovre: ");
			scanf("%d", &n);
			inserir1(n);
			printf("Digite um número para a SEGUNDA árvore: ");
			scanf("%d", &n1);
			inserir2(n1);
			system("cls");
			break;

		case 2: printf("OPÇÃO 2\n");
			
			verificarIgualdade(root, root1);
			
			system("cls");
			break;
		

	}
	
	}while(op != 3 );
	
	
	return 0;
}
