#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int alumnos, afectada, temperatura;
    
    srand(time(NULL));

    //Minimo numero + el numero que da el maximo
    alumnos = rand() % 11 + 20;
    afectada = rand() % 7 + 5;
    temperatura = rand() % 4 + 37;

    printf("El total de alumnos es %d, de ellos estan afectados por la enfermedad %d, y la temperatura que estan sufriendo es de %d grados centigrados", alumnos, afectada, temperatura);
    return 0;
}