#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL));
    
    int alumnos = rand() % 11 + 20;

    while (alumnos < 20 || alumnos > 30) { //en realidad no hace falta usar el while porque el numero ya esta en el rango pero pongo porque aparece en el indicador.
        int alumnos = rand() % 11 + 20;
    }

    int afectados = rand() % 7 + 5;

    while (afectados < 5 || afectados > 11) {
        int alumnos = rand() % 11 + 20;
    }

    int temperatura = rand() % 4 + 37;

    while (temperatura < 37 || alumnos > 40) {
        int alumnos = rand() % 11 + 20;
    }


    printf("El total de alumnos en el aula es %d, de ellos estan afectados %d por la enfermedad y la temperatura que estan sufriendo es de %d grados centigrados.", alumnos, afectados, temperatura);

    return 0;
}