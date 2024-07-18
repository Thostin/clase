/*2. Ingresar dos valores en las variables 'maximo' y 'minimo' y luego ingresar un valor en la varibale 'temperatura'
imprime un mensaje si el valor de temperatura no esta dentro de los rangos marcados por maximo y minimo.*/
#include<stdio.h>
void rango(int maximo, int minimo, int temperatura)
{
    if (temperatura > maximo || temperatura < minimo) /* se verifica si la temperatura está fuera del rango especificado. 
    Si es asi, se imprime un mensaje indicando que la temperatura está fuera del rango, de lo contrario, 
    se imprime un mensaje indicando que la temperatura esta dentro del rango*/
    {
        printf("El valor ingresado en 'temperatura' esta fuera del rango establecido.");
    }
    else
    {
        printf("El valor ingresado en 'temperatura' esta dentro del rando establecido.");
    }
}
int main(){
    int maximo, minimo, temperatura;
    printf("Introduzca el valor maximo: ");
    scanf("%d", &maximo);
    printf("Introduzca el valor minimo: ");
    scanf("%d", &minimo);
    if (maximo < minimo) /*validacion*/
    {
        printf("El elemento 'maximo' debe ser mayor a 'minimo' y viceversa");
    }
    else
    {
        /*en caso de que se hayan introducido los datos correctamente, se pide al usuario la temperatura y luego se llama al procedimiento 'rango'*/
        printf("Introduzca la temperatura: ");
        scanf("%d", &temperatura);
        rango(maximo, minimo, temperatura);
    }
    
    


    return 0;
}