#include <stdio.h>
// #include <stdlib.h>

// Encima que ni funciona
int verif(int N) {
  if (N <= 0) {
    printf("error, introduzca el valor otra vez"); /* verifica la variable por
                                                      primera vez */
    scanf("%d", &N);
  }

  if (N <= 0) {
    return (verif(N)); /*si N sigue siendo inválido, retorna la función */
  } else {
    return N; /*si N es valido; retorna el númer*/
  }
}

void verificarpuntajes(int cantidad) {
  int j;
  int igual;
  int array[cantidad * 5]
           [3]; /*se asume que cada alumno realizo las mismas tareas, entonces,
                   se procede a inciializar una matriz que tendra por fila:
                   cedula, puntaje asignado y obtenido*/
  int obtenido;
  int asignado;
  int i;
  int cedula;
  int cedulas[5];
  for (i = 0; i < 5; i++) {
    printf("Introduzca el número de cedula del estudiante %d:", i + 1);
    scanf("%d", &cedulas[i]);
    for (j = 0; j < i; j++) {
      if (cedulas[i] == cedulas[j]) {
        printf("Cédula repetida, pruebe otra vez");
        scanf("%d", &cedulas[i]);

        // Yo puse este j = 0;
        j = 0;
      }
    }
  } /* validacion de cedulas repetidas*/

  int totalpuntos = 0;
  igual = 0;
  for (i = 0; i < cantidad * 5; i++) {
    printf("Introduzca el CI del estudiante"); /*lectura e introduccion
                                                  respectiva de los datos*/
    scanf(" %d", &cedula);
    cedula = verif(cedula);
    for (j = 0; j < i; j++) {
      if (cedulas[i] == cedulas[j]) {
        igual++;
      }
    }

    if (igual > cantidad) {
      printf("error, introduzca la cedula otra vez");
      scanf("%d", &cedula);
    } /*validacion para que no haya más tareas de las asignadas para cada alumno
       */
    array[i][0] = cedula;
    printf("introduzca el puntaje asignado");
    scanf("%d", &asignado);
    array[i][1] = asignado;
    asignado = verif(asignado);
    printf("introduzca el puntaje obtenido");
    scanf("%d", &obtenido);
    obtenido = verif(obtenido);
    while (asignado < obtenido || obtenido <= 0) {
      printf(
          "error, intente de nuevo"); /*validacion para que el puntaje obtenido
                                         no sea mayor que el asignado*/
      scanf("%d", &obtenido);
    }
    array[i][2] = obtenido;
    totalpuntos = totalpuntos + asignado;
  }

  int aux;
  // Esto literalmente no hace nada
  for (i = 0; i < cantidad * 5; i++) {
    for (j = 1; j < cantidad * 5; j++) {
      if (array[i][0] == array[j][0]) {
        aux = array[i][0];
        array[i][0] = array[j][0];
        array[j][0] = aux;
      }
    }
  } /*ordenar la matriz para que todas las tareas de un mismo alumno estén
       juntas*/
  int totalobtenidos = 0;
  for (i = 0; i < (cantidad * 5); i += 5) {
    printf("el alumno con CI %d obtuvo los siguientes puntajes:\n",
           array[i][0]);
    for (j = 0; j < cantidad; j++) {
      printf("tarea %d:\n", j);
      printf("puntaje %d/%d\n", array[j + i][1], array[j + i][2]);
      printf("puntos perdidos: %d\n", array[j + i][1] - array[j + i][2]);
      totalobtenidos = totalobtenidos + array[j + 1][2];
    }

    if (totalpuntos * 0.7 > totalobtenidos) {
      printf("Lo lamentamos, el alumno se ha eliminado");
      printf("Le han faltado %f puntos", (totalpuntos * 0.7) - totalobtenidos);
    } else {
      printf("congratulaciones, ha aprobado");
    }
  }
}

int main() {
  int cantidad;
  printf("Hola! Introduzca la cantidad de valorizaciones a cargar en total");
  scanf("%d", &cantidad);
  cantidad = verif(cantidad);
  verificarpuntajes(cantidad);
}
