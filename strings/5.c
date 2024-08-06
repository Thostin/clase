/*
 * Dado un texto, codificar su contenido cambiando cada letra por la que le
 * sigue en el alfabeto. La letra "z" se reemplaza por "a"
 * */
#include <stdio.h>

int main(void) {
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c == 'z' || c == 'Z' ? c - 'Z' + 'A' : c + 1);
  }
  return 0;
}
