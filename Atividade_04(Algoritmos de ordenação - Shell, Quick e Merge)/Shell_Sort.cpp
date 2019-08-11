#include<stdio.h>
void Shell_Sort(int *ponteiro, int tamanho);

int main(int argc, char** argv)
{
    int dimensao;
    printf("Informe a dimensao do vetor: ");
    scanf("%i ",&dimensao);

    int i, vetor[dimensao];

    for(i = 0; i <dimensao; i++)
    {
        scanf("%i", &vetor[i]);
    }

    Shell_Sort(vetor, dimensao);

    printf("\nValores ordenados:\n");
    for(i = 0; i < dimensao; i++)
    {
        printf("%i\n", vetor[i]);
    }
    return (0);
}
void Shell_Sort(int *ponteiro, int tamanho)
{
    int i , j , contador;
    int posicao = 1;

    do
    {
        posicao = 3 * posicao + 1;
    }
    while(posicao < tamanho);

    do
    {
        posicao /= 3;
        for(i = posicao; i < tamanho; i++)
        {
            contador = ponteiro[i];
            j = i - posicao;

            while (j >= 0 && contador < ponteiro[j])
            {
                ponteiro[j + posicao] = ponteiro[j];
                j -= posicao;
            }
            ponteiro[j + posicao] = contador;
        }
    }
    while(posicao > 1);
}
