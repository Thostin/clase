#include "func.h"
#include <stdio.h>

/* lim: límite de carcateres (excluyendo el '\0') */

void leer_datos(void) {
  int cod_emp, sexo, dat[10], res_sueldo, sueldo;
  __builtin_memset(dat, 0, 40);
  while (1) {
    printf("Código de empleado: ");
    if (1 != scanf(" %d", &cod_emp) || cod_emp <= 0 || cod_emp == 9999)
      break;
    printf("Código de sexo: ");
    if (1 != scanf(" %d", &sexo) || sexo <= 0 || sexo >= 3)
      break;
    printf("Sueldo: ");
    if (1 != scanf(" %d", &sueldo) || sueldo <= 0 || sueldo >= 15000) {
      printf("\n");
      break;
    }

    if (sueldo <= 200)
      res_sueldo = 0;
    else if (sueldo <= 400)
      res_sueldo = 1;
    else if (sueldo <= 600)
      res_sueldo = 2;
    else if (sueldo <= 800)
      res_sueldo = 3;
    else
      res_sueldo = 4;
    ++dat[5 * (sexo - 1) + res_sueldo];
  }

  printf("Una tabla con datos resaltantes:\n\n"
         "_____________________________________________________________________"
         "_________________________________\n"
         "| Sexo/Sueldo en miles | <= 200 | 200 < y <= 400 | 400 < y <= 600 | "
         "600 < y <= 800 | 800 < | "
         "TOTALES |\n");

  char *sexos[] = {"Hombres", "Mujeres"};
  for (int i = 0; i < 2; ++i) {
    printf("| %s              | %6d | %14d | %14d | %14d | %5d | %7d |\n",
           sexos[i], dat[5 * i], dat[5 * i + 1], dat[5 * i + 2], dat[5 * i + 3],
           dat[5 * i + 4], suma_fila(dat, 5, i));
  }
  printf("_____________________________________________________________________"
         "_________________________________\n");
}

int _main(void) {
  leer_datos();
  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
