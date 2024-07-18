#include <stdio.h>
#include <time.h>

int main() { /*En la funcion main, declaramos la semilla para generar numeros aleatorios*/
    srand(time(NULL));
    int L = 100;
    lanzamientos(L);

    return 0;
}

void lanzamientos(int L) { /*Esta funcion registrara todos los lanzamientos*/
    int CIguales = 0;
    int Lanzamientos = 0; /*Inicializamos las variables*/
    int CEscalera = 0;
    int Dado[3];
    int Sumas = 0;

    while (Lanzamientos < L) { /*Generamos numeros aleatorios para cada dado*/
        for (int i = 0; i < 3; i++) {
            Dado[i] = rand() % 6 + 1;
        }
        int Igual = Iguales(Dado); /*Lllamamos a la funcion para verificar resultados iguales*/
        CIguales+=Igual;

        int escalera = Escalera(Dado); /*Llamamos a la funcion para verificar escalera*/
        CEscalera+=escalera;
        Lanzamientos++;
    }
    
    printf("La cantidad de veces que dio el mismo numero: %d \n", CIguales); /*Imprimimos las cantidades*/

    printf("La cantidad de veces que dio escalera: %d \n", CEscalera);

    printf("La frecuencia de aparicion mas grande de sumas le corresponde al numero: %d \n", CIguales);
}

int Iguales(int Dado[]) { /*Funcion para verificar si los dados dieron resultados iguales*/
    if (Dado[0] == Dado[1] && Dado[1] == Dado[2]) {
        return 1;
    } /*Retorna 0 o 1 segun se cumpla*/
    else {
        return 0;
    }
}

int Escalera(int Dado[]) { /*Funcionpara verificar si se cumple una escalera*/
    if (Dado[0] < Dado[1] && Dado[1] < Dado[2]) {
        return 1;
    } /*Retorna 0 o 1 segun se cumpla*/
    else {
        return 0;
    }
}

