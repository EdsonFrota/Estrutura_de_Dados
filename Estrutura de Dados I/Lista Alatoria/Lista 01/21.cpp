 /*Crie uma estrutura representando os alunos do curso de Métodos e Técnicas de
Programação. A estrutura deve conter a matrícula do aluno, nome, nota da primeira
prova, nota da segunda prova e nota da terceira prova.
a. Permita ao usuário entrar com os dados de 5 alunos
b. Encontre o aluno com maior nota da primeira prova
c. Encontre o aluno com maior média geral
d. Encontre o aluno com menor média geral
e. Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6
para aprovação.*/

#include<stdio.h>
#include<stdlib.h>
struct universidade
{
    int mat;
    char nome[2];
    int pp,sp,tp,fp;

};
int main()
{
    struct  alunos[2]
            int i;
    for(i=0; i<2; i++)
{
        printf("digite seu nome: \n",i);
        gets(alunos.nome);
        printf("\nvalor primeira prova: ",i);
        scanf("%d",&alunos.pp);
        printf("valor segunda prova: ",i);
        scanf("%d",&alunos.sp);
        printf("valor terceira prova: ",alunos.tp);
        scanf("%d",&alunos.tp);
    }
    int media;

    for(i=0; i<2; i++)
    {

        printf("media final: ",i);
        scanf("%d",&alunos.fp);


    }
