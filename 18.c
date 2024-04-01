/*
 * Un programa que lea dos vectores y halle su union
 */

#include "list/list.h"

#include <stdio.h>
#include <stdlib.h>

typedef long type;

void mostrar_arreglo(type *src, size_t nmemb) {
  printf("{%ld", *src);
  for (int i = 1; i < nmemb; ++i) {
    printf(", %ld", src[i]);
  }
  putchar('}');
}

int main(void) {
  printf("Ingrese los elementos del vector 1 (ingrese algo inválido para "
         "finalizar):\n");
  printf("> ");

  type aux;
  if (!scanf(" %ld", &aux)) {
    printf("vector 1 vacío así no tiene gracia, chau\n");
    return EXIT_FAILURE;
  }

  listptr_t v1 = nullptr;
  listptr_t v_total = nullptr;

  initl(&v1, &aux, sizeof(aux));
  initl(&v_total, &aux, sizeof(aux));

  size_t tam1 = 1, tam_total = 1;
  err_t aux_err;

  while (1) {
    printf("> ");
    if (!scanf(" %ld", &aux))
      break;
    aux_err = nrpushl(&v1, &aux, sizeof(aux));
    if (aux_err == EXIT_SUCCESS)
      ++tam1;
    else if (aux_err != EXIT_SUCCESS_REPEATED) {
      printf("Algo salió mal con nrpushl\n");
      return EXIT_FAILURE;
    } else {
      continue;
    }

    aux_err = nrpushl(&v_total, &aux, sizeof(aux));
    if (aux_err == EXIT_SUCCESS)
      ++tam_total;
    else if (aux_err != EXIT_SUCCESS_REPEATED) {
      printf("Algo salió mal con nrpushl\n");
      return EXIT_FAILURE;
    }
  }

  while (getchar() != '\n')
    ;

  printf("Ingrese los elementos del vector 2:\n");
  printf("> ");

  if (!scanf(" %ld", &aux)) {
    printf("vector 2 vacío así no tiene gracia, chau\n");
    return EXIT_FAILURE;
  }

  listptr_t v2 = nullptr;
  listptr_t n2 = nullptr;

  initl(&v2, &aux, sizeof(aux));
  aux_err = nrpushl(&v_total, &aux, sizeof(aux));

  switch (aux_err) {
  case EXIT_FAILURE:
    printf("Algo salió mal con nrpushl\n");
    return EXIT_FAILURE;
  case EXIT_SUCCESS:
    ++tam_total;
  }

  size_t tam2 = 1;
  while (1) {
    printf("> ");
    if (!scanf(" %ld", &aux))
      break;
    aux_err = nrpushl(&v2, &aux, sizeof(aux));
    if (aux_err == EXIT_SUCCESS)
      ++tam2;
    else if (aux_err != EXIT_SUCCESS_REPEATED) {
      printf("Algo salió mal con nrpushl\n");
      return EXIT_FAILURE;
    } else {
      continue;
    }

    aux_err = nrpushl(&v_total, &aux, sizeof(aux));
    if (aux_err == EXIT_SUCCESS)
      ++tam_total;
    else if (aux_err != EXIT_SUCCESS_REPEATED) {
      printf("Algo salió mal con nrpushl\n");
      return EXIT_FAILURE;
    }
  }

  type vec1[tam1];
  type vec2[tam2];
  type vec_total[tam_total];

  compactl(v1, vec1, sizeof(type));
  compactl(v2, vec2, sizeof(type));
  compactl(v_total, vec_total, sizeof(type));

  printf("Conjunto 1:\n");
  mostrar_arreglo(vec1, tam1);

  printf("\nConjunto 2:\n");
  mostrar_arreglo(vec2, tam2);

  printf("\n\nUnión de los conjuntos:\n");
  mostrar_arreglo(vec_total, tam_total);

  printf("\n\n");

  freel(&v1);
  freel(&v2);
  freel(&v_total);

  return EXIT_SUCCESS;
}
