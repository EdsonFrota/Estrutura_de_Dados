#include<stdio.h>

int Pesquisa_Binaria (int numero, int vetor[], int limite_inferior, int limite_superior)
{
    int meio = (limite_inferior + limite_superior) / 2;

    if (vetor[meio] == numero)
    {
        printf("Nenhum numero encontrado!\n");
        return (0);
    }

    if (limite_inferior >= limite_superior)
    {
        return (-1);
    }

    else
    {
        if (vetor[meio] < numero)
        {
            return (Pesquisa_Binaria(numero, vetor, meio+1, limite_superior));
        }
        else
        {
            return (Pesquisa_Binaria(numero, vetor, limite_inferior, meio-1));
        }
    }
}

int main()
{

    int vetor[20]= {0,5,5,8,10,13,16,17,29,31,34,36,43,49,51,11,55,65,32,33,66,90,2};
    int numero = 34;

    Pesquisa_Binaria(numero, vetor, 0, 17);

    return(0);
}
