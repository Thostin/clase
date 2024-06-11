#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mstrcmp(const void *a, const void *b) {
  return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("No words to work with\n");
    return 0;
  }

  ++argv;
  --argc;
  qsort(argv, argc, 8, mstrcmp);
  printf("Lista ordenada de palabras:\n");
  for (int i = 0; i < argc; ++i) {
    printf("%s\n", argv[i]);
  }
  return EXIT_SUCCESS;
}
