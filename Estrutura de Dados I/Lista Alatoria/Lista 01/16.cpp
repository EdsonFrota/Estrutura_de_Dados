/*Faça um programa que controla o consumo de energia dos eletrodomésticos de uma
casa e:
• Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potencia (real,
em kW) e tempo ativo por dia (real, em horas).
• Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo
relativo de cada eletrodoméstico (consumo/consumo total) nesse período de
tempo. Apresente este último dado em porcentagem.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char nome[15];
	float potencia;
	int tempo;
	int tdias;


} Consumo;

int main(){
	int quantidade=2;
	Consumo eletrodomesticos[quantidade];
	int i=0;
	float consumototal;
	float consumo;
	float porcentagem;

	for(i=0;i<quantidade;i++){
		printf("\nInsira o nome, potencia(em kW), tempo ativo por dia(em hrs) e  quantidade de dias em que esta ligado:\n\n");
		scanf("%s %f %d %d", &eletrodomesticos[i].nome, &eletrodomesticos[i].potencia, &eletrodomesticos[i].tempo,&eletrodomesticos[i].tdias);
	}
	for(i=0;i<quantidade;i++){
		printf("ELETRODOMESTICO %i\n\nNOME: %s\nPOTENCIA: %f\nTEMPO ATIVO: %d\nDIAS LIGADO: %d\n\n", i+1, eletrodomesticos[i].nome, eletrodomesticos[i].potencia, eletrodomesticos[i].tempo, eletrodomesticos[i].tdias);
	}
	for(i=0;i<quantidade;i++){

		consumo=eletrodomesticos[i].potencia*eletrodomesticos[i].tempo*eletrodomesticos[i].tdias;
		consumototal+=consumo;
		printf("Consumo %d= %f\n", i+1, consumo);

	}
	printf("Consumo total=%f\n\n", consumototal);

	for(i=0;i<quantidade;i++){
	 porcentagem=consumo/consumototal;

	}
	printf("Porcentagem (1): %.2f porcento\n", (porcentagem*100));
	printf("Porcentagem (2): %.2f porcento\n", (1-porcentagem)*100);
	return 0;
}
