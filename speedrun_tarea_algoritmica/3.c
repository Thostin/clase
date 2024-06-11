#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_number(char *str);
int is_capicua(char *str);

int main(int argc, char *argv[]) {
  if (2 != argc) {
    printf("Improper use\n");
    return 1;
  }

  if (!is_number(argv[1])) {
    printf("No es un entero válido\n");
    return 1;
  }

  if (is_capicua(argv[1])) {
    printf("Es capicúa\n");
    return 0;
  }
  printf("No es capicúa\n");

  return 0;
}

int is_number(char *str) {
  switch (*str) {
  case '\0':
    return 0;
  case '-':
    ++str;
  }
  if (!isdigit(*str))
    return 0;
  printf("a\n");
  while (*(++str) != '\0' && isdigit(*str))
    ;
  if ('\0' != *str)
    return 0;
  return 1;
}

int is_capicua(char *str) {
  int len = strlen(str);
  for (int i = 0; i <= len / 2; ++i) {
    if (str[i] != str[len - i - 1])
      return 0;
  }
  return 1;
}
