/*18. Faça um programa em C que resolva o problema da Torre de Hanoi, sem usar recursividade.
O programa deverá usar uma lista que implementa a pilha do programa para simular as
chamadas recursivas.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define MAX 20
int vazia (int **s, int topo);
int empilha (int **s, int *topo, int *x, int Nmax);
int desempilha(int **s, int *topo, int **y);
void limpaPino(int i, char c);
int pinoVazio(int i);
int empilhaNoPino(int i, int x);
int desempilhaDoPino(int i, int *x);
int * novaTarefa(int quant, int origem, int aux, int destino);
void TH(int *tarefaInicial);
int mov, debug, quiet, silent;
int PINO[3][MAX];
int TopoPino[3];
char id[3];
int main (int argc, char **argv){
	int n, j;
	int c, index;
	extern char *optarg;
    extern int optind, optopt, opterr;

	n = 0;
	debug = 0;
	quiet = 0;
	opterr = 0;
	while ( (c = getopt (argc, argv, "dqsn:")) != -1 )
		switch (c) {
			case 'd':
				debug = 1;
				break;
			case 'q':
				quiet = 1;
				break;
			case 's':
				silent = 1;
				quiet = 1;
				break;
			case 'n':
				n = atoi(optarg);
				break;
			case '?':
				if (optopt == 'n')
					fprintf (stderr, "Opção -%c requer um argumento, o número de argolas, que é inteiro positivo e menor que %d.\n", optopt, MAX);
				else if ( isprint (optopt) )
					fprintf (stderr, "Opção `-%c' desconhecida.\n", optopt);
				else
					fprintf ( stderr,
						"Caractere `\\x%x' de opção desconhecido .\n", 						optopt );
				return 1;
			default:
				abort ();
		}
	if ( debug == 1 ) {
		printf("Entrando no modo de depuração...\n\n");
	}
	for ( index = optind; index < argc; index++ )
		printf ("Argumento não válido: %s\n", argv[index]);
	if ( n <= 0 ) {
		printf("Digite um inteiro n (<= %d), o número de argolas: ", MAX);
		scanf("%d", &n);
	} else {
		printf("O número de argolas, n : %d.\n", n);
	}
	mov = 1;

	limpaPino(0, 'A');
	limpaPino(1, 'B');
	limpaPino(2, 'C');
	for(j = n; j > 0; j--) {
		empilhaNoPino(0, j);
	}
	TH(novaTarefa(n, 0, 1, 2));
	printf("\nTerminado em %d movimentos.\n", (mov - 1));
	if (debug <= -1) {
		printf("Algum erro no movimento %d.\n", (-1 * debug));
		return -1;
	} else {
		if (debug == 1) {
			printf("\n...tudo ok.\n");
		}
		return 0;
	}
}
void limpaPino(int i, char c) {
	TopoPino[i] = -1;
	id[i] = c;
}
/* A funcao pinoVazio devolve -1 se o pino i esta vazio e 1, caso contrario. */
int pinoVazio(int i) {
	if(TopoPino[i] == -1)
		return -1;
	else return 1;
}
/* A funcao empilhaNoPino insere um valor x no pino i. */
int empilhaNoPino(int i, int x){
	if(debug == 1){
		if (PINO[i][TopoPino[i]] <= x && TopoPino[i] >= 0)
			debug = -1 * mov; /* erro */
	}
	if(TopoPino[i] < MAX) {
		TopoPino[i] = TopoPino[i] + 1;
		PINO[i][TopoPino[i]] = x;
	    return TopoPino[i];
	}
	else {
		return -2; /* overflow */
	}
}
/* A funcao desempilha remove um elemento no topo do pino i e
	guarda na variável apontada por x. */
int desempilhaDoPino(int i, int *x){
	if(TopoPino[i] == -1)
    	return -2; /* underflow */
	else  {
		*x = PINO[i][TopoPino[i]];
		TopoPino[i] = TopoPino[i] - 1;
		return TopoPino[i];
  }
}
/* A funcao empilha insere um elemento x contendo [n,A,B,C] na pilha s. */
int empilha (int **s, int *topo, int *x, int Nmax){
	int i;
	if(*topo < Nmax) {
		*topo = *topo + 1;
		s[*topo] = x;
		if (quiet != 1) {
			printf("pilha S: [%d,%d,%d,%d] empilhado na posição %d\n",
				s[*topo][0], s[*topo][1], s[*topo][2], s[*topo][3], *topo);
		}
		return *topo;
	}
	else {
		return -2; /* overflow */
	}
}
/* A funcao desempilha remove um elemento no topo da pilha s e
	guarda na variável apontada por *y. */
int desempilha(int **s, int *topo, int **y){
  if(*topo == -1)
    return -2; /* underflow */
  else  {
    *y = s[*topo];
	if (quiet != 1) {
		printf("pilha S: [%d,%d,%d,%d] desempilhado da posição %d\n",
			s[*topo][0], s[*topo][1], s[*topo][2], s[*topo][3], *topo);
	}
	*topo = *topo - 1;
    return *topo;
  }
}
int * novaTarefa(int quant, int origem, int aux, int destino) {
	int *tarefaAux;
	tarefaAux = (int *) malloc(4 * sizeof(int));
	tarefaAux[0] = quant;
	tarefaAux[1] = origem;
	tarefaAux[2] = aux;
	tarefaAux[3] = destino;
	return tarefaAux;
}
void TH(int *tarefa) {
	int ** S;
	int Nmax, topo, x;
	x = 0;
	Nmax = 2 * tarefa[0] - 1;
	S = (int **) malloc(Nmax * sizeof(int *));
	topo = -1;
	empilha (S, &topo, tarefa, Nmax);
	while (topo > -1){
		desempilha(S, &topo, &tarefa);
		if (tarefa[0] == 1) {
			desempilhaDoPino(tarefa[1], &x);
			empilhaNoPino(tarefa[3], x);
			if (silent != 1) {
				printf("\n%d : ", mov);
				printf("mover argola %d de %c para %c", x, id[tarefa[1]], id[tarefa[3]]);
			}
			if (quiet != 1) {
				printf("\nTopos dos pinos: [%d,%d,%d]\n", PINO[0][TopoPino[0]], PINO[1][TopoPino[1]], PINO[2][TopoPino[2]]);
			}
			free(tarefa);
			mov++;
		}
		else {
			empilha (S, &topo,
				novaTarefa(tarefa[0] - 1, tarefa[2], tarefa[1], tarefa[3]), Nmax);
			empilha (S, &topo,
				novaTarefa(1, tarefa[1], tarefa[2], tarefa[3]), Nmax);
			empilha (S, &topo,
				novaTarefa(tarefa[0] - 1, tarefa[1], tarefa[3], tarefa[2]), Nmax);
		}
	}
}
