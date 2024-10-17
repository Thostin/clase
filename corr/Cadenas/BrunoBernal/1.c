/*
    Dado un texto t, formar una lista "diccionario" conteniendo todas las palabras diferentes
    que existen en t, ordenadas alfabéticamente.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    int longitud, palabras = 0, i = 0;
    bool Palabra = false;
    char t[2048];

    printf("Escriba un texto: \n");
    fgets(t, sizeof(t), stdin);         //Pide el texto
    strlwr(t);
    
    longitud = strlen(t);

    if (t[longitud - 1] == '\n') {
        t[longitud - 1] = '\0';       // Elimina el nulo para separar palabras
        longitud--;
    }

    printf("\nCaracteres: %d \n", longitud);   //Estos usaba para comprobar

    for (i = 0; i < longitud; i++) {
        if (isspace(t[i])) {
            Palabra = false;
        } else {
            if (!Palabra) {    // Cuenta las palabras
                palabras++;
                Palabra = true;
            }
        }
    }

    printf("Hay %d palabras.\n", palabras);

    char **diccionario = (char **)malloc(palabras * sizeof(char *));
    if (diccionario == NULL) {
        printf("Error: No se pudo asignar memoria para el diccionario.\n");
        return 1;
    }

    i = 0;
    char *palabra = strtok(t, " ,.;:-");
    while (palabra != NULL && i < palabras) {
        diccionario[i] = (char *)malloc((strlen(palabra) + 1) * sizeof(char));
        strcpy(diccionario[i], palabra);       // Separa las palabras
        i++;
        palabra = strtok(NULL, " ,.;:-");
    }

    for (i = 0; i < palabras - 1; i++) {
        for (int j = 0; j < palabras - i - 1; j++) {
            if (strcmp(diccionario[j], diccionario[j + 1]) > 0) {
                char *temp = diccionario[j];                        // Ordenar alfabéticamente
                diccionario[j] = diccionario[j + 1];
                diccionario[j + 1] = temp;
            }
        }
    }

    // Imprimir las palabras ordenadas alfabeticamenet
    printf("Las palabras ordenadas alfabeticamente:\n");
    for (i = 0; i < palabras; i++) {
        printf("%s\n", diccionario[i]);
        free(diccionario[i]);
    }
    free(diccionario);  // Igual este ejercicio no explicó bien kuri la coooordi

    return 0;
}