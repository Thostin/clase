#include <stdio.h>

void validacion1 (int Tarea1[], int Puntaje_T1){
    for(int i = 0; i < 5; i++){
        while(Tarea1[i] > Puntaje_T1){
            printf("Error!!, ingresa de nuevo: ");
            scanf("%d", &Tarea1[i]);
        }
    }
}

void validacion2 (int Tarea2[], int Puntaje_T2){
    for(int i = 0; i < 5; i++){
        while(Tarea2[i] > Puntaje_T2){
            printf("Error!!, ingresa de nuevo: ");
            scanf("%d", &Tarea2[i]);
        }
    }
}


void impresion(int Tarea1[], int Tarea2[], int Puntaje_Total, int Puntos_Obtenidos[], int Min_P){
    for(int i = 0; i < 5; i++){
        printf("----------Alumno %d----------\n", i+1);
        printf("Puntaje en la tarea 1: %d\n", Tarea1[i]);
        printf("Puntaje en la tarea 2: %d\n", Tarea2[i]);
        printf("Perdiste %d puntos\n", Puntaje_Total - Puntos_Obtenidos[i]);
        if(Puntos_Obtenidos[i] >= Min_P){
            printf("Felicidades, aprobaste\n");
        } else if(Puntos_Obtenidos[i] < Min_P){
            printf("No aprobaste, puntos faltantes: %d\n", Min_P - Puntos_Obtenidos[i]);
        }
    }
}

int main(){
    int Cedula_i[5], Puntaje_T1, Puntaje_T2;
    int Tarea1[5], Tarea2[5], Puntos_Obtenidos[5], Min_P = 0;


    //Ingresamos los puntos asignados en cada tarea

    printf("Puntos de la primera tarea: ");
    scanf("%d", &Puntaje_T1);

    printf("Puntos de la segunda tarea: ");
    scanf("%d", &Puntaje_T2);

    int Puntaje_Total = Puntaje_T1 + Puntaje_T2;
    Min_P = Puntaje_Total * 0.7;


    for(int i = 0; i < 5; i++){
        printf("----------Alumno %d----------\n", i+1);
        printf("Ingresa la cedula de identidad del alumno: ");
        scanf("%d", &Cedula_i[i]);
        printf("Puntaje obtenido en la tarea 1: ");
        scanf("%d", &Tarea1[i]);
        validacion1(Tarea1, Puntaje_T1);

        printf("Puntaje obtenido en la tarea 2: ");
        scanf("%d", &Tarea2[i]);
        validacion2(Tarea2, Puntaje_T2);

        Puntos_Obtenidos[i] = Tarea1[i] + Tarea2[i];
    }
    printf("----------Resultados----------\n");

    impresion(Tarea1, Tarea2, Puntaje_Total, Puntos_Obtenidos, Min_P);
    
    return 0;
}