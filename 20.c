#include <stdio.h>

int main(void){
  long candidatos[4] = {0};
  printf("**VOTOS***\n");
  printf("**INTRODUZCA ALGO INVALIDO PARA FINALIZAR**\n");
  printf("OPCIONES:\n1-KARAI KACHO\n2-KALAITO POMBERO\n3-AIRE ACONDICIONADO\n4-VENTILADOR\n\nIntroduzca su voto:\n> ");

  long aux;
  while(1){
    if(!scanf(" %ld", &aux)){
      printf("CHAU\n");
      break;
    }
    switch(aux){
      case 1:
      case 2:
      case 3:
      case 4:
      ++candidatos[aux - 1]; break;
      default:
      printf("Por favor, introduzca algo válido\n");
    }
    printf("> ");
  }

  printf("KARAI KACHO: %ld votos.\n", candidatos[0]);
  printf("KALAITO POMBERO: %ld votos.\n", candidatos[1]);
  printf("AIRE ACONDICIONADO: %ld votos.\n", candidatos[2]);
  printf("VENTILADOR: %ld votos.\n\n", candidatos[3]);
  return 0;
}
