/*9. Generar las siguientes series de valores, escribir los procedimientos para cada una
serie a ---- serie b ---- serie c ---- serie d ---- serie e
    1           1         1234        1            1234
    12          22        2345        121          2341
    123         333       3456        12321        3412
    1234        4444      4567        1234321      4123
                          ...         123454321
                          ...         12...N..21
    123456789   88888888  13141516
*/
#include<stdio.h>

void serie_uno(){
printf("Serie A: \n"); /*No es necesario ni explicar, pero imprime el encabezado de "Serie A"*/
for (int i = 0; i <= 9; i++)/*se realizan 9 iteraciones, que inicia desde el 0*/
{
    for (int j = 1; j <= i; j++) /*otro bucle que imprime los valores de 1 al valor actual de 'j'*/
    {
        printf("%d", j);
    }
    printf("\n"); /*Permite que salte a la siguiente linea y que, por ejemplo, no salgan los numeros '112123...' impresos en una sola linea*/
}
printf("\n");
}

/*nuevamente, creamos otro procedimiento llamado 'serie_dos', donde primeramente imprimimos 'serie A'*/
void serie_dos(){
printf("Serie B: \n");
for (int i = 0; i <= 8; i++) /*Se realiza un bucle, que itera del 0 al 8*/
{
    for (int j = 1; j <= i; j++) /*imprime el valor de j*/
    {
        printf("%d", i);
    }
    printf("\n"); /*Imprime una nueva linea despues de imprimir todos los numeros en una fila*/
}
printf("\n");
}

void serie_tres(){
printf("Serie C: \n");
for (int i = 0; i <= 12; i++) /*itera del 0 al 12*/
{
    for (int j = 1; j <= 4; j++) /*sub-bucle con la finalidad de imprimir j+i*/
    {
        printf("%d", j + i);
    }
    printf("\n"); 
}
printf("\n");
}

void serie_cuatro(){
printf("Serie D: \n"); /*imprime el encabezado "Serie D"*/
for (int i = 1; i <= 5; i++) /*utiliza un bucle externo que va desde 1 hasta 5 para generar cada fila de la serie*/
{
    /*Se utilizan dos bucles anidados, donde el primer bucle imprime numeros del 1 al valor actual de i, mientras que el segundo
    imprime numeros en orden descendente desde i - 1 hasta 1*/
    for (int j = 1; j <= i; j++) 
    {
        printf("%d", j);
    }
    for (int j = i - 1; j >= 1; j--) 
    {
        printf("%d", j);
    }
printf("\n");
}
}

void serie_cinco() {
    printf("\nSerie E: \n"); 
    int arr[4] = {1, 2, 3, 4}; /*Se define un arreglo arr de tamaño 4 con los valores '1', '2', '3', '4'*/
    for (int i = 0; i < 4; i++) 
    {
        /*En cada iteración, se imprime el elemento del arreglo según la fórmula (i + j) % 4 que asegura 
        que cada vez que se llega al final del arreglo, se vuelva al principio.*/
        for (int j = 0; j < 4; j++) 
        {
            printf("%d", arr[(i + j) % 4]);
        }
        printf("\n"); /*luego de imprimir todos los elementos en una fila, se agrega 
        una nueva linea, evitando que se imprima todo en una linea horizaontal*/
    }
}

int main(){
    /*Se llaman a todos los procedimientos*/
    serie_uno();
    serie_dos();
    serie_tres();
    serie_cuatro();
    serie_cinco();
    return 0;
}