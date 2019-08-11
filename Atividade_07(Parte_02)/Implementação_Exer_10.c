#include<stdio.h>
#include<string.h>

void Inverter_palavra (char *vetor)
{
    if(*vetor)
    {
        Inverter_palavra(vetor+1);
        putchar(*vetor);
    }
}
int main()
{
    char palavra[10];

    printf(" Digite a palavra que deseja inverter:  ");
    scanf("%s", palavra);

    printf("\n Palavra invertida:  ");
    Inverter_palavra(palavra);

    printf(" \n ");

    return (0);
}
