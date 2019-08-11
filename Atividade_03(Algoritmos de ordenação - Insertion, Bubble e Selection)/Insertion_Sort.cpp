#include <stdio.h>
#define maximo 10

void insertion_sort(int *posicao);
int main(int argc, char** argv)
{
    int i, vetor[maximo];

    printf("Informe os elementos do vetor:\n");

    for(i = 0; i < maximo; i++)
    {
        scanf(" %i", &vetor[i]);
    }

    insertion_sort(vetor);

    printf("\nValores ordenados:\n");
    for(i = 0; i < maximo; i++)
    {
        printf(" \n%i ", vetor[i]);
    }

    return (0);
}

void insertion_sort(int *posicao)
{
    int i, j, x;
    for(i = 1; i < maximo; i++)
    {
        x = posicao[i];
        for(j = i-1; j >= 0 && x < posicao[j]; j--)
        {
            posicao[j+1] = posicao[j];
        }
        posicao[j+1] = x;
    }
}
