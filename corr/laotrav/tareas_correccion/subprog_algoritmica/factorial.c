/*Escribir la funcion factorial de un nro*/
#include<stdio.h>

/*se crea la funcion "procedimiento" llamando al parametro de entrada "numero"*/
int factorial(int numero){
    int resultado = 1;
        for (int i = 1; i <= numero; i++)
        /*en esta linea de codigo, se utiliza un for, con "i" como contador a partir de 1 para que este itere hasta el numero que el usuario nos especifique*/
        {
            resultado *= i;
        }
        return resultado;/*al retornarnos un dato o valor, debemos almacenarlo en una variable en el programa principal*/
}


int main(void){
int numero, factor;
printf("Introduzca un numero: ");
scanf("%d", &numero);
factor = factorial(numero);/*aqui invocamos el valor que nos devuelve subprograma y lo almacenamos en "factor"*/
printf("El resultado es: %d", factor);/*finalmente imprimimos el resultado*/

    return 0;
}