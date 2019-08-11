#include<stdio.h>

void BubbleSort(int vetor[], int tamanho_Vetor)
{
    int i, j, aux;
    for(i = 0; i < tamanho_Vetor - 1; i++)
    {

        for( j = 0; j < (tamanho_Vetor -(i +1)); j++)
        {

            if(vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void Concatenar(int vetor_1[], int vetor_2[], int tamanho_Vetor)
{
    int j, vetor_3[tamanho_Vetor];
    for(j = 0; j < tamanho_Vetor; j++)
    {
        vetor_3[j] = vetor_1[j] + vetor_2[j];
        printf("\n%i ", vetor_3[j]);
    }
}

int main()
{
    int tamanho , i;

    printf("Digite a dimensao do vetor: ");
    scanf("%i", &tamanho );

    int vetor_1[tamanho];
    int vetor_2[tamanho];

    printf("\nInforme os elementos dos vetores:\n");

    printf("\nPRIMEIRO VETOR: \n");
    for(i = 0; i < tamanho; i++)
    {
        scanf("%i", &vetor_1[i]);
    }

    printf("\nSEGUNDO VETOR: \n");
    for(i = 0; i < tamanho; i++)
    {
        scanf("%i", &vetor_1[i]);
    }

    printf("\nResultado: \n");
    BubbleSort(vetor_1, tamanho);
    BubbleSort(vetor_1, tamanho);
    Concatenar(vetor_1, vetor_1, tamanho);

}


