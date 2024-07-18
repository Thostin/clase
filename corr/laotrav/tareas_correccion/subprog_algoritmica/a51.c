/*1. Calcular el cociente y el resto de una division entera. hay piko que explicar esto*/
#include<stdio.h>

void division(int nro1, int nro2)
{
    int cociente = 0, resto = 0;
    cociente = nro1/nro2; /*se define la variable cociente, que almacenara el resultado del nro1 entre el nro2 */
    printf("El cociente es: %d ", cociente); /*se imprime el cociente*/
    resto = nro1 % nro2; /*Calculamos el resto de la division utilizando el operador modulo '%' y se almacena en la variable 'resto'*/
    printf("\nEl resto es: %d", resto);
}

int main(){
    int nro1, nro2;
    printf("Introduzca el primer numero: ");
    scanf("%d", &nro1);
    printf("Introduzca el segundo numero: ");
    scanf("%d", &nro2);
    if (nro2 > nro1) /*validacion, aunque no es necesario realmnte*/
    {
        printf("Introduzca terminos validos, el primer numero ingresado debe ser mayor al segundo ingresado.");
        scanf("%d", &nro2);
    }
    else /*en el caso de que los datos se hayan ingresado correctamente, se llama al procedimiento division*/
    {
        division(nro1, nro2);
    }

    return 0;
}