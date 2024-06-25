#include <stdio.h>

int lectura_cedula(int a);
int lectura_tareas(int b);
int puntaje_t(int x);
int puntaje_ob(int p, int x);

int main() {

  int ci[5];
  int pot[5];

  int tareas, i, sumatoria, total = 0, setenta, p_restantes, j;

  for (i = 0; i < 5; i++) {
    printf("Introduzca la cedula de identidad del alumno número %d ", i + 1);
    ci[i] = lectura_cedula(ci[i]);
  }

  printf(
      "Introduzca la cantidad de tareas asignadas durante el proceso lectivo ");
  tareas = lectura_tareas(tareas);

  int puntaje_total[tareas];

  for (i = 0; i < tareas; i++) {
    printf("Introduzca el puntaje asignado a la tarea %d ", i + 1);
    puntaje_total[i] = puntaje_t(puntaje_total[i]);
    total = total + puntaje_total[i];
  }

  // Este vector está al peeeedo
  int puntaje_obtenido[tareas];

  for (i = 0; i < 5; i++) {
    for (j = 0; j < tareas; j++) {

      printf("Introduzca el puntaje obtenido por el alumno %d en la tarea %d ",
             i + 1, j + 1);
      puntaje_obtenido[j] = puntaje_ob(puntaje_obtenido[j], puntaje_total[j]);
      pot[i] = pot[i] + puntaje_obtenido[j];
    }
  }

  setenta = total * 0.7;

  for (i = 0; i < 5; i++) {
    p_restantes = total - pot[i];
    printf("Al alumno de cédula %d le faltaron %d puntos para el total", ci[i],
           p_restantes);
    if (pot[i] < setenta) {
      printf("El alumno de cédula %d esta eliminado", ci[i]);
    }
  }

  return 0;
}

int lectura_cedula(int a) {

  scanf("%d", &a);
  while (a > 9999999 || a < 999999) {
    printf("La cédula de identidad no puede tener más de 7 digitos ");
    scanf("%d", &a);
  }
  return a;
}

int lectura_tareas(int b) {

  scanf("%d", &b);
  while (b <= 0) {
    printf("Introduzca un numero entero positivo por favor ");
    scanf("%d", &b);
  }
  return b;
}

int puntaje_t(int x) {

  scanf("%d", &x);
  while (x <= 0) {
    printf("Introduzca un puntaje mayor a 0");
    scanf("%d", &x);
  }
  return x;
}

int puntaje_ob(int p, int x) {

  scanf("%d", &p);
  while (p < 0 || p > x) {
    printf("El valor no puede ser negativo, este no puede superar al valor de "
           "la tarea asignada");
    scanf("%d", &p);
  }
  return p;
}
