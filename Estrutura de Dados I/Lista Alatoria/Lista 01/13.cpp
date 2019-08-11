/*Faça um programa que leia um inteiro n e:
• Crie e leia um vetor com dados de n livros: tıtulo (máximo 30 letras), autor (máximo
15 letras) e ano.
• Procure um livro por título, perguntando ao usuário qual título deseja buscar.
Mostre os dados de todos os livros encontrados.*/

#include<stdlib.h>
#include<stdio.h>
typedef struct livraria
{
    char titulo[30];
    char autor[15];
    int ano;
} livraria;

livraria livros[5];

void procura(char titulo[])
{
    int i;
    for(i=0; i<5; i++)
    {
        if(strcmp(livros[i].titulo,titulo) == 0)
        {
            printf("%s\n", livros[i].titulo);
            printf("%s\n", livros[i].autor);
            printf("%d\n", livros[i].ano);
        }
    }
}

int main()
{
    int i;
    char nometit[30];
    for(i=0; i<5; i++)
    {
        printf("titulo:%d \n", i + 1);
        gets(livros[i].titulo);
        fflush(stdin);
        printf("autor:%d \n", i + 1);
        gets(livros[i].autor);
        fflush(stdin);
        printf("ano:%d \n", i + 1);
        scanf("%d",&livros[i].ano);
        fflush(stdin);

    }
    printf("Digite o titulo do livro");
    gets(nometit);
    procura(nometit);
    system("pause");

    return 0;


}
