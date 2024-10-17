/*
    Verificar si un número es capicúa.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void capicuatinizador(char* numero, bool* esCapicua) {

    int l = strlen(numero);

    for (int i = 0; i < l / 2; i++) {
        if (numero[i] != numero[l - 1 - i]) {   // Compara los dígitos
            *esCapicua = false;
            break;
        }
    }
}

int main() {

    char numero[2048];
    bool esCapicua = true;  // booleano

    printf("Introduzca un numero: ");
    scanf("%s", numero);

    capicuatinizador(numero, &esCapicua);  // llama la función

    if (esCapicua) {
        printf("El numero %s es capicua. \n", numero);
    } else {                                                // Imprime si es o no capicúa
        printf("El numero %s no es capicua. \n", numero);
    }
    
    return 0;
}