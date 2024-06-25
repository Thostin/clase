#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int Alumnos, Afectada, Temperatura;
	srand(NULL);
	//Creación de todos los números aleatorios
	Alumnos = rand()%21+20;
	Afectada = rand()%8+4;
	Temperatura = rand()%+3+37;
	printf ("El total de alumnos en el aula es %d, de ellos están afectados %d por la enfermedad, y la temperatura que están sufriendo es %d grados centígrados", Alumnos, Afectada, Temperatura);
	return 0;
}

