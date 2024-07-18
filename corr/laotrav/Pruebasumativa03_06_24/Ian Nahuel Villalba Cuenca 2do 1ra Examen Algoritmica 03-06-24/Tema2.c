/*
    Escribir un algoritmo que simule 100 lanzamientos de tres dados. Generar procedimientos que permitan realizar lo siguiente.w
    a) Cual es el numero que mas veces se presenta como suma total de los tres dados?
    b) En cuantas tiradas los tres dados dieron el mismo numero?
    c) En cuantas tiradas los numeros formaron una escalera?
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mismo(int dados[]){     // mismo retornara un contador, que luego sera sumado junto a otra variable para conseguir la cantidad de veces que los dados tienen el mismo valor.
    int cont=0;
    if(dados[0] == dados[1] && dados[1] == dados[2]){
        cont++;
    }
    return cont;
}

int escalera(int dados[]){      // Escalera funciona de la misma manera que la funcion "mismo", solo que solo cuando se forme una escalera.
    int cont=0;
    if(dados[0] == dados[1]+1 && dados[1] == dados[2]+1){
        cont++;
    }
    return cont;
}

void cantsuma(int dados[], int suma[], int aux[]){
    switch(dados[0] + dados[1] + dados[2]){     //Este switch es utilizado para calcular la cantidad de veces que aparece un numero. La resta de el auxiliar con la suma (que es la cantidad de veces que aparece el numero de la suma de los 3 dados) dara como resultado la suma que aparecio mas veces.
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            suma[0]++;
            aux[0]++;
            break;
        case 4:
            suma[1]++;
            aux[1]++;
            break;
        case 5:
            suma[2]++;
            aux[2]++;
            break;
        case 6:
            suma[3]++;
            aux[3]++;
            break;
        case 7:
            suma[4]++;
            aux[4]++;
            break;
        case 8:
            suma[5]++;
            aux[5]++;
            break;
        case 9:
            suma[6]++;
            aux[6]++;
            break;
        case 10:
            suma[7]++;
            aux[7]++;
            break;
        case 11:
            suma[8]++;
            aux[8]++;
            break;
        case 12:
            suma[9]++;
            aux[9]++;
            break;
        case 13:
            suma[10]++;
            aux[10]++;
            break;
        case 14:
            suma[11]++;
            aux[11]++;
            break;
        case 15:
            suma[12]++;
            aux[12]++;
            break;
        case 16:
            suma[13]++;
            aux[13]++;
            break;
        case 17: 
            suma[14]++;
            aux[14]++;
            break;
        case 18:
            suma[15]++;
            aux[15]++;
            break;
    }
}

int comparar(const void *a, const void *b){     // Funcion utilizada en el qsort para ordenar los arrays de forma descendente
    return (*(int*)b - *(int*)a);
}

int main(int argc, char **argv){
    srand(time(NULL));
    int dados[3];
    int suma[16];   // Cantidad de veces que aparecen ciertas sumas de dados. Sera inicializado con 0 para que funcione de contador.
    int aux[16] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}; //Auxiliar que contiene todas las sumas posibles. Sera aumentado y luego restado con la cantidad de veces que aparecio estas sumas para dar la suma que aparecio mas veces.
    for(int i=0; i<16; i++){
        suma[i] = 0;
    }
    int mismos=0, escaleras=0;
    for(int k=0; k<100; k++){
        for(int i=0; i<3; i++){
            dados[i] = rand() % 6 + 1;
        }
        qsort(dados, 3, sizeof(int), comparar); // Ordena los arrays de forma descendente.
        mismos += mismo(dados);
        escaleras += escalera(dados);
        cantsuma(dados, suma, aux);
    }
    qsort(suma, 16, sizeof(int), comparar);
    qsort(aux, 16, sizeof(int), comparar);
    printf("\nEl numero que mas se presenta como suma total de los 3 dados es: %d con %d apariciones.\nLa cantidad de veces que los dados tuvieron el mismo numero es %d.\nLa cantidad de veces que se formo una escalera es %d.\n\n", (aux[0]-suma[0]), suma[0], mismos, escaleras);
    return 0;
}