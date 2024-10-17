/*
    Dado un texto, codificar su contenido cambiando cada letra por la que le sigue en el alfabeto.
    La letra "z" se reemplaza por la "a".
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char t[2048];

    printf("Escriba un texto: \n"); // recibe el texto
    fgets(t, sizeof(t), stdin);
    strlwr(t);  // Convierte a minúscula para facilitar el traajo

    for (int i = 0; t[i] != '\0'; i++) {
        if (t[i] >= 'a' && t[i] <= 'z') {
            if (t[i] == 'z') {     // Cambia su valor ASCII
                t[i] = 'a';
            } else {
                t[i] = t[i] + 1;
            }
        }
    }
    
    printf("Texto codificado : %s\n", t);  // Imprime el texto codificado

    return 0;
}