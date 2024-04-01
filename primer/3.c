#include <stdio.h>

#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif

#define SIZE 20
void get_token(char *str){
  int c;
  int counter = 0;
  int len = 0;
  while((c = getchar()) != EOF && c != '\n'){
    if(counter == SIZE){
      printf("Line too long");
      break;
    }

    if('0' == c){
      printf("ERROR: A '0' introduced at:\n%s", str);
      putchar('0');
      while((c = getchar()) != '\n')
        putchar(c), ++len;
      putchar(10);
      for(int i = 0; i < counter; i++)
        putchar('-');
      putchar('^');
      for(int i = 0; i < len; i++)
        putchar('-');
      putchar(10);
      memset(str, 0, SIZE);
      //str[counter] = c;
      break;
    }
    str[counter] = c;
    ++counter;
  }

}

int med(void){
  printf("Introduzca números (introduzca '0' para terminar): \n");

  int aux, counter = 0, sum = 0;
  char token[SIZE];
  do{
    ++counter;
    printf("> ");
    memset(token, 0, SIZE);
    get_token(token);
    aux = atoi(token);
    //printf("VAL: %d\n",aux);
    sum +=aux;
  }while(aux != 0);

  if(!--counter){
    printf("No se han introducido números\n"); return 1; }
  if(counter == 1)
    printf("Se ha introducido un solo número, la media es: %lf\n", (double)sum);
  else
    printf("Se han introducido %d números, la media es: %lf\n", counter, ((double)sum) / (double)counter);

  return EXIT_SUCCESS;
}
int main(void){
  return med();
}
