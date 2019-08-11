/*Escreva um trecho de código em C para fazer a criação dos novos tipos de dados
conforme solicitado abaixo:
• Horário: composto de hora, minutos e segundos.
• Data: composto de dia, mês e ano.
• Compromisso: composto de uma data, horário e texto que descreve o
compromisso.
• Byte: usado para armazenar 8 bits (definido em função dos tipos básicos da
linguagem C).*/

#include <stdio.h>

int main ()
{
    struct info
    {
        char nome [100];
        int matricula;
        float mediaFinal;
    };

    struct info dados[3], aprovados[3], reprovados[3];
    int i;
    for (i=0; i<3; ++i)
    {
        printf ("Digite o nome do aluno %i: " , i + 1);
        scanf ("%s", dados[i].nome);
        printf ("Digite a matricula do aluno %i: ", i + 1);
        scanf ("%i", &dados[i].matricula);
        printf ("Digite a media final do aluno %i: ", i + 1);
        scanf ("%f", &dados[i].mediaFinal);
        if (dados[i].mediaFinal<5)
        {
            reprovados[i]=dados[i];
        }
        else aprovados[i]=dados[i];
    }
    for (i=0; i<3; ++i)
    {
        printf ("Aprovados\n Nome: %s\n, Matricula: %i\n, Media Final: %f\n",aprovados[i].nome,
                aprovados[i].matricula,
                aprovados[i].mediaFinal);
    }
    printf ("\n");
    for (i=0; i<3; ++i)
    {
        printf ("Reprovados\n Nome: %s\n, Matricula: %i\n, Media Final: %f\n",reprovados[i].nome,
                reprovados[i].matricula,
                reprovados[i].mediaFinal);
    }

}
