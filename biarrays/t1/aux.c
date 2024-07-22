#include <stdio.h>
#include <stdlib.h>

#ifndef MAXLINE
#define MAXLINE 100
#endif /* ifndef MAXLINE */

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

/* Retorna EOF para EOF, 1, para línea muy extensa,
 * 0 para que no pasó nada y 2 si no se leyó nada.
 * Ignora el salto de línea final.
 * En buf_size guarda el tamaño del bloque de memoria
 * que se reservó.
 * */

int m_getline(char **buf_ptr, size_t *buf_size, size_t buf_size_max, FILE *fp) {
  int c, ret = 0, i = 0;
  char buf[buf_size_max];

  while (--buf_size_max) {
    if ((c = getc(fp)) == EOF) {
      ret = EOF;
      if (0 == i)
        return 2;
      break;
    } else if ('\n' == c || '\0' == c) {
      // El chequeo del c == '\0' es por seguridad
      if (0 == i) {
        ++buf_size_max;
        continue;
      } else {
        break;
      }
    }

    buf[i++] = c;
  }

  *buf_ptr = malloc(i + 1);
  __builtin_memcpy(*buf_ptr, buf, i);

  // Debug mode:
  printf("size allocated by m_getline: %zu\n", (size_t)i + 1);

  (*buf_ptr)[i] = '\0';
  *buf_size = i + 1;

  return ret;
}

int main(void) { return EXIT_SUCCESS; }
