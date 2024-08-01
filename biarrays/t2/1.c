#include "func.h"
#include <stdio.h>

/* lim: límite de carcateres (excluyendo el '\0') */
char *leer_nombre(int lim) {
  int c;
  int i = 0;

  char nom[lim + 1];
  char *ptr = nom;

  while (i++ < lim && (c = getchar()) != '\n' && c != '\0') {
    *ptr++ = c;
  }

  ptr = malloc(i);
  __builtin_memcpy(ptr, nom, i - 1);
  ptr[i - 1] = '\0';

  return ptr;
}

struct list {
  struct list *next;
  char *nom;
  int num_prof, num_dep;
};

void leer_datos(void) {
  char *nom;
  int num_dep, num_prof;
  int dat[20];
  __builtin_memset(dat, 0, 20 * sizeof(int));

  struct list root;
  struct list *ptr = &root;

  while (1) {
    printf("Nombre del profesional: ");
    nom = leer_nombre(100);
    printf("Número de departamento: ");
    if (1 != scanf(" %d", &num_dep) || num_dep <= 0 || num_dep >= 18) {
      printf("Hay 17 departamentos, pero es posible que también hayas escrito "
             "cualquier cosa\n");
      break;
    }
    printf("Código de profesión: ");
    if (1 != scanf(" %d", &num_prof) || num_prof <= 0 || num_prof >= 18) {
      printf("\n");
      break;
    }
    while (getchar() != '\n')
      ;

    ++dat[4 * num_dep + num_prof - 5];

    ptr = ptr->next = malloc(sizeof(struct list));
    ptr->nom = nom;
    ptr->num_dep = num_dep;
    ptr->num_prof = num_prof;
    ptr->next = nullptr;
  }

  char *departamentos[] = {"Concepción   ", "San Pedro    ", "Itapúa       ",
                           "Central      ", "Misiones     "};

  char *profesiones[] = {"Médico", "Abogado", "Ingeniero", "Arquitecto"};

  struct list *aux = nullptr;

  ptr = root.next;
  printf("Una lista completa de los profesionales:\n");
  while (ptr != nullptr) {
    printf("Nombre: %s\n", ptr->nom);
    printf("Departamento: %s\n", departamentos[ptr->num_dep - 1]);
    printf("Profesión: %s\n", profesiones[ptr->num_prof - 1]);
    aux = ptr;
    ptr = ptr->next;
    free(aux);
  }
  ptr = nullptr;
  aux = nullptr;

  printf("Una tabla con datos resaltantes:\n\n"
         "_____________________________________________________________________"
         "_______\n"
         "| Dpto/Profesión | Médicos | Abogados | Ingenieros | Arquitectos | "
         "TOTALES |\n");

  for (num_dep = 0; num_dep < 5; ++num_dep) {
    printf("| %s  | %-7d | %-8d | %-10d | %-11d | %-7d |\n",
           departamentos[num_dep], dat[4 * num_dep + 1], dat[4 * num_dep + 1],
           dat[4 * num_dep + 2], dat[4 * num_dep + 3],
           suma_fila(dat, 4, num_dep));
  }
  printf("_____________________________________________________________________"
         "_______\n");
}

int _main(void) {
  leer_datos();
  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
