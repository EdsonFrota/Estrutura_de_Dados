#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct No{
	
	int valor;
	struct No *dir;
	struct No *esq;
	
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

No* buscar(int n)
{
    No* p = root;
    while(p != NULL)
    {
        if(p->valor == n)
            return p;

        if(p->valor > n)
            p = p->esq;
        else
            p = p->dir;
    }

    return NULL;
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	int op, n, n1;
	
	do{

	printf("\nOpções: \n");
	printf("  [1] Inserir\n");
	printf("  [2] Buscar um elemento da lista\n");
	printf("  [3] Sair\n");
	scanf("%d", &op);
	system("cls");

	switch(op){

		case 1: printf("OPÇÃO 1\n");
			printf("Digite um número: ");
			scanf("%d", &n);
			inserir(n);
			system("cls");
			break;

		case 2: printf("OPÇÃO 2\n");
			printf("Digite o número a ser buscado: ");
			scanf("%d", &n1);
			if(buscar(n) == NULL)
                        printf("Número NÃO foi encontrado na árvore\n");
                    else
                        printf("Número foi encontrado na árvore\n");
			system("Cls");
			break;
		

	}
	
	}while(op != 3 );
	
	
	return 0;
}
