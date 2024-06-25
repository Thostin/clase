#include <stdio.h>
#include <stdlib.h>
int verificador(int x){
    while (x <= 0)
    {
        printf("Introduzca un numero valido...");
        scanf("%d", &x);
    }
    
}
int verificador2(int y, int x){
    while (y < 0 || y > x)
    {
        printf("Introduzca un numero valido...");
        scanf("%d", &y);
    }
    
}

int eliminados(int cantidad_de_tareas){
    int alumno_los_5[5], tareas[cantidad_de_tareas], alumno[cantidad_de_tareas],perdicion[cantidad_de_tareas], cedula, puntaje_tarea, puntaje_obtenido, puntos_perdidos;
    int total_puntos = 0, total_puntos_obtenidos = 0, total_puntos_perdidos = 0;
    for (int j = 0; j < cantidad_de_tareas; j++)
    {
        printf("Introduzca el puntaje de la tarea numero %d: ", j + 1);
        scanf("%d", &puntaje_tarea);  
        verificador(puntaje_tarea);      
        tareas[j] = puntaje_tarea;
        total_puntos = total_puntos + puntaje_tarea;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Introduzca el numero de cedula del alumno %d: ", i + 1);
        scanf("%d", &cedula);
        verificador(cedula);
        alumno_los_5[i] = cedula;

        for (int k = 0; k < cantidad_de_tareas; k++)
        {  
            printf("Introduzca el puntaje obtenido por el alumno en la tarea %d: ", k + 1);
            scanf("%d", &puntaje_obtenido);
            verificador2(puntaje_obtenido, puntaje_tarea);
            alumno[k] = puntaje_obtenido;
            puntos_perdidos = tareas[k] - alumno[k];
            perdicion[k] = puntos_perdidos;
            total_puntos_obtenidos = total_puntos_obtenidos + puntaje_obtenido;
            total_puntos_perdidos = total_puntos - total_puntos_obtenidos;
        }

        printf("El alumno con CI: %d\n", alumno_los_5[i]);
        for (int m = 0; m < cantidad_de_tareas; m++)
        {
            printf("Logro en la tarea numero %d el puntaje de: %d puntos\n", m + 1, alumno[m]);
            printf("Perdio en esta tarea %d puntos\n", perdicion[m]);
        }

        printf("Ha perdido en total: %d puntos\n", total_puntos_perdidos);
        float aprovado_eliminado = (total_puntos_obtenidos / total_puntos) * 100;
        if (aprovado_eliminado < 70)
        {
            printf("El alumno con CI: %d ha quedado eliminado del Colegio Tecnico Nacional\n", alumno_los_5[i]);
            int qlq_falto = (total_puntos * 0.7) - total_puntos_obtenidos;
            printf("Le faltaron %d puntos para pasar de curso\n", qlq_falto);
        }
        else
        {
            printf("El alumno con CI: %d ha pasado de curso\n", alumno_los_5[i]);
        }
        
    }
}

int main(){
    int cantidad_de_tareas, cedula;
    printf("Introduzca la cantidad de tareas de los 5 alumnos: ");
    scanf("%d", &cantidad_de_tareas);
    verificador(cantidad_de_tareas);
    eliminados(cantidad_de_tareas);
    return 0;
}