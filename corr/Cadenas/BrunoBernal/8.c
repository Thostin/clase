/*
    Existen números que leídos de izquierda a derecha y de derecha a izquierda tienen el mismo valor.
    Ejemplo: 404, 111, 55, 323, 1045401. Lea un conjunto de números e imprima aquellos números leídos
    que tengan la característica antes anotada.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool esCapicua(char* numero) {  // CApicuatinizador 2: Ahora es personal
    int l = strlen(numero);

    for (int i = 0; i < l / 2; i++) {
        if (numero[i] != numero[l - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char numero[50];
    char capicuas[1000] = "";  // Almacenar los números capicuas

    printf("Introduzca numeros (deje en blanco para parar): \n");

    while (true) {
        fgets(numero, sizeof(numero), stdin);
        numero[strcspn(numero, "\n")] = '\0'; 

        // Salir del bucle
        if (strlen(numero) == 0) {
            break;
        }

        if (esCapicua(numero)) {
            if (strlen(capicuas) > 0) {
                strcat(capicuas, " ");  // Separar los numeros
            }
            strcat(capicuas, numero);  // Agregar el número a la cadena
        }
    }

    printf("Son capicuas: %s\n", capicuas);

    return 0;
}