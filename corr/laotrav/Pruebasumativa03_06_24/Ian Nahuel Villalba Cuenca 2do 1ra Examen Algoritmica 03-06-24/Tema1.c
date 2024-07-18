/*
    El Banco de la Capital de un programa que pueda seleccionar a aquel cliente de mayor prestigio para otorgarle bono exclusivo.
    El prestigio de un cliente se mide por su rapidez en los pagos. Si un cliente se retrasa un mes en un pago, es restado a su nivel de prestigio
    1 punto, si se retrasa dos meses, se le resta 3 puntos (1 por el primer mes, 2 por el segundo), si se atrasa tres meses, se le resta 6 puntos
    (1 por el primer mes, 2 por el segundo, 3 por el tercero). El cliente con un puntaje mas cercano al cero, es decir, menos puntajes restados
    es el mas prestigioso.
    Permitir la carga de la cantidad (N) de clientes, la cantidad de prestamos realizados por cada uno y los meses de retraso que tuvo en cada pago.
    Imprimir en pantalla al cliente mas prestigioso junto a su nombre y seguido a el los otros clientes de manera descendente en referencia
    a su cercania con el 0.
*/


#include <stdio.h>
#include <stdlib.h>

void retraso(int prestigio[], int prestamos[], int cantidadClientes){   //Calcula y verifica los puntajes de los usuarios, tomando en cuenta los prestamos que sacaron.
    int atraso[cantidadClientes];
    for(int i=0; i<cantidadClientes; i++){
        if(prestamos[i] == 2){ // Si sacaron dos prestamos entonces el doble de la cantidad de puntos seran restados si se atrasa
            do{
                printf("Introduzca la cantidad de veces que el cliente con id %d se atraso un mes con su pago.\n", i+1);
                scanf("%d", &atraso[i]);
                if(atraso[i] < 0){
                    printf("Error. Debe introducir un numero positivo.\nIntente de nuevo\n\n");
                }
                else if(atraso[i] > 12){
                    printf("Error. No puede atrasarse mas de un año en pagar todo su prestamo\nIntente de nuevo.\n\n");
                }
            }while(atraso[i] < 0 || atraso[i] > 12);
            prestigio[i] = prestigio[i] - (atraso[i]*2);
            do{
                printf("Introduzca la cantidad de veces que el cliente con id %d se atraso 2 meses con su pago.\n", i+1);
                scanf("%d", &atraso[i]);
                if(atraso[i] < 0){
                    printf("Error. Debe introducir un numero positivo.\nIntente de nuevo\n\n");
                }
                else if(atraso[i] > 6){
                    printf("Error. No puede atrasarse mas de un año en pagar todo su prestamo\nIntente de nuevo.\n\n");
                }
            }while(atraso[i] < 0 || atraso[i] > 6);
            prestigio[i] = prestigio[i] - (atraso[i]*(3*2));
            do{
                printf("Introduzca la cantidad de veces que el cliente con id %d se atraso 3 meses con su pago.\n", i+1);
                scanf("%d", &atraso[i]);
                if(atraso[i] < 0){
                    printf("Error. Debe introducir un numero positivo.\nIntente de nuevo\n\n");
                }
                else if(atraso[i] > 4){
                    printf("Error. No puede atrasarse mas de un año en pagar todo su prestamo\nIntente de nuevo.\n\n");
                }
            }while(atraso[i] < 0 || atraso[i] > 4);
            prestigio[i] = prestigio[i] - (atraso[i]*(6*2));
        }
        else if(prestamos[i] == 1){ // Si sacaron un solo prestamo entonces solo se restara la cantidad normal de puntos.
            do{
                printf("Introduzca la cantidad de veces que el cliente con id %d se atraso un mes con su pago.\n", i+1);
                scanf("%d", &atraso[i]);
                if(atraso[i] < 0){
                    printf("Error. Debe introducir un numero positivo.\nIntente de nuevo\n\n");
                }
                else if(atraso[i] > 12){
                    printf("Error. No puede atrasarse mas de un año en pagar todo su prestamo\nIntente de nuevo.\n\n");
                }
            }while(atraso[i] < 0 || atraso[i] > 12);
            prestigio[i] = prestigio[i] - (atraso[i]);
            do{
                printf("Introduzca la cantidad de veces que el cliente con id %d se atraso 2 meses con su pago.\n", i+1);
                scanf("%d", &atraso[i]);
                if(atraso[i] < 0){
                    printf("Error. Debe introducir un numero positivo.\nIntente de nuevo\n\n");
                }
                else if(atraso[i] > 6){
                    printf("Error. No puede atrasarse mas de un año en pagar todo su prestamo\nIntente de nuevo.\n\n");
                }
            }while(atraso[i] < 0 || atraso[i] > 6);
            prestigio[i] = prestigio[i] - (atraso[i]*(3));
            do{
                printf("Introduzca la cantidad de veces que el cliente con id %d se atraso 3 meses con su pago.\n", i+1);
                scanf("%d", &atraso[i]);
                if(atraso[i] < 0){
                    printf("Error. Debe introducir un numero positivo.\nIntente de nuevo\n\n");
                }
                else if(atraso[i] > 4){
                    printf("Error. No puede atrasarse mas de un año en pagar todo su prestamo\nIntente de nuevo.\n\n");
                }
            }while(atraso[i] < 0 || atraso[i] > 4);
            prestigio[i] = prestigio[i] - (atraso[i]*(6));
        }
    }
}

int comparar(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int main(int argc, char **argv){
    int cantidadclientes;
    do{         // Utilizo el do while para la verificacion de aquellos numeros que no deseo que sean negativos.
        printf("Introduzca la cantidad de clientes que tiene el banco.\n");
        scanf("%d", &cantidadclientes);
        if(cantidadclientes <= 0){
            printf("Error. Debe introducir un numero mayor a 0.\nIntente de nuevo.\n\n");
        }
    }while(cantidadclientes <= 0);
    int idcliente[cantidadclientes];
    for(int i=0; i<cantidadclientes; i++){
        idcliente[i] = 0;
    }
    int cantprestamos[cantidadclientes];
    for(int i=0; i<cantidadclientes; i++){
        do{
            printf("Introduzca la cantidad de prestamos del cliente con id %d.\n", i+1);
            scanf("%d", &cantprestamos[i]);
            if(cantprestamos[i] <= 0){
                printf("Error. Debe introducir un numero mayor a 0.\nIntente de nuevo.\n\n");
            }
            else if(cantprestamos[i] > 2){
                printf("Error. No puede tener mas de dos prestamos activos.\nIntente de nuevo.\n\n");
            }
        }while(cantprestamos[i] <= 0 || cantprestamos[i] > 2);
    }
    retraso(idcliente, cantprestamos, cantidadclientes); // Llamo a la funcion retraso para asignar los puntos y modificar las variables necesarias
    int aux[cantidadclientes];
    for(int i=0; i<cantidadclientes; i++){
        aux[i] = idcliente[i];
    }
    int auxclientes=1;
    qsort(idcliente, cantidadclientes, sizeof(int), comparar);  //Ordeno la cantidad de puntos de los clientes
    for(int i=0; i<cantidadclientes; i++){
        for(int j=0; j<cantidadclientes; j++){
            if(aux[j] == idcliente[i]){
                printf("\nEl cliente con el id %d tiene el rango %d de prestigio en el banco con %d puntos.\n\n", j+1, i+1, idcliente[i]); //Imprimo el id del cliente con su prestigio.
                aux[j] = 5; //Cambio el valor del auxiliar actual por si acaso hay multiples clientes con la misma cantidad de prestigio
                break;
            }
        }
    }
    return 0;
}