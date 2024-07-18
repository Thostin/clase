/*3. 
Ingrese los puntos alcanzados por un alumno e imprima su nota. Para calcular su nota tome la siguiente escala:
Nota    Rango
1       1 al 60
2       61 al 70
3       71 al 80
4       81 a 94
5       95 al 100
*/
#include<stdio.h>
void nota(int notas){
    /*basicamente imprime la nota del alumno dependiendo de los puntajes alcanzados*/
    if (notas >= 1 && notas <= 60)
    {
        printf("\nSu nota es '1'");
    }
    else if (notas >= 61 && notas <= 70)
    {
        printf("\nSu nota es '2'");
    }
    else if (notas >= 71 && notas <= 80)
    {
        printf("\nSu nota es igual a '3'");
    }
    else if (notas >= 81 && notas <= 94)
    {
        printf("\nSu nota es igual a '4'");
    }
    else if (notas >= 95 && notas <= 100)
    {
        printf("Su nota es igual a '5'");
    }
}

int main(){
    int cantidadnotas, notas;
    printf("\nIntroduzca la cantidad de notas a calcular: ");
    scanf("%d", &cantidadnotas);
    while (cantidadnotas < 1) /*vslidacion*/
    {
        printf("\nError, introduzca terminos validos, debe ser como minimo de dos notas.");
    }
    for (int i = 0; i < cantidadnotas; i++) /*se ejecuta un bucle que itera desde 0 hasta la cantidad de puntajes que haya introducido el usuario*/
    {
        printf("\nIntroduzca los puntajes del alumno: ");
        scanf("%d", &notas);
        while (notas < 1) /*otra vez la validacion*/
        {
            printf("\nNo se ingresaron los datos validos, ingrese una nota > 1");
        }
        nota(notas);
    }
    

    return 0;
}