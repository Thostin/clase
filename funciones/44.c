/*
 * Los alumnos de una materia se dividen en dos secciones llamadas sección 1 y
 * sección 2. Cada sección tiene su propia lista de alumnos en la cual figuran
 * sus números de matrícula. Escribir un algoritmo que reciba una cantidad de
 * alumnos y los números de matrícula en cada sección, forme dos arreglos con
 * los datos de cada sección y luego combine ambas listas en una sola, ordenada
 * por número de matrícula. */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define nullptr (void *)0x0

struct Node {
  struct Node *next;
  unsigned long matricula;
};

static int push(struct Node *ex_from, uint32_t matricula) {
  register struct Node *from = ex_from;
  if (!from)
    return 2;

  register struct Node *aux;

  while (from) {
    aux = from;
    from = from->next;
  }
  aux->next = malloc(sizeof(struct Node));

  if (nullptr == aux->next)
    return 1;
  aux = aux->next;
  aux->next = nullptr;
  aux->matricula = matricula;
  return 0;
}

static struct Node *get_final_ptr(struct Node *ex_node) {
  if (nullptr == ex_node)
    return nullptr;

  struct Node *aux;
  struct Node *node = ex_node;
  while (node) {
    aux = node;
    node = node->next;
  }
  return aux;
}

uint32_t list_len(struct Node *node) {
  uint32_t len = 0;
  while (node) {
    ++len;
    node = node->next;
  }

  return len;
}

/*Asume que arr tiene espacio suficiente*/
void list_to_arr(struct Node *ex_node, uint32_t *arr) {
  register struct Node *node = ex_node;
  register int i = 0;
  while (node) {
    arr[i] = node->matricula;
    node = node->next;
    ++i;
  }
}

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int leer_alumnos(void) {
  printf("***CARGA DE MATRÍCULAS DE LA MATERIA ???***\n");
  printf("Ingrese las matrículas de la sección 1 (ingrese algo inválido para "
         "finalizar):\n> ");

  int32_t matricula_aux;
  if (0 == scanf("%d", &matricula_aux) || matricula_aux < 1) {
    printf("No se ha ingresado nada para la sección 1, error...\n");
    return 0;
  }
  struct Node *sec1 = malloc(sizeof(struct Node));
  sec1->next = nullptr;
  sec1->matricula = matricula_aux;

  while (1) {
    printf("> ");
    if (0 == scanf(" %d", &matricula_aux) || matricula_aux < 1)
      break;
    push(sec1, matricula_aux);
  }

  while (getchar() != '\n')
    ;
  printf("Ahora ingrese las matrículas de la sección 1 (ingrese algo inválido "
         "para "
         "finalizar):\n> ");

  if (0 == scanf("%d", &matricula_aux) || matricula_aux < 1) {
    printf("No se ha ingresado nada para la sección 2, error...\n");
    return 0;
  }
  struct Node *sec2 = malloc(sizeof(struct Node));
  sec2->next = nullptr;
  sec2->matricula = matricula_aux;

  while (1) {
    printf("> ");
    if (0 == scanf(" %d", &matricula_aux) || matricula_aux < 1)
      break;
    push(sec2, matricula_aux);
  }

  struct Node *xd = get_final_ptr(sec2);
  if (nullptr == xd) {
    printf("WTFFFF????\n");
    return 1;
  }
  xd->next = sec1;
  uint32_t len = list_len(sec2);
  if (0 == len) {
    printf("NDERAKOReEEEEEEEE\n\n");
    return 1;
  }

  uint32_t arr_matriculas[len];
  list_to_arr(sec2, arr_matriculas);
  qsort(arr_matriculas, len, sizeof(uint32_t), comp);
  printf("Todas las matrículas ordenadas por ???:\n\n");
  for (int i = 0; i < len; ++i) {
    printf("%4d | %u\n", i + 1, arr_matriculas[i]);
  }
  putchar(10);
  return 0;
}

int main(void) {
  leer_alumnos();
  return 0;
}
