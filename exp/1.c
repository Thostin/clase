// Entren pyyyyyy
/*
 * Funciones
 * */
#include <stdio.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

int fac(int);

int main(void) { return EXIT_SUCCESS; }

int fac(int k) {
  printf("Ésta es una función que calcula el factorial de un número\n\n");
  register int n = k;
  if (n < 1)
    return 0;
  register int res = n;
  while (--n)
    res *= n;

  return res;
}
