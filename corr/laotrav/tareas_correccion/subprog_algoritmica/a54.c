/*4. Un alumno tiene los resultados de sus x examenes finales correspondientes a las materias que ha cursado hasta ahora. Necesita que puedas
ingresar por teclado lso puntos y sumarlos todos, se imprime la cantidad totsl de puntos acumulados y el promedio. Por cada puntuacion que sea 
ingresadose debe imprimir su nota.
RECUERDA: El total de notas y el promedio solo puede ser impreso dps de ingresar la ultima puntuacion, ademas de que debees ingresar el valor de
X pr teclado.*/
#include <stdio.h>

void notass(int nota) {
    printf("\nNota ingresada: %d", nota);
    /*dependiendo de los puntajes imprime la nota obtenida*/
    if (nota >= 1 && nota <= 60) 
    {
        printf("\nSu nota es '1'");
    } else if (nota >= 61 && nota <= 70) 
    {
        printf("\nSu nota es '2'");
    } else if (nota >= 71 && nota <= 80) 
    {
        printf("\nSu nota es '3'");
    } else if (nota >= 81 && nota <= 94) 
    {
        printf("\nSu nota es '4'");
    } else if (nota >= 95 && nota <= 100) 
    {
        printf("\nSu nota es '5'");
    }
}

void calcularpromedio(int suma, int cantidadresultados) {
    float promedio = (float)suma / cantidadresultados;/*se calcula el promedio en domde se divide la suma de los puntajes entre la cantidad de resultados obtenidos*/
    printf("\nTotal de puntos acumulados: %d", suma); /*se imprimen la cantidad de puntos acumulados y el promedio*/
    printf("\nPromedio: %.2f", promedio);
}

int main(void) {
    int cantidadresultados, nota, suma = 0;

    printf("\nIntroduzca la cantidad de resultados obtenidos: ");
    scanf("%d", &cantidadresultados);

    for (int i = 0; i < cantidadresultados; i++) /*bucle que itera desde 0 hasta la cantidad de puntajes que el usuario haya aclarado*/
    {
        printf("\nIntroduzca el puntaje del alumno: ");
        scanf("%d", &nota);

        while (nota < 1) /*validacion*/
        {
            printf("\nNota no válida, ingrese una nota mayor o igual a 1: ");
            scanf("%d", &nota);
        }

        notass(nota); /*se llama a la funcion en donde se imprime la nota que hayas sacado*/
        suma += nota; /*se suman los puntajes obtenidos*/
    }

    calcularpromedio(suma, cantidadresultados);

    return 0;
}
