#include<stdio.h>

void BubbleSort(int vetor[], int n)
{
    int i, j, aux;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(vetor[j]>vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}
int main ()
{
    int i, n, vetor[100];
    printf("n:");
    scanf("%i",&n);

    for(i=0; i<n; i++)
    {
        printf("%i",vetor[i]);
    }
    BubbleSort(vetor, n);
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%i",vetor[i]);
    }
}
