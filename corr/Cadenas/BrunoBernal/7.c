/*
    Desarrollar un algoritmo para jugar AHORCADO. En este juego, uno de los jugadores escribe una palabra secreta
    que debe ser descubierta por el segundo jugador. Como pista inicial se presenta una palabra reemplazada cada
    letra por un asterisco. El jugador propone una letra a la vez y si esta letra existe en la palabra, se vuelve
    a mostrar la palabra, pero colocando la letra en todas las posiciones en que ella aparece. Se cuenta con una
    cantidad máxima de intentos posibles para descubrir la palabra completa.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ahorcado(int intentos) {
    switch(intentos) {
        case 0:
            printf("  -----\n");   // Muestra el dibujito cada vez que el jugador falla
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 1:
            printf("  -----\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  -----\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  -----\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  -----\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  -----\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("  -----\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
    }
}

int main() {
    char palabra[20];
    char letra;
    int intentos = 0;
    int intentosMaximos = 6;
    int l;

    printf("JUGADOR 1:\n Escribe la palabra que el JUGADOR 2 tendra que acertar: ");
    scanf("%s", palabra);   // Guarda la palabra que la persona 1 introducwe

    l = strlen(palabra);
    char palabraSecreta[l + 1];  // Guarda la longitud de la palabra y crea otra cadena para ocultar la palabra

    for (int i = 0; i < l; i++) {
        palabraSecreta[i] = '*';
    }                               // Llena la palabra de asteriscos
    palabraSecreta[l] = '\0';

    printf("JUGADOR 2:\n");
    while (intentos < intentosMaximos && strchr(palabraSecreta, '*')) {
        ahorcado(intentos);
        printf("%s\n", palabraSecreta);
        printf("Introduzca una letra: ");
        scanf(" %c", &letra);  // Pide una letra y convierte a min
        letra = strlwr(letra);

        int coincide = 0;
        for (int i = 0; i < l; i++) {
            if (palabra[i] == letra) {
                if (palabraSecreta[i] != letra) {
                    palabraSecreta[i] = letra;  // Busca la letra en la palabra
                    coincide = 1;
                }
            }
        }

        if (!coincide) {
            intentos++;   // Si no encuentra suma un intento
        }
    }

    ahorcado(intentos);
    if (!strchr(palabraSecreta, '*')) {
        printf("Felicidades!!!! Has ganado. La palabra era: %s\n", palabra);
    } else {                                                                    // Mensajes
        printf("Has perdido!!!!. La palabra era: %s\n", palabra);
    }

    return 0;
}
