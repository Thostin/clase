/*
    Conjugar un verbo terminado en "ar" en tiempo presente.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char verbo[20];

    printf("Introduzca un verbo REGULARRRRR terminado en \"ar\": "); // Con algunos irregulares funciona
    scanf("%s", &verbo);

    strlwr(verbo);
    int l = strlen(verbo);

    if (l >= 2 && verbo[l-2] == 'a' && verbo[l-1] == 'r') {
        // Yo
        verbo[l - 2] = 'o';
        verbo[l - 1] = '\0';
        printf("\nYo %s\n", verbo);

        // Tú
        verbo[l - 2] = 'a';
        verbo[l - 1] = 's';
        verbo[l] = '\0';
        printf("Tu %s\n", verbo);

        // Él / Ella / Usted
        verbo[l - 2] = 'a';
        verbo[l - 1] = '\0';
        printf("El / Ella / Usted %s\n", verbo);

        // Nosotros / Nosotras
        verbo[l - 2] = 'a';
        verbo[l - 1] = 'm';
        verbo[l] = 'o';
        verbo[l + 1] = 's';
        verbo[l + 2] = '\0';
        printf("Nosotros / Nosotras %s\n", verbo);

        // Vosotros / Vosotras
        verbo[l - 2] = 'a';
        verbo[l - 1] = 'i';
        verbo[l] = 's';
        verbo[l + 1] = '\0';
        printf("Vosotros / Vosotras %s\n", verbo);

        // Ellos / Ellas / Ustedes
        verbo[l - 2] = 'a';
        verbo[l - 1] = 'n';
        verbo[l] = '\0';
        printf("Ellos / Ellas / Ustedes %s\n", verbo);

    } else {
        printf("Error... El verbo ingresado no termina en 'ar'. \n");
    }

    return 0;
}