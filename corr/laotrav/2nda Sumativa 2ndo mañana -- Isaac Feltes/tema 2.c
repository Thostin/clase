/*
Tema 2
Escribir un algoritmo que simule 100 lanzamientos de tres dados. Generar tres procedimientos que permitan realozar los siguiente

a- Cual es el numero que mas se presenta como suma total de los tres dados?
b- En cuantas tiradas los tres dados dieron el mismo numero?
c- En cuantas tiradas los numeros formaron una escalera?

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumadados[16];
int contsumas[16];

int verif_iguales(int *x, int *y, int *z, int l){
    int iguales;
    for (size_t i = 0; i < l; i++)
    {
        if (x[i] == y[i] && y[i] == z[i])
        {
            iguales++;
        }
    }
    return iguales;
}

int verif_sumas(int *x, int *y, int *z, int l){
    int mayor;
    for (size_t i = 0; i < l; i++)
    {
        for (size_t j = 0; j < 15; j++){
            if (x[i] + y[i] + z[i] == sumadados[j])
            {
                contsumas[j]++;
            }
        }
    }
    mayor = contsumas[0];
    for (size_t i = 0; i < 16; i++)
    {
        if (mayor < contsumas[i])
        {
                mayor = contsumas[i];
        }
    }
    return mayor;
}

int verif_escaleras(int *x, int *y, int *z, int l){
    int escalera;
    for (size_t i = 0; i < l; i++)
    {
     if ((x[i] == y[i] + 1 && y[i] == z[i] + 1) || (x[i] == y[i] - 1 && y[i] == z[i] - 1))
     {
        escalera++;
     }
    }
    return escalera;
}

int main(){
    srand(time(NULL));
    int lanzamientos1[100];
    int lanzamientos2[100];
    int lanzamientos3[100];

    for (size_t i = 0; i < 16; i++) //Inicio los contadores
    {
        contsumas[i] = 0;
    }
    

    for (int i = 0; i < 15; i++) //Inicio un vector para guardar las 15 sumas posibles de los dados (3 a 18);
    {
        sumadados[i] = 4+i;
    }
    
    for (size_t i = 0; i < 100; i++) //Doy valor a las tiradas
    {
        lanzamientos1[i] = (rand() % 6) + 1;
        lanzamientos2[i] = (rand() % 6) + 1;
        lanzamientos3[i] = (rand() % 6) + 1;
    }
    
    int mayor = verif_sumas(lanzamientos1, lanzamientos2, lanzamientos3, 100);
    printf("El numero que mas salio en las sumas es: %d \n", mayor);

    int cant_iguales = verif_iguales(lanzamientos1, lanzamientos2, lanzamientos3, 100);
    printf("En los lanzamientos, los tres numeros fueron iguales %d veces \n", cant_iguales);

    int cant_escaleras = verif_escaleras(lanzamientos1, lanzamientos2, lanzamientos3, 100);
    printf("En los lanzamientos, los numeros dieron escalera %d veces \n", cant_escaleras);
    return 0;
}