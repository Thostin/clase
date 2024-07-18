#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	int C = 0, suma = 0, iguales = 0, escalera = 0;
	while (C < 100) {
		int dado1 = 1 + rand () % 7;
		int dado2 = 1 + rand () % 7;
		int dado3 = 1 + rand () % 7;
		if (dado1+dado2+dado3==18) {
			suma+=1;
		}
		if (dado1==dado2 && dado2==dado3 && dado1==dado3) {
			iguales+=1;
		}
		if (dado1<=dado2 && dado2<=dado3 || dado1>=dado2 && dado2>=dado3) {
			escalera+=1;
		}
		C++;
	}

	printf ("Cantidad que más veces se presenta como suma total de los dados: %d\n", suma);
	printf ("Veces que dieron el mismo número: %d\n", iguales);
	printf ("Veces que formaron una escalera: %d\n", escalera);
	return 0;
}
