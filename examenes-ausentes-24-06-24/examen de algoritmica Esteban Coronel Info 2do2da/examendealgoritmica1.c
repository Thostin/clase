//tema 1
#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, ptasignado, ptobtenidos, aprobado = 0;
    int alumnos[5]; 
    float eliminado = 0, ptfaltantes, ptfaltantesparaelmin;
    for (i = 0; i < 5; i++) {
        printf("Ingrese el identificador del alumno %d: ", i + 1);
        scanf("%d", &alumnos[i]);
    }
    printf("Ingrese el puntaje asignado: ");
    scanf("%d", &ptasignado);
    for (i = 0; i < 5; i++) {
    printf("Ingrese los puntajes obtenidos por el alumno %d: ", i + 1);
    scanf("%d", &ptobtenidos);
    ptfaltantes = ptasignado - ptobtenidos;
    ptfaltantesparaelmin = (ptasignado * 0.7) - ptobtenidos;
    if (ptasignado * 0.7 <= ptobtenidos) {
        aprobado++;
        printf("El alumno %d aprobó con %d puntos. Puntos faltantes para el total puntaje: %f\n", i + 1, ptobtenidos, ptfaltantes);
    } else {
        eliminado++;
        printf("El alumno %d ha sido eliminado con %d puntos. Puntos faltantes para el minimo: %f\n", i + 1, ptobtenidos, ptfaltantesparaelmin);
    }
}
    printf("Los alumnos aprobados son: %d\n", aprobado);
    printf("Los alumnos eliminados son: %f\n", eliminado);
    return 0;
}