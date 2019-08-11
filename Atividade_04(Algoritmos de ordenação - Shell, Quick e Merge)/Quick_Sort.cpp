#include<stdio.h>
void QuickSort(int *vetor, int inicio, int fim)
{
    int i, j, meio, contador;

    i = inicio;
    j = fim;
    meio = vetor[(inicio + fim) / 2];
    do
    {
        while(vetor[i] < meio)
        {
            i++;
        }
        while(vetor[j] > meio)
        {
            j--;
        }
        if(i <= j)
        {
            contador = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = contador;
            i++;
            j--;
        }
    }
    while(i <= j);

    if(inicio < j)
    {
        QuickSort(vetor, inicio, j);
    }
    if(i < fim)
    {
        QuickSort(vetor, i, fim);
    }
}
int main()
{
    int i, tamanho;
    printf("Informe a dimensao do vetor: ");
    scanf("%i", &tamanho);

    int vetor[tamanho];

    for(i = 0; i < tamanho; i++)
    {
        scanf("%i", &vetor[i]);
    }
    QuickSort(vetor,0,tamanho);

    printf("Vetor Ordenado: ");
    for( i = 0; i < tamanho; i++)
    {
        printf("\n%i ", vetor[i]);
    }
    return(0);
}

