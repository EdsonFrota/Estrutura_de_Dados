#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define NOME_ARQUIVO "Vetor de Entrada.txt"

//protótipos das funções
int menu();
void LimpaBuffer();
void bubble(int v[], int n);	     // n - tamanho do vetor
void insertion(int v[], int n);
void selection(int v[], int n);
void shell(int v[], int n);
void mergeSort(int vetor[], int inicio, int fim);
void quick(int v[], int c, int f);   // c - começo; f - fim
void LerArquivos(int tam);
void ImprimeVetor(int v[], int tam);

int trocas, comparacoes;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = 1, m = 0, sort;
    int i = 0, tam;

    printf("Digite o tamanho do vetor do arquivo:\n");
    scanf("%d", &tam);
    LimpaBuffer();
    int v[tam];
    //Abre o arquivo
    FILE *arq = fopen(NOME_ARQUIVO, "r");
    //Verifica se o arquivo é nulo
    if(arq == NULL)
        printf("O arquivo não foi encontrado.");
    //Percorre o arquivo até a última linha
    while ((fscanf(arq,"%d\n", &v[i])) != EOF)
    {
        ++i;
        LimpaBuffer();
    }

    //Fecha o arquivo
    fclose(arq);

    int size = sizeof(v)/sizeof(v[0]);

    sort = menu();	 //opção de ordenação

    clock_t Ticks[2];   // início da contagem de tempo de execução do programa
    Ticks[0] = clock();

switch(sort)
    {
    case 1:
        bubble(v, tam);
        system("cls");
        ImprimeVetor(v,tam);
        printf("\nBUBBLE SORT\n\nEstabilidade: Estável\n\nComplexidade(Pior Caso): O(n^2)\n\nIn-Place: Sim\n");
        break;
    case 2:
        insertion(v, tam);
        system("cls");
        ImprimeVetor(v,tam);
        printf("\nINSERTION SORT\n\nEstabilidade: Estável\n\nComplexidade(Pior Caso): O(n^2)\n\nIn-Place: Sim\n");
        break;
    case 3:
        selection(v, tam);
        system("cls");
        ImprimeVetor(v,tam);
        printf("\nSELECTION SORT\n\nEstabilidade: Não estável\n\nComplexidade(Pior Caso): O(n^2)\n\nIn-Place: Sim\n");
        break;
    case 4:
        shell(v, tam);
        system("cls");
        ImprimeVetor(v,tam);
        printf("\nSHELL SORT\n\nEstabilidade: Não estável\n\nComplexidade(Pior Caso): O(n^2)\n\nIn-Place: Sim\n");
        break;
    case 5:
        mergeSort(v, 0, tam-1);
        system("cls");
        ImprimeVetor(v,tam);
        printf("\nMERGE SORT\n\nEstabilidade: Estável\nComplexidade(Pior Caso): O(nlog(n))\nIn-Place: Não\n");
        break;
    case 6:
        quick(v, 0, tam);
        system("cls");
        ImprimeVetor(v,tam);
        printf("\nQUICK SORT\n\nEstabilidade: Não estável\n\nComplexidade(Pior Caso): O(n^2)\n\nIn-Place: Não\n");
        break;
    }
      Ticks[1] = clock();
    //Fim da contagem de tempo de execução
    double Tempo = (Ticks[1] - Ticks[0])/(CLOCKS_PER_SEC/1000);
    printf("\nTempo gasto: %g ms.\n", Tempo);
    getchar();
    printf("\nComparações: %d\n\nTrocas: %d\n", comparacoes, trocas);
    return 0;
}

int menu()
{
    system("cls");
    int sort;
    do
    {
        printf("\n=== OPÇÕES DE ORGANIZAÇÃO ===");
        printf("\n1== Bubble Sort");
        printf("\n2== Insertion Sort");
        printf("\n3== Selection Sort");
        printf("\n4== Shell Sort");
        printf("\n5== Merge Sort");
        printf("\n6== Quick Sort");
        printf("\n\nMétodo: ");
        scanf("%d", &sort);
    }
    while(sort > 7 && sort < 0);

    return sort;
}

void bubble(int v[], int n)
{
    int k, j, aux;
    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n; j++)
        {
            comparacoes++;
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                trocas++;
                v[j] = v[j + 1];
                trocas++;
                v[j + 1] = aux;
                trocas++;
            }
        }
    }
}

void insertion(int v[], int n)
{
    int i, j, atual;

    for(j = 1; j < n; j++)
    {
        trocas++;
        atual = v[j];
        i = j-1;
        comparacoes++;
        while(i >= 0 && v[i] > atual)
        {
            trocas++;
            v[i+1] = v[i];
            i--;
        }
        trocas++;
        v[i+1] = atual;
    }
}

void troca(int *x, int *y)
{
    int temp = *x;
    trocas++;
    *x = *y;
    trocas++;
    *y = temp;
    trocas++;
}

void selection(int v[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            comparacoes++;
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        troca(&v[min], &v[i]);
    }
}

void shell(int v[], int n)
{
    for (int h = n/2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i += 1)
        {
            int temp = v[i];
            trocas++;
            int j;
            comparacoes = comparacoes + 3;
            for (j = i; j >= h && v[j - h] > temp; j -= h)
                v[j] = v[j - h];
                trocas++;
            v[j] = temp;
            trocas++;
        }
    }
}

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

void quick(int v[], int c, int f)
{
    int i, j, pivo, aux;
    i = c;
    j = f-1;
    pivo = v[(c + f) / 2];
    comparacoes++;
    while(i <= j)
    {
        comparacoes++;
        comparacoes++;
        while(v[i] < pivo && i < f)
        {
            i++;
        }
        comparacoes++;
        comparacoes++;
        while(v[j] > pivo && j > c)
        {
            j--;
        }

        if(i <= j)
        {
            aux = v[i];
            trocas++;
            v[i] = v[j];
            trocas++;
            v[j] = aux;
            trocas++;
            i++;
            j--;
        }
    }
    comparacoes++;
    if(j > c)
        quick(v, c, j+1);
    if(i < f)
        quick(v, i, f);
}

void ImprimeVetor(int v[], int tam)
{   int i;
    printf("\n\nVetor final : { ");
    for(i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("}\n");
}

void LimpaBuffer()
{
    setbuf(stdin,NULL);
}
