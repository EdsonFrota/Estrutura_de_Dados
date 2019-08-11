/* Utilizando estrutura, fazer um programa em C que permita a entrada de nome,
endereço e telefone de 5 pessoas e os imprima em ordem alfabética.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct cadastro
{
    char nome[20];
    char end[50];
    char telefone[11];
};

int main()
{
    int i;


    struct cadastro *c;
    c = (struct cadastro*) malloc(sizeof(c)*5);
    for (i=0; i<5; i++)
    {
        printf("\n Digite seu Nome : ");
        scanf("%s", c[i].nome);
        printf("\n Digite seu Endereco : ");
        scanf("%s", &c[i].end);
        printf("\n Digite seu Telefone : ");
        scanf("%s", &c[i].telefone);
    }
    for (i=0; i<5; i++)
    {
        printf("\n Nome : %s", c[i].nome);
        printf("\n Endereco : %s", c[i].end);
        printf("\n Telefone : %s", c[i].telefone);
        printf("\n\n");
    }
    getch();
}
