/*Crie uma estrutura representando os alunos do curso de Estrutura de Dados. A
estrutura deve conter a matrıcula do aluno, nome, nota da primeira prova, nota da
segunda prova e nota da terceira prova.
a. Permita ao usuário entrar com os dados de 5 alunos.
b. Encontre o aluno com maior nota da primeira prova.
c. Encontre o aluno com maior média geral.
d. Encontre o aluno com menor média geral
e. Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6
para aprovação./*/

#include <stdio.h>
int main()
{
    struct prova
    {
        int matric;
        char nome[50];
        float nota[3];
    } aluno[5];
    float media ,maior_media, menor_media, maior_prim_prova;
    int i, j, ind_maior=0, ind_menor=0, ind_maior_prim_prova=0;
    for (i=0; i<5; i++)
    {
        printf("Informe a matrícula e nome do %dº aluno: ", i+1);
        scanf("%d", &aluno[i].matric);
        gets(aluno[i].nome);
        for (j=0; j<3; j++)
        {
            printf("Informe a nota da %dª prova: ", j+1);
            scanf("%f", &aluno[i].nota[j]);
        }
    }
    printf("\nResultado:\n");
    for (i=0; i<5; i++)
    {
        media = (aluno[i]. nota[0] + aluno[i].nota[1] + aluno[i].nota[2]) / 3;
        if (i == 0)
        {
            maior_media = menor_media = media;
            maior_prim_prova = aluno[i].nota[0];
        }
        else
        {
            if (media > maior_media)
            {
                maior_media = media;
                ind_maior = i;
            }
            else if (media < menor_media)
            {
                menor_media = media;
                ind_menor = i;
            }
            if (aluno[i].prova[0] > maior_prim_prova)
            {
                maior_prim_prova = aluno[i].prova[0];
                ind_maior_prim_prova = i;
            }
        }
        printf("%s\t%.2f\t%s\n", aluno[i].nome, media, (media < 6) ? "Reprovado" : "Aprovado");
    }
    printf("\nMaior nota na primeira prova: %s com %.2f\n", aluno[ind_maior_prim_prova].nome, aluno[ind_maior_prim_prova].nota[0]);
    printf("Aluno com maior média geral: %s com %.2f\n", aluno[ind_maior_media].nome, maior_media);
    printf("Aluno com menor média geral: %s com %.2f\n", aluno[ind_menor_media].nome, menor_media);
    return 0;
}
