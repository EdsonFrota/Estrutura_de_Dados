#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//protótipos das funções
int menu();
void LimpaBuffer();
void bubble(int v[], int n);	     // n - tamanho do vetor
void insertion(int v[], int n);
void selection(int v[], int n);
void shell(int v[], int n);
void mergeSort(int vetor[], int inicio, int fim);
void quick(int v[], int c, int f);   // c - começo; f - fim

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
        printf("\n	BUBBLE SORT\n\nEstabilidade: estável\n\nComplexidade(Pior Caso): %d\n\nIn-Place: Sim", tam*tam);
        break;
    case 2:
        insertion(v, tam);
        system("cls");
        printf("\n	INSERTION SORT\n\nEstabilidade: estável\n\nComplexidade(Pior Caso): %d\n\nIn-Place: Sim", tam*tam);
        break;
    case 3:
        selection(v, tam);
        system("cls");
        printf("\n	SELECTION SORT\n\nEstabilidade: não estável\n\nComplexidade(Pior Caso): %d\n\nIn-Place: Sim", tam*tam);
        break;
    case 4:
        shell(v, tam);
        system("cls");
        printf("\n	SHELL SORT\n\nEstabilidade: não estável\n\nComplexidade(Pior Caso): %d\n\nIn-Place: Sim", tam*tam);
        break;
    case 5:
        mergeSort(v, 0, tam-1);
        //merge(v, 0, m);  //parâmetros estão incorretos
        system("cls");
        printf("\n	MERGE SORT\n\nEstabilidade: estável\n\nComplexidade(Pior Caso): %d\n\nIn-Place: Não", tam);
        break;
    case 6:
        quick(v, 0, tam+1);
        system("cls");
        printf("\n	QUICK SORT\n\nEstabilidade: não estável\n\nComplexidade(Pior Caso): %d\n\nIn-Place: Não", tam*tam);
        break;
    }

    //imprime o vetor
    printf("\n\nVetor final : { ");
    for(m = 0; m < tam; m++)
    {
        printf("%d ", v[m]);
    }
    printf("}\n");

    //Fim da contagem de tempo de execução
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n", Tempo);
    getchar();
    printf("\nComparações: %d\n\nTrocas: %d\n", comparacoes, trocas);
    return 0;

    /*
     	complexidade do pior caso
    	pior caso = limite inferior?
    	estável?
    	in-place?
    */
}

int menu()
{
    system("cls");
    int sort;
    do
    {
        printf("\nArquivo lido com sucesso.\n");
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
        for (j = 0; j < n - k; j++)
        {
            if (v[j] > v[j + 1])
            {
                comparacoes++;
                aux = v[j];
                v[j] = v[j + 1];
                trocas++;
                v[j + 1] = aux;
                trocas++;
            }
            comparacoes++;
        }
    }
}

void insertion(int v[], int n)
{
    int i, j, atual;

    for( j=1; j < n; j++ )
    {
        atual = v[j];
        i = j-1;
        while(i >= 0 && v[i] > atual)
        {
            comparacoes++;
            v[i+1] = v[i];
            trocas++;
            i--;
        }
        comparacoes++;
        v[i+1] = atual;
        trocas++;
    }
}

void troca(int *x, int *y)
{
    int temp = *x;
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
            if (v[j] < v[min])
            {
                comparacoes++;
                 min = j;
            }
            comparacoes++;
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
            int j;
            for (j = i; j >= h && v[j - h] > temp; j -= h)
                v[j] = v[j - h];
            v[j] = temp;
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
    while(i <= j)
    {
        while(v[i] < pivo && i < f)
        {
            i++;
        }
        while(v[j] > pivo && j > c)
        {
            j--;
        }
        if(i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    if(j > c)
        quick(v, c, j+1);
    if(i < f)
        quick(v, i, f);
}


void LimpaBuffer()
{
    setbuf(stdin,NULL);
}
