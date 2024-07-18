#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPILE_STRING "gcc -o p -Wall -Werror -Wpedantic -Wextra "

int main(int argc, char *argv[]) {
  if (2 != argc) {
    printf("Invalid\n");
    return 1;
  }

  int len = strlen(argv[1]);
  char command[sizeof(COMPILE_STRING) + len];

  char *ptr = command;

  __builtin_memcpy(ptr, COMPILE_STRING, sizeof(COMPILE_STRING) - 1);
  ptr += sizeof(COMPILE_STRING) - 1;

  __builtin_memcpy(ptr, argv[1], len);

  ptr[len] = '\0';
  system(command);
  return 0;
}
