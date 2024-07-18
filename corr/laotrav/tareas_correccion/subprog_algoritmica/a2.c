/* Hacer un subprograma que reciba un vector de N elementos y dos numeros.
La subrutina debe retornar. la suma de los elementos que se encuentran entre
las dos posiciones que se reciben como_parámetro.
Ejemplo: dado (10, 20, 30, 40, 40, 40, 60,70), pos_1 = 2 y pos_2= 5 se debe
retornar 20+30+40+40
OBS. Los números que se reciben como posición son siempre positivos mayores a 0*/
#include<stdio.h>
/*Se implementa una funcion, en la cual se toma como parametros las respecticas posiciones ingresadas por el usuario en el 'main' 
y de las cuales se calculara la suma y la resta, ademas del vector y su longitud*/
int suma(int vector[], int firstnumber, int secondnumber, int longitud){
    /*--------------------------------------------*/
    int resultado = 0; /*se inicializa un vector el cual almacenara la suma de las posiciones anteriormente mencionadas*/
    int frn = firstnumber-1; /*se almacena en 'frn' (es firstnumber pero acortado) ajustandolo para que coincida con el indice del vector ya que 
    el usuario podria haber ingresado '2' y se tomara la tercera posicion del vector*/
    /*--------------------------------------------*/
    for (int i = frn; i < secondnumber; i++) /*aca se almacena en resultado y bla bla bla*/
    {
        resultado += vector[i];
    }
    /*--------------------------------------------*/
    return resultado; /*este devuelve la suma calculada*/
}
int main(){
    int longitud, firstnumber, secondnumber, sumareal; 
    /*--------------------------------------------*/
    printf("Introduzca la longitud del vector: "); /*Se solicita al usuario que introduzca la longitud del vector*/
    scanf("%d", &longitud);
    int vector[longitud]; /*aqui defino el vector con su longitud respectiva*/
    /*---------------------------------------------*/
    printf("Introduzca la 1ra posicion: "); 
    scanf("%d", &firstnumber); 
    /*--------------------------------------------*/
    printf("Introduzca la 2da posicion: ");
    scanf("%d", &secondnumber);
    /*--------------------------------------------*/
    for (int i = 0; i < longitud; i++) /*esta funcion es para q el usuario ingrese los elementos del vector*/
    {
        printf("Introduzca los numeros del vector nro %d: ", i+1);
        scanf("%d", &vector[i]);
    }
    /*--------------------------------------------*/
    sumareal = suma(vector, firstnumber, secondnumber, longitud); /*en esta variable se almacena el resultado final de la funcion suma*/
    printf("resultado: %d", sumareal); /*finalmente se imprime el resultado*/
    return 0;
}