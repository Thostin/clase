#include <stdio.h>
#include <string.h>

int main(void) {
  char arr[100] = {0};
  scanf(" %99s", arr);
  arr[strlen(arr) - 1] = '\0';
  printf("%sito\n", arr);
  return 0;
}
