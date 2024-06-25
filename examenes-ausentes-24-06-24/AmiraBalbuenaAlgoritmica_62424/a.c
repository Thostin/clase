/*El Colegio Tecnico cuenta con bastantes alumnos y algunos de ellos acaban eliminados al 
final de casda anio lectivo debido al no llegar a los puntajes minimos requeridos '70% del total'. 
Los funcionarios de esta institucion requieren una aplicacion que ayude en el proceso
de la realizacion de la planilla de un grupo de '3 alumnos'. Dicho proceso se refiere a la carga de tareas
con su cedula de id, puntaje asignado en la tarea, puntaje obtenido por cada alumno.
Imprimir a cada alumno junto a sus puntajes en cada tarea, asi como cuantos puntos 
han perdido en total, si han aprobado o ahn quedado eliminados y cuantos puntos 
le han faltado para llegar al minimo*/
// 3 alumnos /
// 70% del total /
// requerir ci /
// puntaje obtenido por tarea /
// puntaje total por cada alumno /
// Imprimir a cada alumno junto a sus puntajes en cada tarea /
// cuantos puntos han perdido en total /
// si han aprobado o ahn quedado eliminados /
// cuantos puntos le han faltado para llegar al minimo /
#include<stdio.h>
#include<stdlib.h>
void validacion(int x){ /*procedimiento encargado de validar si un numero es menor a lo requerido*/
    while (x < 1)
    {
        printf("Error... Introduzca los datos requeridos: ");
        scanf("%d", &x);
    }
}
void validacionhaciaarriba(int y, int a){/*procedimiento para validar si un numero indebido (xd) es mayor que el otro */
    while (y > a)
    {
        printf("\nError... Introduzca los datos requeridos: ");
        scanf("%d", &y);
    }
}
/*procedimiento para imprimir los resultados*/
void lectura(int puntajetotal, int alumno[], int puntajetotaltarea, int puntosperdidostarea, int cantidadtareas, int tarea[], int puntajetotalobtenido, int puntosperdidos, int pasaono, int puntajeminimo, int puntosasalvar){
    for (int i = 0; i < 3; i++)
    {
        printf("\t\nAlumno nro %d: %d\n", i+1, alumno[i]);
        for (int i = 0; i < cantidadtareas; i++)
        {
            printf("\nEl puntaje de cada tarea: %d", puntajetotaltarea);
            printf("\nEl puntaje obtenido por el alumno: %d", tarea[i]);
            printf("\nPuntos perdidos en la tarea: %d", puntosperdidostarea);
        }
        printf("\nEl total obtenido es: %d", puntajetotalobtenido);
        printf("\nLa catidad de puntos perdidos son: %d", puntosperdidos);
        printf("\nEl alumno hizo %d porciento", pasaono);
        if (pasaono >= 70)
        {
            printf("\nEl alumno aprobo");
        }
        else
        {
            printf("\nEl alumno desaprobo");
        }
        if (pasaono < 70)
        {
            printf("\nLa cantidad de puntos que le faltaron para aprobar fue de: %d puntos", puntosasalvar);
        }
    }
    
}
int main(){
    int puntajetotal, alumno[4], puntajetotaltarea, puntosperdidostarea = 0, cantidadtareas, puntajetotalobtenido = 0, puntosperdidos = 0, pasaono = 0, puntajeminimo = 0, puntosasalvar = 0;
    printf("\nIntroduzca el puntaje total de la etapa: ");
    scanf("%d", &puntajetotal);
    validacion(puntajetotal); //validacion
    printf("\nintroduzca la cantidad de tareas realizadas a lo largo de la etapa: ");
    scanf("%d", &cantidadtareas);
    validacion(cantidadtareas); //validacion
    int tarea[cantidadtareas];
    for (int i = 0; i < 3; i++)
    {
        printf("\nIntroduzca la cedula de identidad del alumno nro %d: ", i+1);
        scanf("%d", &alumno[i]);
        validacion(alumno[i]); //validacion
        for (int i = 0; i < cantidadtareas; i++)
        {
            printf("\nIntroduzca el puntaje total de la tarea nro %d: ", i+1);
            scanf("%d", &puntajetotaltarea);
            validacion(puntajetotaltarea); //validacion
            printf("\nIntroduzca el puntaje obtenido por el alumno en la realizacion de dicha tarea: ");
            scanf("%d", &tarea[i]);
            validacionhaciaarriba(tarea[i], puntajetotaltarea);
            puntosperdidostarea = puntajetotaltarea - tarea[i];
        }
        puntajetotalobtenido += tarea[i]; /*no me lee bien al ponerlo dentro del for*/
        puntosperdidos = puntajetotal - puntajetotalobtenido; /*calcula la cantidad de puntos perdidos*/
        pasaono = (puntajetotalobtenido * 100)/puntajetotal; /*bien*/
        puntajeminimo = (puntajetotal * 70)/100; /*bien*/
        puntosasalvar = puntajetotalobtenido - puntajeminimo ;
    }
    printf("\t RESULTADOS: "); /*se llama al procedimiento*/
    lectura(puntajetotal, alumno, puntajetotaltarea, puntosperdidostarea, cantidadtareas, tarea, puntajetotalobtenido, puntosperdidos, pasaono, puntajeminimo, puntosasalvar);
    return 0;
}