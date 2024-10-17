/*Existen los nros que leidos de derecha a izquierda e izquierday derecha tienen el mismo valor.
ejemplo 404, 111, 55, 323, 1045401. Lea un conjunto de numeros leidos que tengan la carasteristica antes anotada*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
//si = son iguales
/*verifica si la secuencia de caracteres se leen igual de derecha a iaquierda*/
bool si(char cadena[], int longitud){
    for (int i = 0; i < longitud/2; i++) //recorre la cadena hasta la mitad
    {
        if (cadena[i] != cadena[longitud - i - 1]) //compara la cadena desde el principio con el caracter del final, siendo que si algun caracter no es igual al otro la funcion terminaria y retornaria false
        {
            return false;
        }
    }
    return true;//de otra manera si retornaria true
}
int main(){
    char cadena[100];
    printf("Ingresa una cadena de numeros: ");
    scanf("%s", cadena);
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++)//verificar si todos los caracteres son digitos
    {
        if (!isdigit(cadena[i]))
        {
            printf("La cadena contiene caracteres no validos. ");
            return 1;
        }
        
    }
    if (si(cadena, longitud))
    {
        printf("%s Se lee igual de derecha a izquierda. \n", cadena);
    }
    else
    {
        printf("%s No se lee igual de derecha a izquierda. \n", cadena);
    }
    return 0;
}