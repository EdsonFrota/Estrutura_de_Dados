/*Considerando a estrutura
struct Vetor
{
float x;
float y;
float z;
};
para representar um vetor no R3

, implemente um programa que calcule a soma de dois

vetores.*/

#include<stdlib.h>
#include<stdio.h>

typedef struct vetor Vetor;
Vetor* cria(float x, float y, float z);
void libera(Vetor* v);
Vetor* soma(Vetor* v1, Vetor* v2);
float prodint (Vetor* v1, Vetor* v2);
Vetor* prodvet (Vetor* v1, Vetor* v2);

struct vetor
{
    float x;
    float y;
    float z;
};
Vetor* cria(float x0, float y0, float z0)
{
    Vetor* v=(Vetor*) malloc(sizeof(Vetor));
    v->x=x0;
    v->y=y0;
    v->z=z0;
    return v;
}
void libera(Vetor* v)
{
    free(v);
}
Vetor* soma(Vetor* v1, Vetor* v2)
{
    Vetor *v=cria(v1->x+v2->x, v1->y+v2->y, v1->z+v2->z);
    return v;
}
float prodint (Vetor* v1, Vetor* v2)
{
    float prod = v1->x*v2->x + v1->y*v2->y + v1->z*v2->z;
    return prod;
}
Vetor* prodvet (Vetor* v1, Vetor* v2)
{
    Vetor* pv=(Vetor*) malloc(sizeof(Vetor));
    pv->x = v1->y*v2->z - v1->z*v2->y;
    pv->y = -(v1->x*v2->z - v1->z*v2->x);
    pv->z = v1->x*v2->y - v1->y*v2->x;
    return pv;
}
