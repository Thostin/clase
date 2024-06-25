#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));

    int alum = rand()%30;
    int alumnos = 0;
    while (alum < 20)
    {
        alum = rand()&30;
    }
    alumnos = alum;

    int afec = rand()%11;
    int afectada = 0;
    while (afec < 5)
    {
        afec = rand()&11;
    }
    afectada = afec;

    int tempe = rand()%40;
    int temperatura = 0;
    while (tempe < 37)
    {
        tempe = rand()&40;
    }
    temperatura = tempe;

    printf("El total de alumnos en el aula es %d, de ellos estan afectados %d por la enfermedad, y la temperatura que estan sufriendo es %d grados centigrados\n", alumnos, afectada, temperatura);
    return 0;
}