#include <stdio.h>

void funcIdAlum(int idAlumnos[]);

void funcPunTot(int puntajeTotal[], int puntajeMin[], int canTareas, int puntajeMinTot, int puntajeTotalTotal);

void funcPunAlum(int idAlumnos[], int puntajeAlumno[], int puntajeTotal[], int canTareas, int puntajeTotAlum, int puntajeMinTot, int puntajeTotalTotal, int puntajeMin[]);


int main() {
    int idAlumnos[5];
    int puntajeAlumno[5];
    int puntajeTotal[3];
    int puntajeMin[3];
    int canTareas = 3;
    int puntajeMinTot = 0;
    int puntajeTotAlum = 0;
    int puntajeTotalTotal = 0;

    funcIdAlum(idAlumnos);
    funcPunTot(puntajeTotal, puntajeMin, canTareas, puntajeMinTot, puntajeTotalTotal);
    funcPunAlum(idAlumnos, puntajeAlumno, puntajeTotal, canTareas, puntajeTotAlum, puntajeMinTot, puntajeTotalTotal, puntajeMin);

    return 0;
}

void funcIdAlum(int idAlumnos[]) { //funca
    for (int i = 0; i < 5; i++) {
        printf("\n\nIntroduzca el numero de cedula del alumno %d: ", i + 1);
        scanf("%d", &idAlumnos[i]);

        while (idAlumnos[i] < 0) {
            printf("\nIntroduzca un numero de cedula correcto: ");
            scanf("%d", &idAlumnos[i]);
        }
        
        printf("Numero de cedula del alumno %d: %d", i + 1, idAlumnos[i]);
    }
}



void funcPunTot(int puntajeTotal[], int puntajeMin[], int canTareas, int puntajeMinTot, int puntajeTotalTotal) {
    for (int i = 0; i < canTareas; i++) {
        printf("\n\nIntroduzca el puntaje total para la tarea %d: ", i + 1);
        scanf("%d", &puntajeTotal[i]);

        while (puntajeTotal[i] < 1 && puntajeTotal[i] > 99) {
            printf("\nIntroduzca un puntaje mayor a 0: ", i + 1);
            scanf("%d", &puntajeTotal[i]);
        }

        puntajeTotalTotal += puntajeTotal[i];

        printf("Puntaje total para la tarea %d: %d", i + 1, puntajeTotal[i]);

        puntajeMin[i] = (puntajeTotal[i] * 7 ) / 10;


        printf("\nPuntaje minimo para aprovar la tarea: %d", puntajeMin[i]);

        puntajeMinTot += puntajeMin[i];
    }

    printf("\n\nPuntaje total de todas las tareas: %d\n\n", puntajeTotalTotal);

}

void funcPunAlum(int idAlumnos[], int puntajeAlumno[], int puntajeTotal[], int canTareas, int puntajeTotAlum, int puntajeMinTot, int puntajeTotalTotal, int puntajeMin[]) {
    puntajeTotalTotal = puntajeTotal[0] + puntajeTotal[1] + puntajeTotal[2];
    puntajeMinTot = puntajeMin[0] + puntajeMin[1] + puntajeMin[2];


    for (int i = 0; i < 5; i++) {
        printf("\n\nIntroduzca los puntajes del alumno con cedula %d", idAlumnos[i]);
        puntajeTotAlum = 0;

        for (int l = 0; l < canTareas; l++) {
            printf("\n\nIntroduzca su puntaje obtenido en la tarea %d. El puntaje total de la tarea es %d: ", l + 1, puntajeTotal[l]);
            scanf("%d", &puntajeAlumno[l]);
            
            while (puntajeAlumno[l] < 0 || puntajeAlumno[l] > puntajeTotal[l]) {
                printf("\nIntroduzca el puntaje de nuevo. El puntaje total de la tarea es %d: ", puntajeTotal[l]);
                scanf("%d", &puntajeAlumno[l]);
            }

            printf("\nPuntaje obtenido en la tarea %d: %d/%d", l + 1, puntajeAlumno[l], puntajeTotal[l]);

            puntajeTotAlum += puntajeAlumno[l];
        }
        
        if (puntajeTotAlum < puntajeMinTot) {
            printf("\n\nEl alumno sera eliminado.");
            printf("\nEn total hizo %d/%d puntos.", puntajeTotAlum, puntajeTotalTotal);
            printf("\nPerdio %d puntos. Le falto %d puntos para alcanzar el minimo.\n", puntajeTotalTotal - puntajeTotAlum, puntajeMinTot - puntajeTotAlum);
        }

        else {
            printf("\n\nEl alumno pasa.");
            printf("\nEn total hizo %d/%d puntos.", puntajeTotAlum, puntajeTotalTotal);
            printf("\nPerdio %d puntos.\n", puntajeTotalTotal - puntajeTotAlum);   
        }


    }


}