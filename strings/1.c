/*
 * Dado un texto $t$, formar una lista "diccionario" conteniendo todas
 * las palabras diferentes que existen en $t$, ordenadas alfabéticamente.
 *
 * Resolución: Crearé un árbol bimario donde se almacenarán todos los punteros
 * a las cadenas. Se procesará el texto en el archivo del nombre que se
 * proporcione.
 *  How descubrí que isblank() no detecta a los saltos de línea como 'blanks'
 * */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

int strcmp(const char *, const char *);

struct Node {
  char *str;
  struct Node *left, *right;
};

static struct Node *root;

char *get_str(FILE *fp) {
  static int is_EOF = 0;
  if (is_EOF) {
    return NULL;
  }
  int len = 0;
  int len_aux = 1;

  int c;
  while (1) {
    c = getc(fp);
    if (EOF == c) {
      is_EOF = 1;
      return NULL;
    }
    if (!isblank(c) && c != '\n') {
      fseek(fp, -1, SEEK_CUR);
      break;
    }
  }
  while ((c = getc(fp)) != EOF && !isblank(c) && c != '\n')
    ++len;

  if (0 == len) {
    printf("Zero length!\n");
    return NULL;
  }

  if (EOF == c) {
    --len;
    is_EOF = 1;
    // printf("EOF reached\n");
  }
  /*
    printf("len: %d\n", len);
    getchar();
  */
  fseek(fp, -(len + 1), SEEK_CUR);
  char *str = malloc(len + 1);

  if (NULL == str) {
    printf("Malloc just failed!\n");
    return NULL;
  }

  fread(str, len, 1, fp);
  str[len] = '\0';
  // printf("New word added: %s\n", str);

  return str;
}

void push(char *str) {
  struct Node *aux = root;
  int cmp;
  while (1) {
    cmp = strcmp(str, aux->str);
    if (0 == cmp)
      return;
    if (cmp > 0) {
      if (NULL == aux->right) {
        aux->right = malloc(sizeof(struct Node));
        aux = aux->right;
        aux->str = str;
        aux->right = aux->left = NULL;
        return;
      }
      aux = aux->right;
    } else {
      if (NULL == aux->left) {
        aux->left = malloc(sizeof(struct Node));
        aux = aux->left;
        aux->str = str;
        aux->left = aux->right = NULL;
        return;
      }
      aux = aux->left;
    }
  }
}

void creat_btree(FILE *fp) {
  char *str = NULL;
  if ((str = get_str(fp)) == NULL) {
    printf("No words available\n");
    return;
  }

  root = malloc(sizeof(struct Node));
  if (NULL == root) {
    printf("Malloc just failed!\n");
    return;
  }

  root->right = root->left = NULL;
  root->str = str;

  while (1) {
    if ((str = get_str(fp)) == NULL)
      break;
    push(str);
  }
}

void show_btree(struct Node *aux) {
  if (NULL != aux) {
    if (NULL != aux->left)
      show_btree(aux->left);
    printf("%s\n", aux->str);

    if (NULL != aux->right)
      show_btree(aux->right);
  }
}

int main(int argc, char *argv[]) {
  if (2 != argc) {
    printf("Need a file to work with please\n");
    return 1;
  }
  FILE *fp = fopen(argv[1], "rb");
  if (NULL == fp) {
    perror("fopen");
    return 1;
  }
  creat_btree(fp);
  printf("Aquí todas las palabras leídas:\n");
  show_btree(root);
  return 0;
}
