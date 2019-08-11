/*Escreva um programa que receba dois structs do tipo dma, cada um representando
uma data valida, e calcule o número de dias que decorreram entre as duas datas.
struct dma {
int dia;
int mes;
int ano;
};*/

#include <stdio.h>
#include <stdbool.h>

struct dma
{
    int dia;
    int mes;
    int ano;
};

bool valida(struct dma data)
{
    /* retorna true se data válida ou false se inválida */
    if (data.mes < 1 || data.mes > 12)
        return false;
    else
    {
        if (data.mes == 2)
        {
            if ((data.ano % 4 == 0) && (data.ano % 100 != 0) || (data.ano % 400 == 0))
            {
                if (data.dia < 1 || data.dia > 29)
                    return false;
            }
            else if (data.dia < 1 || data.dia > 28)
                return false;
        }
        else
        {
            if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
            {
                if (data.dia < 1 || data.dia > 30)
                    return false;
            }
            else if (data.dia < 1 || data.dia > 31)
                return false;
        }
    }
    return true;
}

int dias_decorridos(struct dma data_ini, struct dma data_fim)
{
    int dias_no_mes[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, tot_dias_ini, tot_dias_fim, i;
    tot_dias_ini = data_ini.ano * 365.2425;
    for (i=1; i<data_ini.mes; i++)
        tot_dias_ini += dias_no_mes[i];
    if (((data_ini.ano % 4 == 0) && (data_ini.ano % 100 != 0) || (data_ini.ano % 400 == 0)) && data_ini.mes > 2)
        tot_dias_ini++;
    tot_dias_ini += data_ini.dia;

    tot_dias_fim = data_fim.ano * 365.2425;
    for (i=1; i<data_fim.mes; i++)
        tot_dias_fim += dias_no_mes[i];
    if (((data_fim.ano % 4 == 0) && (data_fim.ano % 100 != 0) || (data_fim.ano % 400 == 0)) && data_fim.mes > 2)
        tot_dias_fim++;
    tot_dias_fim += data_fim.dia;

    return (tot_dias_fim - tot_dias_ini);
}


int main()
{
    struct dma data1, data2;
    printf("Informe a primeira data: ");
    scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);
    while (!valida(data1))
    {
        printf("Data inválida. Reinforme a primeira data: ");
        scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);
    }
    printf("Informe a segunda data: ");
    scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);
    while (!valida(data2))
    {
        printf("Data inválida. Reinforme a segunda data: ");
        scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);
    }
    printf("Dias decorridos: %d\n", dias_decorridos(data1, data2));
    return 0;
}
