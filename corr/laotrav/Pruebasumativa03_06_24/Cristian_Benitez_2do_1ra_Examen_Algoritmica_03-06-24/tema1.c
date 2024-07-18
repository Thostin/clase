#include <stdio.h>
void subprograma (int N) {
	int Clientes [N], Prestigio[N];

	// Cargar el nivel de prestigio inicial de cada cliente.

	for (int i = 0; i < N; i++) {
		Prestigio[i] = 0;
	}

	// Cargar la cantidad de préstamos de cada cliente.

	for (int i = 0; i < N; i++) {
		printf ("Ingrese la cantidad de préstamos del cliente\n");
		scanf ("%d", &Clientes[i]);
		while (Clientes[i] < 1 || Clientes[i] > 2) {
			printf ("ERROR\n");
			scanf ("%d", &Clientes[i]);
		}
	}

	// Ingresar los meses de retraso.

	int m, mayor = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < Clientes[i]; j++) {
			printf ("Ingrese los meses de retraso del cliente %d\n", i);
			scanf ("%d", &m);
			while (m < 0 || m > 3) {
				printf ("ERROR\n");
				scanf ("%d", &m);
			}

			if (m==1) {
				Prestigio [i]-=1;
			}
			else if (m==2) {
				Prestigio [i]-=3;
			}

			else if (m==3) {
				Prestigio [i]-=6;
			}

			if (mayor<Prestigio[i]) {
				mayor = Prestigio[i];
			}
		}
	}


	// Imprimir el prestigio.

	for (int i = 0; i < N; i++) {
		if (Prestigio[i] == mayor) {
			printf ("---------CLIENTE %d ES EL MÁS PRESTIGIOSO---------\n", i);
			printf ("Prestigio: %d\n", Prestigio[i]);

		}
		else {
			printf ("Prestigio del cliente %d: %d\n", i, Prestigio[i]);
		}
	}

}


int main () {
	int N;
	printf ("Ingrese la cantidad de clientes\n");
	scanf ("%d", &N);
	while (N < 1) {
		printf ("ERROR");
		scanf ("%d", &N);
	}
	subprograma (N);
	return 0;
}
