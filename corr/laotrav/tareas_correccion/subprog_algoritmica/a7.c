/*
7. El matemático Fermat ha propuesto el siguiente teorema: No existen tres
números A, B y C enteros para los cuales se cumpla que A^n = B^n + C^n cuando n es mayor que 2.
Escribir un algoritmo que verifique el cumplimiento de este teorema para valores
de A, B y C comprendidos entre 1 y 20 y valores de n entre 3 y 5. Utilizər un
subprograma para la realización de! proceso.
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>/*utilice nros aleatorios pq parecia interesante, aunque tienden a repetirse ciertos valores por la naturaleza de la aleatoriedad, queria experimentar.
creo que sigue cumpliendose lo establecido en el enunciado*/
/*se define una funcion para verificar el teorema de Fermat*/
int verificacion(int a, int b, int c, int n){
    /*------------------------------*/
    if (pow(a, n) == (pow(b, n) + pow(c, n)))
    {
        return 1;/* Devuelve 1 si se cumple el teorema*/
    }
    else
    {
        return 0;/* Devuelve 0 si no se cumple el teorema, lo que normalmente deberia ocurrir si n > 2*/
    }
    /*-----------------------------*/
}
int main(){
    srand(time(NULL));
    int n, a, b, c;
    for (int n = 3; n <= 5; n++)
    {
        int cumplicion = 0;/*Variable para indicar si se ha encontrado una combinación que cumple el teorema*/
        printf("n: %d\n", n);/*cada que itere el bucle, se vizualizara el valor de 'n'*/
        /*-------------------------*/
        for (int i = 1; i <= 50; i++)/*un bucle para realizar 50 intentos de encontrar una combinación que cumple el teorema*/
        {
            a = rand() % 20 + 1;/*valor aleatorio para a, que se actualiza con cada iteracion, lo mismo para b y c*/
            b = rand() % 20 + 1;
            c = rand() % 20 + 1;
            printf("Intento %d: a = %d, b = %d, c = %d\n", i, a, b, c);/*se cumpla o no el teorema, se vizualizaran los valores de a, b y c*/
            if (verificacion(a, b, c, n))/*verifica si se cumple el teorema dependiendo de los valores*/
        {
            printf("Se ha encontrado una combinacion: %d*%d = %d*%d + %d*%d\n", a, n, b, n, c, n);/*en caso de que se encuentre una combinacion, 
            se muestra el proceso de como se llego a tal respuesta*/
            cumplicion = 1;/*marca que indica que se ha encontrado una combinacion*/
            break; /*sale del bucle ya que se encontro una combinacion*/
        }
        }
        /*------------------------*/
        if(!cumplicion)/*Si no se encontro ninguna combinacion que cumpla el teorema, imprime un mensaje*/
        {
            printf("No se ha encontrado una combinacion para n: %d\n",n);
        }
    }
    return 0;
}