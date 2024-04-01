#include <stdio.h>

#define  DIAS 6

int main(int argc, char *argv[]){
  int n;
  if(argc == 2){
    if(!sscanf(argv[1], "%d", &n)){
      printf("Improper input\n");
      printf("Vuelva a intentar\n");
      if(!scanf("%d", &n)){
        printf("Ya dos veces te equivocaste, chaaauuuu\n");
        return 1;
      }
    }
  }
  else{
    printf("Ingrese el sueldo por hora del empleado: ");
    if(!scanf("%d", &n)){
      printf("Improper input\n");
      printf("Chau\n");
      return 1;
    }
  }

  int aux;
  int suma_horas = 0;

  printf("Ahora ingrese las horas que trabajó el empleado cada día de la semana:\n");
  for(int j = 0; j < DIAS;){
    printf("Día %d: ", ++j);
    if(!scanf(" %d", &aux)){
      printf("Improper input\n");
      return 1;
    }
    if(aux > 10){
      if(aux > 24){
        printf("Che no estamos jugando\n");
        return 1;
      }
      else{
        printf("ABUSO LABORAL\n");
      }
    }
    suma_horas += aux;
  }

  printf("En total, el empleado trabajó %d horas esta semana, y debe percibir un pago de gs%d respectivamente.\n", suma_horas, suma_horas * n);

  return 0;
}
