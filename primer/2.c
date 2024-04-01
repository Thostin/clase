#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int adv(void){
  const int lim = 10;
  int ret = 0;
  printf("Adivina el numero del 1 al 100 que será generado (tienes %d intentos): \n", lim);
  const int _adv = 1 + rand()%100;
  int guess;

  int _lim = lim;

  while(printf("> ") && scanf(" %d", &guess) && _lim--)
    if(guess == _adv){
      printf("¡Adivinaste!\nIntentos: %d", lim - _lim);
      ret = 1;
      break;
    }
    else 
      printf("No, es m%sor\n", guess > _adv ? "en" : "ay");
  
  printf("%s\n", 0 == ret ? "Y bueno la próxima será" : "");

  return ret;
}

int main(void){
  srand(time(NULL));
  return adv();
}
