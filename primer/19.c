#include <stdio.h>


int main(void){
  int op;
  printf("Aquí hay opciones para mborear un rato:\n");
  printf("1. Salir\n");
  printf("2. Hacer la tarea\n");
  printf("3. No hacer la tarea\n");

  while(1){
    if(scanf(" %d", &op))
    switch(op){
      case 1: printf("Chau\n"); return 0;
      case 2: printf("XD\n"); break;
      case 3: printf("La cordi:\n"); break;
      default: printf("Nderasore chera'a escribi bien\n");
    }
    else{
      printf("CHOREEEEE, escribi bien\n");
      while(getchar() != '\n');
    }
  }

  return 0;
}
