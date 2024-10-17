/*
    Obtener el diminutivo de un nombre dado. Ejemplo: Pedro --> Pedrito.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char nombre[15];
    char nombreDiminutivo[20];

    printf("Introduzca un nombre: ");
    scanf("%s", nombre);

    int len = strlen(nombre);

    strcpy(nombreDiminutivo, nombre);  // Copia el nombre a una cadena diferente

    if (nombreDiminutivo[len - 1] != 'a') {  // Casi todos los nombres femeninos terminan en "a", pero no todos los masculinos terminan en "o".
        nombreDiminutivo[len - 1] = 'i';
        strcat(nombreDiminutivo, "to");
    } else {
        nombreDiminutivo[len - 1] = 'i';
        strcat(nombreDiminutivo, "ta");
    }

    printf("El diminutivo es: %s\n", nombreDiminutivo);

    return 0;
}