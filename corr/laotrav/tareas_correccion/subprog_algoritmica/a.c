/*Un alumno tiene resultados de su x examenes finales correspondientes a las
materias que ha cursado hasta ahora. Necesita que puedas ingresar porn teclado
los puntos y luego de sumarlos todos, se imprime la cantidad total de puntos
acumulados, y el promedio. Por cada puntuacion que sea ingresado se debe
imprimir su nota. Recuerda, el ttotal de notas y el promedio solo puede ser
impreso despues de ingresar la ultima puntuacion, ademas de que debes ingresar
el valor de X por teclado*/
#include <stdio.h>

int nota_puntajes(int exam, int position) {
  int logrado, total, acum_to = 0, acum_lo = 0;
  for (int a = 0; a < exam; a++) {
    printf("\n Introduzca el puntaje total del examen %d de la materia %d : ",
           a + 1, position + 1);
    scanf("%d", &total);
    while (total <= 0) {
      printf("\n Error..el puntaje debe ser mayor a cero(obviamente), "
             "introduzca nuevamente : ");
      scanf("%d", &total);
    }
    printf("\n Introduzca el puntaje logrado : ");
    scanf("%d", &logrado);
    while (logrado > total || logrado < 0) {
      printf("\n Error...puntaje fuera de rango, introduzca nuevamente : ");
      scanf("%d", &logrado);
    }
    acum_to += total;
    acum_lo += logrado;
  }
  float calificacion = ((float)acum_lo / acum_to) * 5;
  printf("\n Materia %d \n Puntaje obtenido = %d\n Calificacion = %.2f\n "
         "Promedio de puntaje = %.2f",
         position + 1, acum_lo, calificacion, (float)acum_lo / exam);
  return calificacion;
}
int main(void) {
  int nro_materias, nro_exam;
  printf("Introduzca el numero de materias : ");
  scanf("%d", &nro_materias);
  while (nro_materias <= 0) {
    printf("\n Error..introduzca un numero mayor a cero : ");
    scanf("%d", &nro_materias);
  }
  float notas = 0;
  for (int i = 0; i < nro_materias; i++) {
    printf("\n Introduzca la cantidad de examenes de la materia %d : ", i + 1);
    scanf("%d", &nro_exam);
    while (nro_exam <= 0) {
      printf("\n Error...introduzca un numero mayor a cero : ");
      scanf("%d", &nro_exam);
    }
    notas += nota_puntajes(nro_exam, i);
  }
  printf("\n El promedio de notas es %.2f ", (float)notas / nro_materias);
  return 0;
}
