/*
Un metodo utilizado por los profesores para ordenar examenes por numeros de matricula, consiste en dividir 
el conjunto total de examenes en dos grupos de igual tamanio, luego ordenar por nnumero de matricula cada grupo
por separado y finalmennte combinar los dos grupos en uno solo para tener todo el conjunto ordenado. Preparar un algoritmo
que reciba un vector de N componentes que utilice este metodo para ordenarlo. Utilizar una funcion al realizar el proceso.
 */
#include<stdio.h>
/*---------------------------------------*/
/*procedimiento que ordena los arreglos a ser utilizado despues*/
void ordenar(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
/*----------------------------------------*/
/*este proced. se encarga de cargar la mitad de los examenes en 'a'*/
void mitadexamA(int mitad, int examenes[], int mitadA[]){
    /*---------------------------*/
    for (int i = 0; i < mitad; i++)
    {
        mitadA[i] = examenes[i];
    }
    ordenar(mitadA, mitad);
}
/*---------------------------------------*/
/*mientras que en este procedimiento se carga la segunda mitad de examenes en un vector 'b' para facilitar ordenarlos */
void mitadexamB(int mitad, int examenes[], int mitadB[]){
    /*----------------------------*/
    for (int i = 0; i < mitad; i++)
    {
        mitadB[i] = examenes[mitad + i];
    }
    ordenar(mitadB, mitad);
}
/*---------------------------------------*/
void nuevovector(int cantidadexamenes, int mitadA[], int mitadB[], int mitad, int ordenC[]){
    /*aqui se cargan ambas mitades en un vector C y al final se ordenan*/
    for (int i = 0; i < mitad; i++)
    {
        ordenC[i] = mitadA[i];
    }
    for (int i = 0; i < cantidadexamenes - mitad; i++)
    {
        ordenC[i+mitad] = mitadB[i];
    }
    /*-------------------------------------------*/
    ordenar(ordenC, cantidadexamenes);
}
/*-----------------------------------------*/
int main(){
    int cantidadexamenes;
    /*-----------------------------------------------------------*/
    printf("Introduzca la cantidad total de examenes a ordenar: ");
    scanf("%d", &cantidadexamenes);
    /*-----------------------------------------------------------*/
    if (cantidadexamenes < 2 || cantidadexamenes % 2 != 0)
    /*Verifica si la cantidad de examenes es par y mayor que 2*/
    {
        printf("Error: la cantidad de exámenes debe ser un número par mayor que 2.\n");
        return 1;
    }
    /*-----------------------------------------------------------*/
    int mitad = cantidadexamenes/2, examenes[cantidadexamenes];/*aqui se define el vector'examenes' con la longitud o cant. de examenes existentes  
    ademas de la longitud que tendra cada mitad, A y B*/
    /*-----------------------------------------------------------*/
    int mitadA[mitad], mitadB[mitad];
    /*-----------------------------------------------------------*/
    for (int i = 0; i < cantidadexamenes; i++)/*se ingresan los datos de los examenes, es decir, por numero de matricula*/
    {
        printf("Introduzca la matricula del examen numero %d: ", i+1);
        scanf("%d", &examenes[i]);
    }
    /*-----------------------------------------------------------*/
    /*en resumen, se invoca a 'mitadexamA' y 'mitadexamB' para que se divididan los examenes en dos grupos*/
    mitadexamA(mitad, examenes, mitadA);
    mitadexamB(mitad, examenes, mitadB);
    /*-------------------------------------------------------------------------------------*/
    int ordenC[cantidadexamenes]; /*Aqui, se llama a 'C', donde se combinan y ordenan los grupos de examenes en un solo arreglo*/
    /*-------------------------------------------------------------------------------------*/
    nuevovector(cantidadexamenes, mitadA, mitadB, mitad, ordenC);
    /*-------------------------------------------------------------------------------------*/
    printf("Nuevo vector ordenado: ");
    for (int i = 0; i < cantidadexamenes; i++)/*se imprime el nuevo vector ordenado*/
    {
        printf("\nelemento nro %d: ", i+1);
        printf("%d\n", ordenC[i]);
    }
    return 0;
}