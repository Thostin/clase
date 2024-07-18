#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Funcion para lanzar un dado
int lanzarDado() {
    return rand() % 6 + 1;
}
// Funcion para calcular la suma de tres dados
int sumaTresDados() {
    int dado1 = lanzarDado();
    int dado2 = lanzarDado();
    int dado3 = lanzarDado();
    return dado1 + dado2 + dado3;
}
// Funcion para verificar si los tres dados tienen el mismo número
int mismosNumeros() {
    int dado1 = lanzarDado();
    int dado2 = lanzarDado();
    int dado3 = lanzarDado();
    return (dado1 == dado2) && (dado2 == dado3);
}
// Funcion para verificar si los números forman una escalera
int formanEscalera() {
    int dado1 = lanzarDado();
    int dado2 = lanzarDado();
    int dado3 = lanzarDado();
    return (dado1 + 1 == dado2) && (dado2 + 1 == dado3);
}
int main() {
    srand(time(NULL));
    int sumafrec[19] = {0}; // Suma total de tres dados varia de 3 a 18
    for (int i = 0; i < 100; i++) {
        int suma = sumaTresDados();
        sumafrec[suma - 3]++;
    }
    // Encontrar la suma mas frecuente
    int maxf = 0;
    int sumamf = 0;
    for (int i = 0; i < 19; i++) {
        if (sumafrec[i] > maxf) {
            maxf = sumafrec[i];
            sumamf = i + 3;
        }
    }
    printf("Numero mas frecuente como suma total de los tres dados: %d\n", sumamf);
    // Contar tiradas con mismos numeros en los tres dados
    int mismosn = 0;
    for (int i = 0; i < 100; i++) {
        if (mismosNumeros()) {
            mismosn++;
        }
    }
    printf("Tiradas en las que los tres dados dieron el mismo numero: %d\n", mismosn);
    // Contar tiradas con escalera
    int escc = 0;
    for (int i = 0; i < 100; i++) {
        if (formanEscalera()) {
            escc++;
        }
    }
    printf("Tiradas en las que los numeros formaron una escalera: %d\n", escc);

    return 0;
}
