#include <stdio.h>
#include <stdlib.h>

#define vocal(c) { \
printf("%c: ", c); \
switch(c){ \
    case 'a': \
    case 'A': \
    case 'e': \
    case 'E': \
    case 'i': \
    case 'I': \
    case 'o': \
    case 'O': \
    case 'u': \
    case 'U': \
    case 'y': \
    case 'Y': \
    printf("VOCAL"); break; \
    default: printf("NO VOCAL"); \
  } \
  putchar(10); \
}

void voc(char *comando){
  int c;
  int len = strlen(comando);

  char com[8 + len];
  uint64_t *aux = (uint64_t *)com;
  *aux = *(uint64_t *)"killall ";
  memcpy(com + 8, comando, len);

  printf("Introduzca letras:\n");
  while((c = getchar()) != EOF){
    switch(c){
      case ' ': system(com);
      default: vocal(c);
    }
  }
}

int main(int argc, char *argv[]){
  voc(*argv);
  return 0;
}
