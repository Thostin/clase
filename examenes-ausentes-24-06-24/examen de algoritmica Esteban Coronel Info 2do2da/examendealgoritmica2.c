//tema 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int alumnos, afectados, temperatura;
    srand(time(NULL));
    do
    {
     alumnos = rand() % 31;
     afectados = rand() % 12;
     temperatura = rand() % 41;
    } while ((alumnos<20 || alumnos > 30)||(afectados < 5 || afectados > 12)||(temperatura < 37 || temperatura > 40));
    printf("El total de alumnos en el aula es %d, de ellos estan afectados %d por la enfermedad, y la temperatura que estan sufriendo es %d grados centigrados.\n", alumnos, afectados, temperatura);
    return 0;
}