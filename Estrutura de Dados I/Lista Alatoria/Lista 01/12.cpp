/*Faça um programa que leia um inteiro n e:
• Crie e leia um vetor com os dados de n carros: marca (máximo 15 letras), ano e
preço.
• Leia um valor p e mostre as informações de todos os carros com preço menor que
p. Repita este processo até que seja lido um valor p = 0./*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  car
{
    char marca[15];
    int ano;
    float preco;
} Carro;


int main()
{
    int i, n;
    float p;
    printf("\tDigite o numero de carros a serem cadastrados: ");
    scanf("%d", &n);
    printf("\n");
    Carro carros[n];
    for(i = 0; i < n; i++)
    {
        printf("\tDigite a marca do %d carro: ", i+1);
        scanf("%s", carros[i].marca);
        printf("\tDigite o ano do %d carro: ", i+1);
        scanf("%d", &carros[i].ano);
        printf("\tDigite o preco do %d carro: ", i+1);
        scanf("%f", &carros[i].preco);
        printf("\n");
    }
    printf("\tDigite um preco limite ou 0 para encerrar o programa: ");
    scanf("%f", &p);
    while(p!= 0)
    {
        for(i = 0; i < n; i++)
        {
            if(carros[i].preco <= p)
            {
                printf("\tMarca: %s\n", carros[i].marca);
                printf("\tAno: %d\n", carros[i].ano);
                printf("\tPreco: %.2f\n", carros[i].preco);
                printf("\n");
            }
        }
        printf("\tDigite um preço limite ou 0 para encerrar o programa: ");
        scanf("%f", &p);
    }
    return 0;
}
