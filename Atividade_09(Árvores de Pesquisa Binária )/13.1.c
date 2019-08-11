#include<stdio.h>

struct No{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;

void criarArvore(No **pRaiz){
    *pRaiz = NULL;
}

void insercao(No **Raiz, int numero){
	if (*Raiz==NULL){
	*Raiz=(No *)malloc(sizeof (No));
	(*Raiz)->esq=NULL;
	(*Raiz)->dir=NULL;
	(*Raiz)->chave=numero;
	}else {
		if (numero<((*Raiz)->chave)){
			insercao(&((*Raiz)->esq), numero);
		}else{
			insercao(&((*Raiz)->dir), numero);
		}
	}
}

No *MaiorDireita(No **no){
    if((*no)->direita != NULL)
       return MaiorDireita(&(*no)->direita);
    else{
       No *aux = *no;
       if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esquerda;
       else
          *no = NULL;
       return aux;
       }
}

No *MenorEsquerda(No **no){
    if((*no)->esquerda != NULL)
       return MenorEsquerda(&(*no)->esquerda);
    else{
       No *aux = *no;
       if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *no = (*no)->direita;
       else
          *no = NULL;
       return aux;
       }
}

void remover(No **pRaiz, int numero){
    if(*pRaiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       getch();
       return;
    }
    if(numero < (*pRaiz)->numero)
       remover(&(*pRaiz)->esquerda, numero);
    else
       if(numero > (*pRaiz)->numero)
          remover(&(*pRaiz)->direita, numero);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          No *pAux = *pRaiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL;
               }
          else{     // so tem o filho da direita
             if ((*pRaiz)->esquerda == NULL){
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*pRaiz)->direita == NULL){
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux); pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   pAux = MaiorDireita(&(*pRaiz)->esquerda); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                   pAux->esquerda = (*pRaiz)->esquerda;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                   pAux->direita = (*pRaiz)->direita;
                   (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                   free((*pRaiz));  *pRaiz = pAux;  pAux = NULL;
                   }
                }
             }
          }
}
