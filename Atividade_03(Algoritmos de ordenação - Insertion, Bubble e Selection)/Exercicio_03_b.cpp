#include <stdio.h>
void ordenaInsercaoD(int Vetor[], int tamanho)
{
    int j, k, aux;
    for (k = 1; k < tamanho; k++)
    {
        j = k;
        while (j > 0 && Vetor[j - 1] < Vetor[j])
        {
            aux = Vetor[j];
            Vetor[j] = Vetor[j - 1];
            Vetor[j - 1] = aux;
            j--;
        }
    }
}

int main()
{
    int Vetor[6] = {12,8,6,10,23,14}, tamanho, i;
    tamanho = 6;
    ordenaInsercaoD(Vetor,tamanho);
    printf("Vetor Ordenado: \n");
    for (i=0; i<tamanho; i++)
    {
        printf(" \n%i ", Vetor[i]);
    }

    return(0);
}
