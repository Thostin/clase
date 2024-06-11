#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_number(char *str);
int is_capicua(char *str);
int how_many_capicuas(int *arr, int n);

int main(void) {
  printf("¿Cuántos números desea leer?: ");
  int n;

  if (!scanf(" %d", &n) || n <= 0) {
    printf("Sos un reverendo pelotudo\n");
    return 1;
  }
  int arr[n];

  for (int i = 0; i < n; i++) {
    printf("> ");
    if (!scanf(" %d", arr + i)) {
      printf("Sos un reverendo pelotudo\n");
      return 1;
    }
  }
  how_many_capicuas(arr, n);
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

int how_many_capicuas(int *arr, int n) {
  int ret = 0;
  char num[11] = {0};

  for (int i = 0; i < n; ++i) {
    sprintf(num, "%d", arr[i]);
    if (is_capicua(num)) {
      ++ret;
      printf("%s \n", num);
      memset(num, 0, sizeof(num));
    }
  }

  return ret;
}
