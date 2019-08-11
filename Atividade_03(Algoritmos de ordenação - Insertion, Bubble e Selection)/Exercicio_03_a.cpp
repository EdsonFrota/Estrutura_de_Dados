#include <stdio.h>
void ordenaInsercao (int Vetor[], int tamanho)
{
    int j, k, aux;
    for (k=1; k<tamanho; k++)
    {
        aux = Vetor[k];
        for ( j=k-1; j>=0 && Vetor[j]>aux; j-- )
            Vetor[j+1] = Vetor[j];
        Vetor[j+1] = aux;
    }
}

int main()
{

    int Vetor[6] = {12,8,6,10,23,14}, tamanho, i;
    tamanho = 6;
    ordenaInsercao(Vetor,tamanho);
    printf(" Vetor Ordenado: \n");
    for (i=0; i<tamanho; i++)
    {
        printf(" \n%i ", Vetor[i]);
    }
    return(0);
}
