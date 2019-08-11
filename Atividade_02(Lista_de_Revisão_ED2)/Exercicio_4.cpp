/*(4) Invente um jeito de remover uma célula de uma lista encadeada sem
cabeça. (Será preciso tomar algumas decisões de projeto antes de
começar a programar.)*/

#include<stdio.h>

void remover(pessoa *p){
   pessoa *remove;
   remove = p->prox;
   p->prox = remove->prox;
   remover(lixo);
}
