/*Polinômios podem ser representados por meio de listas, cujos nós são registros com 3
campos: coeficiente, expoente e referência ao seguinte. Por exemplo, o polinômio

3x5 + 2x –1

seria representado por:/*/

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

typedef struct lista {
    int num;
    int potencia;
    struct lista *prox;
} Lista;

void grupo();
void inserir(int p);
void inserirLista(int p, int num, int potencia);
Lista* getEqualOrGreater(int potencia);
void somar();
void insereSoma(Lista *novo);
void imprimirSoma(Lista *aux, char op[]);
void limpar(int p);

Lista *inicioP1 = NULL;
Lista *inicioP2 = NULL;
Lista *inicioSoma = NULL;

int main() {
    setlocale(LC_ALL, "");

    grupo();

    inserir(1);
    inserir(2);


    printf("\n ################ SOMA ###############\n");
    somar();

    limpar(1);
    limpar(2);

    return 0;
}

void inserir(int p) {
    int num, potencia;

    printf("\nInsira o valor -1 e potência -1 para sair ");
    int i = 3;
    if (p == 1) {
        i = 4;
    } else {
        i = 3;
    }
    do {
        printf("\nValor: ");
        scanf("%d", &num);
        // num = i;
        printf("\nPotência de x: ");
        scanf("%d", &potencia);
        //potencia = i;
        i--;
        if (num == -1 && potencia == -1) {
            break;
        } else {
            inserirLista(p, num, potencia);
        }
    } while (1);
}

void inserirLista(int p, int num, int potencia) {

    Lista *novo = (Lista *) malloc(sizeof (Lista));

    if (novo == NULL) {
        printf("ERRO: Memória insuficiente !\n");
        return;
    }

    novo->num = num;
    novo->potencia = potencia;
    novo->prox = NULL;

    Lista *polinomios;
    if (p == 1) {
        polinomios = inicioP1;
    } else {
        polinomios = inicioP2;
    }

    if (polinomios == NULL) {
        if (p == 1) {
            inicioP1 = novo;
        } else {
            inicioP2 = novo;
        }
        return;
    }
    Lista *aux = polinomios;
    Lista *temp = NULL;

    while (aux != NULL) {
        if (novo->potencia > aux->potencia) {
            if (temp == NULL) {
                novo->prox = aux;
                if (p == 1) {
                    inicioP1 = novo;
                } else {
                    inicioP2 = novo;
                }
            } else {
                temp->prox = novo;
                novo->prox = aux;
            }
            return;
        } else {
            if (novo->potencia == aux->potencia) {
                aux->num += novo->num;
                free(novo);
                return;
            }
        }
        temp = aux;
        aux = aux->prox;
    }

    temp->prox = novo;
}

void somar() {
    Lista *p1 = inicioP1;
    Lista *p2 = inicioP2;
    Lista *aux = NULL;


    if (p1 == NULL && p2 != NULL) {
        inicioSoma = p2;
        imprimirSoma(inicioP1, "+");
        imprimirSoma(inicioP2, "=");
        imprimirSoma(inicioSoma, "");
        return;
    }

    if (p1 != NULL && p2 == NULL) {
        inicioSoma = p1;
        imprimirSoma(inicioP1, "+");
        imprimirSoma(inicioP2, "=");
        imprimirSoma(inicioSoma, "");
        return;
    }

    imprimirSoma(inicioP1, "+");
    imprimirSoma(inicioP2, "=");

    while (p1 != NULL) {
        aux = getEqualOrGreater(p1->potencia);
        if (aux == NULL) {
            Lista *novo = (Lista *) malloc(sizeof (Lista));
            novo->num = p1->num;
            novo->potencia = p1->potencia;
            insereSoma(novo);
            p1 = p1->prox;
            continue;
        }
        if (p1->potencia < aux->potencia) {
            insereSoma(aux);
            continue;
        }

        if (p1->potencia == aux->potencia) {
            aux->num += p1->num;
            insereSoma(aux);

        }
        p1 = p1->prox;
    }


    imprimirSoma(inicioSoma, "");

}

Lista* getEqualOrGreater(int potencia) {
    Lista *aux = inicioP2;
    Lista *temp = NULL;
    Lista *novo = (Lista *) malloc(sizeof (Lista));

    if (novo == NULL) {
        printf("ERRO: Memória insuficiente !\n");
        return NULL;
    }

    while (aux != NULL) {
        if (aux->potencia >= potencia) {

            novo->num = aux->num;
            novo->potencia = aux->potencia;
            novo->prox = NULL;

            if (temp == NULL) {
                temp = inicioP2->prox;
                free(inicioP2);
                inicioP2 = temp;
            } else {
                temp->prox = aux->prox;
                free(aux);
                aux = temp->prox;

            }

            return novo;
        }

        temp = aux;
        aux = aux->prox;
    }
    return NULL;
}

void insereSoma(Lista *novo) {
    novo->prox = NULL;

    if (inicioSoma == NULL) {
        inicioSoma = novo;
        return;
    }

    Lista *temp = inicioSoma;

    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo;
}


void imprimirSoma(Lista *aux, char op[]) {
    printf("(");
    while (aux != NULL) {
        if (aux->num != 0) {
            printf(" %s%d", (aux->num >= 0 ? "+" : ""), aux->num);
            if (aux->potencia > 0) {
                printf("x^(%d)", aux->potencia);

            }
        }
        aux = aux->prox;
    }
    printf(") %s ", op);

    return;

}

void limpar(int p) {
    Lista *aux = (p == 1 ? inicioP1 : inicioP2);

    Lista *temp;

    while (aux != NULL) {
        temp = aux->prox;
        free(aux);
        aux = temp;

    }


}

void grupo() {

}
