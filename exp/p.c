#include <stdio.h>
#include <stdlib.h>

struct hop {
  char p;
  int valor;
  int *puntero;
};

struct Position {
  int x, y;
};

int fun(struct Position pos) {
  // TODO
}

int main(void) {
  printf("tamano del int: %zu\n", sizeof(int));

  return EXIT_SUCCESS;
}
