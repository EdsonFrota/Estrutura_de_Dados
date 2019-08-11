#include<stdio.h>
#define tamanho 10
void selection_sort(int v[])
{
    int i, j, aux, menor;
    for(i = 0; i < tamanho; i++)
    {
        menor = i;
        for(j = i+1; j < tamanho; j++)
        {
            if( v[j] < v[menor] )
                menor = j;
        }
        if( i != menor )
        {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}

int main()
{
    int i, vetor[tamanho] = {25,11,97,96,1,5,2,3,4,12};
    printf("Vetor atual: ");
    for(i = 0; i < tamanho; i++)
        printf( "%i ", vetor[i]);
    printf(" \n ");

    selection_sort(vetor);

    printf(" \n\nVetor ordenado: ");
    for(i = 0; i < tamanho; i++)
        printf( "%i ", vetor[i]);
    printf( "\n" );

    return (0);
}
