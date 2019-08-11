/*Considerando a estrutura:
struct Ponto
{
int x;
int y;
};
para representar um ponto em uma grade 2D, implemente um programa que indique
se um ponto p está localizado dentro ou fora de um retângulo. O retângulo e definido
por seus vértices inferior esquerdo v1 e superior direito v2. A função deve imprimir
caso o ponto esteja localizado dentro do retângulo ou não.*/

#include <stdio.h>
int main()
{
    struct Ponto
    {
        int x;
        int y;
    };
    struct Ponto p, v1, v2;
    printf("Informe as coordenadas do vertice inferior esquerdo do retangulo: ");
    scanf("%d %d", &v1.x, &v1.y);
    printf("Informe as coordenadas do vertice superior direito do retangulo: ");
    scanf("%d %d", &v2.x, &v2.y);
    printf("Informe as coordenadas do ponto: ");
    scanf("%d %d", &p.x, &p.y);
    if ((p.x >= v1.x && p.x <= v2.x) && (p.y >= v1.y && p.y <=v2.y))
        printf("O ponto (%d, %d) esta dentro do retangulo os vertices (%d, %d), (%d, %d), (%d, %d) e (%d, %d)\n",
               p.x, p.y, v1.x, v1.y, v2.x, v1.y, v2.x, v2.y, v2.x, v1.y);
    return 0;
}
