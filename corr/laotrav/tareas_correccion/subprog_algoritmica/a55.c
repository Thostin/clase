/*Prueba ordenar ascendentemente cuatro variables numericas*/
#include <stdio.h>
#include <stdlib.h>

/*Esta funcion compara dos elementos del arreglo y devuelve 0, 1 o un numero negativo dependiendo de si son iguales, si el primer elemento es mayor
que el segundo o si el primero nuemro es mayor qu ele orimero*/
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    int arr[4];

    for (int i = 0; i < 4; i++) 
    {
        printf("\nIntroduzca el %d numero: ", i+1);
        scanf("%d", &arr[i]);
    }

    qsort(arr, 4, sizeof(int), comparar);/*dependiendo de los resultados mencionados en la funcion comparar, 
    se permite a qsort ordenar los elementos del arreglo de manera ascendente*/

    printf("\nNumeros ordenados ascendentemente:");/*una vez ordenados, se imprimen en forma ascendente con la ayuda de un for, que recorre 
    los elementos del arreglo*/
    for (int i = 0; i < 4; i++) 
    {
        printf("\n%d ", arr[i]);
    }

    return 0;
}
