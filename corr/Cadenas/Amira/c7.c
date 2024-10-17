/*Desarrollar un algoritmo para jugar al ahorcado. en este juego, uno de los jugadores escribre una palabras secreta
que debe ser descubiertra por el segundo jugador. como pista inicial se presenta una palabra reemplazado
cada letra por un asterisco. el jugador propone una letra a la vez y si esa letra existe en la palabra, se
vuelve a mostrar la palabra, pero colocando las letras en todas las posiciones en que ella aparece.
se cuenta con  una cantidad maxima de intentos posibles para descubrir la palabra completa*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    // p = palabra, poc = palabra oculta
    char p[50], poc[50], letra;
    int oportunidades = 0;
    printf("Ingrese la palabra secreta: ");
    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")] = '\0'; // eliminar el salto de linea
    int longitud = strlen(p);
    for (int i = 0; i < longitud; i++)
    {
        poc[i] = '*';
    }
    poc[longitud] = '\0'; // termianr cadena
    printf("Adivine la palabra secreta: ");
    while (oportunidades < 6)
    {
        printf("Palabra actual: %s\n", poc);
        printf("Ingresa una letra: ");
        scanf("%c", &letra);
        getchar(); // limpieza de buffer, sino hay problemas 
        int acierto = 0;
        for (int i = 0; i < longitud; i++)
        {
            if (tolower(p[i]) == tolower(letra))
            {
                poc[i] = p[i];
                acierto = 1;
            }
        }
        if (!acierto)
        {
            oportunidades++;
            printf("Letra incorrecta.");
        }
        if (strcmp(p, poc) == 0)
        {
            printf("Muy bien, adivinaste!!");
            break;
        }
        if (oportunidades == 6)
        {
            printf("Te quedaste sin intentos. La palabra era: %s\n", p);
        }
    }
    return 0;
}