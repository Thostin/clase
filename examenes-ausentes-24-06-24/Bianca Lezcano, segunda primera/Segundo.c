#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int Alumnos, Afectada, Temperatura;
	srand(NULL);
	//Creaci�n de todos los n�meros aleatorios
	Alumnos = rand()%21+20;
	Afectada = rand()%8+4;
	Temperatura = rand()%+3+37;
	printf ("El total de alumnos en el aula es %d, de ellos est�n afectados %d por la enfermedad, y la temperatura que est�n sufriendo es %d grados cent�grados", Alumnos, Afectada, Temperatura);
	return 0;
}

