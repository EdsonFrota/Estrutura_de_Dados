#include<stdio.h>
void merge(int vetor[], int inicio, int meio, int fim)
{
    int inicio_A, inicio_B, inicio_Aux, tamanho;
    int *vetAux;

    inicio_A = inicio;
    inicio_B = meio+1;
    inicio_Aux = 0;
    tamanho = fim-inicio+1;

    vetAux = (int*)malloc(tamanho * sizeof(int));
    while(inicio_A <= meio && inicio_B <= fim)
    {
        if(vetor[inicio_A] < vetor[inicio_B])
        {
            vetAux[inicio_Aux] = vetor[inicio_A];
            inicio_A++;
        }
        else
        {
            vetAux[inicio_Aux] = vetor[inicio_B];
            inicio_B++;
        }
        inicio_Aux++;
    }
    while(inicio_A <= meio)
    {
        vetAux[inicio_Aux] = vetor[inicio_A];
        inicio_Aux++;
        inicio_A++;
    }
    while(inicio_B <= fim)
    {
        vetAux[inicio_Aux] = vetor[inicio_B];
        inicio_Aux++;
        inicio_B++;
    }
    for(inicio_Aux = inicio; inicio_Aux <= fim; inicio_Aux++)
    {
        vetor[inicio_Aux] = vetAux[inicio_Aux-inicio];
    }
    free(vetAux);
}
void mergeSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = ( fim + inicio ) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
int main()
{
    int i, dimensao;

    printf("Digite a dimensao do vetor: ");
    scanf("%i", &dimensao);
    int vetor[dimensao];

    for(i = 0; i < dimensao; i++)
    {
        scanf("%i", &vetor[i]);
    }
    mergeSort(vetor, 0, dimensao);

    for( i = 0; i < dimensao; i++)
    {
        printf("%i ", vetor[i]);
    }
    return(0);
}


