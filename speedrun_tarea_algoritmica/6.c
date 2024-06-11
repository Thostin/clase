#include <stdio.h>
#include <string.h>

int isvocal(char c) {
  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (2 != argc) {
    printf("Improper use\n");
    return 1;
  }

  printf("Si no termina en vocal, se halla el diminutivo en guaraní:\n");
  int len = strlen(argv[1]);
  if (len <= 2) {
    printf("Uso indebido\n");
    return 1;
  }

  int s;
  char aux[len + 3];
  memset(aux, 0, len + 3);
  memcpy(aux, argv[1], len);

  if (isvocal(aux[len - 1])) {
    printf("Es femenino o masculino (f / m): ");
    s = getchar();
    if (aux[len - 2] == 'i') {
      aux[len - 1] = 't';
      switch (s) {
      case 'f':
        aux[len] = 'a';
        goto kopta;
      case 'm':
        aux[len] = 'o';
        goto kopta;
      default:
        printf("Improper conjugation\n");
        return 1;
      }
    }

    aux[len - 1] = 'i';
    aux[len] = 't';
    switch (s) {
    case 'f':
      aux[len + 1] = 'a';
      break;
    case 'm':
      aux[len + 1] = 'o';
      break;
    default:
      printf("Improper conjugation\n");
      return 1;
    }
  } else {
    printf("Guaraní: ");
    aux[len] = '\'';
    aux[len + 1] = 'i';
  }
kopta:
  printf("%s\n", aux);
  return 0;
}
