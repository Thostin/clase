/*
    Ordenar alfabéticamente una lista de palabras.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    int longitud, palabras = 0, i = 0; // Esto es todo igual al anterior no?
    bool Palabra = false;
    char t[2048];

    printf("Ingrese palabras: \n");
    fgets(t, sizeof(t), stdin);
    strlwr(t);
    
    longitud = strlen(t);

    if (t[longitud - 1] == '\n') {
        t[longitud - 1] = '\0';
        longitud--;
    }

    for (i = 0; i < longitud; i++) {
        if (isspace(t[i])) {
            Palabra = false;
        } else {
            if (!Palabra) {
                palabras++;
                Palabra = true;
            }
        }
    }

    char **diccionario = (char **)malloc(palabras * sizeof(char *));
    if (diccionario == NULL) {
        printf("Error: No se pudo asignar memoria para el diccionario.\n");
        return 1;
    }

    i = 0;
    char *palabra = strtok(t, " ,.;:-");
    while (palabra != NULL && i < palabras) {
        diccionario[i] = (char *)malloc((strlen(palabra) + 1) * sizeof(char));
        strcpy(diccionario[i], palabra);
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
    free(diccionario);

    return 0;
}