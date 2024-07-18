#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tirada, dado1, dado2, dado3;
    int suma_total = 0;
    int misma_suma = 0;

    for (int i = 0; i < 100; i++) {
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        dado3 = rand() % 6 + 1;

        tirada = dado1 + dado2 + dado3;
        suma_total += tirada;

        if (dado1 == dado2 && dado2 == dado3) {
            misma_suma++;
        }

        printf("Tiro %d: Dado 1: %d, Dado 2: %d, Dado 3: %d, Suma: %d\n", i + 1, dado1, dado2, dado3, tirada);
    }

    double promedio = (double)suma_total / 100;
    printf("\nSuma total de los 100 tiros: %d\n", suma_total);
    printf("Promedio de la suma: %.2f\n", promedio);
    printf("Veces que se obtuvo el mismo número en los tres dados: %d\n", misma_suma);

    return 0;
}

