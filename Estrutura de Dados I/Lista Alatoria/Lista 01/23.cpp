/*Implemente um programa em C que leia o nome, a idade e o enderešo de uma pessoa
e armazene os dados em uma estrutura./*/


#include <stdio.h>

typedef struct pessoa
{

    char nome[10], endereco[20];
    int idade;

} PESSOA;

int main()
{

    PESSOA p;

    printf(" Nome da pessoa.\n");
    scanf(" %s", p.nome);
    printf(" Idade da pessoa.\n");
    scanf(" %d", &p.idade);
    printf(" Enderešo da pessoa.\n");
    scanf(" %s", p.endereco);

    printf("\t\tPessoa:\n\tNome:%s\n\tIdade:%i\n\tEnderešo:%s\n\n", p.nome, p.idade, p.endereco);
    return(0);
}
