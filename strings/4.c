/*
 * Conjugar un verbo terminado en "ar" en tiempo presente
 * */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Se asume que se desea conjugar en tercera persona del singular:\n");
  if (2 != argc) {
    printf("Improper use\n");
    return 1;
  }

  int len = strlen(argv[1]);
  if (len <= 2 || argv[1][len - 1] != 'r' || argv[1][len - 2] != 'a') {
    printf("Improper input\n");
    return 1;
  }

  argv[1][len - 1] = '\0';
  printf("%s\n", argv[1]);
  return 0;
}
