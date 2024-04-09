/*
 * Realizar un programa que permita al Director del Consejo Supremo Electoral
 * encontrar el número y porcentaje de votos obtenidos por cada uno de los
 * cuatro candidatos de la Contienda Electoral en relación a los votantes que
 * asistieron a las urnas a depositar su voto.
 * */

#include <stdio.h>

int main(void) {
  long candidatos[4] = {0};
  printf("**VOTOS***\n");
  printf("**INTRODUZCA ALGO INVALIDO PARA FINALIZAR**\n");
  printf("OPCIONES:\n1-KARAI KACHO\n2-KALAITO POMBERO\n3-AIRE "
         "ACONDICIONADO\n4-VENTILADOR\n\nIntroduzca su voto:\n> ");

  long aux;
  while (1) {
    if (!scanf(" %ld", &aux)) {
      printf("CHAU\n");
      break;
    }
    switch (aux) {
    case 1:
    case 2:
    case 3:
    case 4:
      ++candidatos[aux - 1];
      break;
    default:
      printf("Por favor, introduzca algo válido\n");
    }
    printf("> ");
  }

  long total = candidatos[0] + candidatos[1] + candidatos[2] + candidatos[3];
  printf("KARAI KACHO:        %ld votos.  -> %lf%%\n", candidatos[0],
         100.0 * (double)candidatos[0] / total);
  printf("KALAITO POMBERO:    %ld votos.  -> %lf%%\n", candidatos[1],
         100.0 * (double)candidatos[1] / total);
  printf("AIRE ACONDICIONADO: %ld votos.  -> %lf%%\n", candidatos[2],
         100.0 * (double)candidatos[2] / total);
  printf("VENTILADOR:         %ld votos.  -> %lf%%\n", candidatos[3],
         100.0 * (double)candidatos[3] / total);
  printf("TOTAL:              %ld votos.  -> 100%%\n\n", total);
  return 0;
}
