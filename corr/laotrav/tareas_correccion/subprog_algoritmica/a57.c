/*
5.7 Lea N registros con datos donde cada registro tiene dos números
grabados (A y B).
Se pide calcular e imprimir "Y" siendo:
    N
    Y= (sigma) i
    i=1
En donde:
    X = A+B if (A**2-B**2) > 0
    Xi = A-2*B if (A**2-B**2) = 0
    Xi = A+B-5 if (A**2-B**2) < 0
    */

#include<stdio.h>
#include<math.h>

int x(int a, int b){
    if (((a*a)-(b*b)) > 0) /*si a^2 - b^2 es mayor que cero realiza la suma de a+b*/
    {
        return a + b;
    }
    else if (((a*a)-(b*b)) == 0) /*si a^2 - b^2 = 0 se hace 'a-2*b'*/
    {
        return a - 2 * b;
    }
    else
    {
        return a + b - 5; /*si si a^2 - b^2 es menor que cero se realiza a+b-5*/
    }
}

int main(){ 
    int a, b, cantidadregistros, y = 0;
    printf("Ingrese la cantidad de registros que quiere leer: ");
    scanf("%d", &cantidadregistros);
    /*---------------------------------------*/
    while (cantidadregistros <= 0)/*validacion*/
    {
        printf("Error, vuelva a introducir los datos, numeros enteros positivos.");
        scanf("%d", &cantidadregistros);
    }
    /*---------------------------------------*/
    for (int i = 0; i < cantidadregistros; i++) /*itera de 0 hasta la cantidad de registros que haya aclarado el user*/
    {
        printf("Introduzca el primer numero: ");
        scanf("%d", &a);
        /*-----------------------------------*/
        while (a <= 0) /*validacion*/
        {
            printf("Error, vuelva a introducir los datos, numeros enteros positivos.");
            scanf("%d", &a);
        }
        /*-----------------------------------*/
        printf("Introduzca el segundo numero: ");
        scanf("%d", &b);
        /*-----------------------------------*/
        while (b <= 0)/*validacion*/
        {
            printf("Error, vuelva a introducir los datos, numeros enteros positivos.");
            scanf("%d", &b);
        }
        /*-----------------------------------*/
        y = x(a,b); /*se le invoca a la funcion donde se hacen los calculos correspondientes*/

        for (int i = y; i <= cantidadregistros; i++)
        {
            /*Se utiliza otro bucle for para calcular la sumatoria de los nrs desde 'y' hasta la cantidad de registros*/
            y += i;
        }
        
    }
    printf("La sumatoria da como resultado: %d", y); /*se imprime la sumatoria*/

    return 0;
}