/*Faça um programa que controle o fluxo de voos nos aeroportos de um paıs. Com v=5
(voos) e a=5 (aeroportos) e:
• Crie e leia um vetor de voos, sendo que cada voo contém um código de aeroporto
de origem e um de destino.
• Crie um vetor de aeroportos, sendo que cada aeroporto contém seu código,
quantidade de voos que saem e quantidade de voos que chegam.
Nota: Cada aeroporto e identificado por um código inteiro entre 0 e (a-1). Não aceite
aeroportos de código inexistente./*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int v, a, i;
    struct voo
    {
        int origem;
        int destino;
    };
    struct voo *voos;
    struct aeroporto
    {
        int qtd_saidas;
        int qtd_chegadas;
    };
    struct aeroporto *aeroportos;

    printf("Informe a quantidade de voos e de aeroportos: ");
    scanf("%d %d", &v, &a);

    voos =(struct voo*) malloc(v * sizeof(struct voo));
    for (i=0; i<v; i++)
    {
        printf("Informe o aeroporto de origem e o de destino para o %d voo: ", i+1);
        scanf("%d %d", &voos[i].origem, &voos[i].destino);
        while ((voos[i].origem < 0 || voos[i].origem >= a) || (voos[i].destino < 0 || voos[i].destino >= a))
        {
            printf("Origem e/ou Destino inválido(s). Reinforme o aeroporto de origem e o de destino para o %d voo: ", i+1);
            scanf("%d %d", &voos[i].origem, &voos[i].destino);
        }
    }

    aeroportos = (struct aeroporto*) malloc(a * sizeof(struct aeroporto));
    for (i=0; i<a; i++)
    {
        printf("Informe a quantidade de saídas e chegadas do aeroporto %d: ", i);
        scanf("%d %d", &aeroportos[i].qtd_saidas, &aeroportos[i].qtd_chegadas);
        while (aeroportos[i].qtd_saidas < 0 || aeroportos[i].qtd_chegadas < 0)
        {
            printf("Saidas e/ou chegadas inválida(s). Reinforme a quantidade de saídas e chegadas do aeroporto %d: ", i);
            scanf("%d %d", &aeroportos[i].qtd_saidas, &aeroportos[i].qtd_chegadas);
        }
    }

// Aqui vai o código do controle do fluxo de voos

    free(voos);
    free(aeroportos);
    return 0;
}
