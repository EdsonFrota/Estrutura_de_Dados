/*mudanças em i: 20; em h: 4;
n de movimentações: 24;
n de comparações: 37;

*mudanças em i: 20; em h: 4;
n de movimentações: 17;
n de comparações: 37;

*mudanças em i: 20; em h: 4;
n de movimentações: 29;
n de comparações: 37;

*mudanças em i: 20; em h: 4;
n de movimentações: 19;
n de comparações: 37;
*/
#include<stdio.h>
int main(){
	int v[8];

	v[0] = 45;
	v[1] = 56;
	v[2] = 12;
	v[3] = 43;
	v[4] = 95;
	v[5] = 19;
	v[6] = 8;
	v[7] = 67;

	int aux, i, j;
	int conti = 0;
	int conth = 0;
	int contm = 0;
	int contc = 0;

	int h = 8/2;
	conth++;

	while(h > 0){
		contc++;
		i = h;
		conti++;
		while(i < 8){
			contc++;
			aux = v[i];
			j = i;
			contc++;
			while(j >= h && aux < v[j - h]){
				v[j] = v[j - h];
				contm++;
				j = j -h;
			}
			v[j] = aux;
			contm++;
			i = i +1;
			conti++;
		}
		h = h/2;
		conth++;
	}
		printf("- %d - %d - %d - %d -", conti, conth, contm, contc);
	return (0);
}
