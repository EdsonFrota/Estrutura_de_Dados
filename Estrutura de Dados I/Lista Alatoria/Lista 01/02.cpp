/*Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-
se ter os seguintes dados:

• Nome
• E-mail
 Endereço (contendo campos para Rua, número, complemento, bairro, CEP, cidade,
estado, país)
• Telefone (contendo campo para DDD e número)
• Data de aniversário (contendo campo para dia, mês, ano)
• Observações: Uma linha (string) para alguma observação especial*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct agenda
{
    char nome[40];
    int dia;
    int mes;
    int ano;
};

int main ()
{

    int x, y, z, t, i, j;
    char nomedeletado;

    printf ("Essa eh sua agenda virtual! \n\nSe você quiser preenche-la, digite 1. Se você quiser sair, digite 2:");
    scanf ("%d", &y);
    switch (y)
    {
    case 1:
        i=0;
        printf ("Digite o nome de um contato: ");
        scanf ("%s", &agenda.nome);
        printf ("Digite a data do seu aniversario no formato dia/mes/ano:");
        scanf ("%d/%d/%d", &agenda.dia, &agenda.mes, &agenda.ano);
        do
        {
            printf ("Se voce quiser continuar preenchendo a agenda, digite 1. Caso queira sair, digite 2:");
            scanf ("%d", &z);
            switch (z)
            {
            case 1:
                i++;
                printf ("Digite o nome de um contato: ");
                scanf ("%s", &agenda.nome);
                printf ("Digite a data do seu aniversario no formato dia/mes/ano:");
                scanf ("%d/%d/%d", &agenda.dia, &agenda.mes, &agenda.ano);
            }
            if (i==99)
            {
                break;
            }
        case 2:
            break;
        }
        while (z!=2);
    } // switch 2 ;
case 2:
    break;

default:
    printf ("Opcao invalida!");
}


do
{
    printf ("O que voce deseja fazer? \n1.Buscar aniversariantes do mes de um determinado mes\n2.Inserir novo contato\n3.Deletar contato\n4.Imprimir agenda\n5.Sair\n\nDigite um numero:");
    scanf ("%d", &x);
    if (x == 1)
    {
        printf ("Digite o numero de um mes desejado (ex: janeiro = 1, fevereiro = 2");
        scanf ("%d", &t);
        printf ("Os aniversariantes do mes sao:");
        for (j=0; j<100; j++)
        {
            if (t = agenda[j].mes)
            {
                printf ("%s\n", agenda[j].nome);
            }
        }
    }
    if (x == 2)
    {
        i++;
        if (i<99)
        {
            printf ("Digite o nome do seu novo contato");
            scanf ("%s", %agenda.nome);
            printf ("Digite o a data do seu aniversario no formato dia/mes/ano:");
            scanf ("%d/%d/%d", &agenda.dia, &agenda.mes, &agenda.ano);
        }
        if (i>=99(
    {
        printf ("Agenda lotada");
        }
    }

    if (x == 3)
    {
        printf ("Digite o nome do contato que voce deseja deletar: ");
        scanf ("%s", &nomedeletado);

        for (j=0; j<100; j++)
        {
            if (strcmp(agenda[j].nome,nomedeletado)==0)
            {
                strcpy ("", agenda[j].nome);
                agenda.dia="";
                agenda.mes="";
                agenda.ano="";
            }
        }

        if (x == 4)
        {
            for (j=0; j<100; j++)
            {
                printf ("Nome: %s \nData do aniversario: %d/%d/%d\n\n", agenda[j].nome, agenda[j].dia, agenda[j].mes, agenda[j].ano);
            }
        }

    }
}
while (x=!5);
