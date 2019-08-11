/*Faça um programa que armazene em um registro de dados (estrutura composta) os
dados de um funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F),
CPF, Data de Nascimento, Código do Setor onde trabalha (0-99), Cargo que ocupa
(string de até 30 caracteres) e Salário. Os dados devem ser digitados pelo usuário,
armazenados na estrutura e exibidos na tela./*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{

    char Nome[800];
    int Idade;
    char sexo[1];
    int cpf;
    char Data_Nascimento[10];
    int codigosetor;
    char cargo[30];
    float salario;
} Registro;

int main()
{
    Registro funcionario;
    printf("\tDigite o nome do funcionario: ");
    scanf(" %s", &funcionario.Nome);
    printf("\tDigite a idade do funcionario: ");
    scanf("  %d", &funcionario.Idade);
    printf("\tDigite o sexo (M/F): ");
    scanf(" %s", &funcionario.sexo);
    printf("\tDigite o CPF do funcionario: ");
    scanf(" %d", &funcionario.cpf);
    printf("\tDigite a data de nascimento (dd/mm/aaaa): ");
    scanf(" %s", &funcionario.Data_Nascimento);
    printf("\tDigite o codigo do setor (0 - 99): ");
    scanf(" %d", &funcionario.codigosetor);
    printf("\tDigite o nome do cargo do funcionario: ");
    scanf(" %s", &funcionario.cargo);
    printf("\tDigite o valor do salario do funcionario: ");
    scanf(" %f", &funcionario.salario);


    printf("\n\t\t Dados do Funcionario: \n");
    printf("Nome: %s\n", funcionario.Nome);
    printf("Idade: %d\n", funcionario.Idade);
    printf("Sexo: %s\n", funcionario.sexo);
    printf("CPF:  %d\n", funcionario.cpf);
    printf("Codigo do setor: %d\n", funcionario.codigosetor);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario: %f\n", funcionario.salario);

    return(0);

}
