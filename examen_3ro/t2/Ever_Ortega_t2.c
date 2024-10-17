#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#define nullptr NULL
#define BAD_ALLOC 224

struct Nombre {
  char *nom, *ap;
  struct Nombre *next;
};

char *gege;
int len_gege = 0;
int pos_gege = 0;
int Len_nom = 0, Len_ap = 0;

int getchar_cad(void) {
  if (len_gege <= pos_gege) {
    printf("Se ha procesado por completo la cadena ingresada\n");
    return EOF;
  }
  return gege[pos_gege++];
}

int m_fgets_v2(char *arr_nom, char *arr_ap, int lim) {
  int c, i = 0;
  while ((c = getchar_cad()) == ' ' || c == '\t' || c == '\n')
    ;

  if (',' == c) {
    fprintf(stderr, "Una coma??\n");
    return 1;
  }

  do {
    if (EOF == c) {
      fprintf(stderr, "La cadena se ha terminado mientras se leía el nombre\n");
      return 1;
    }

    arr_nom[i] = c;
    ++i;

    if (i == lim) {
      printf("Se ha alcanzado la longitud máxima para arr_nom: %d\n", lim);
      return 1;
    }
  } while ((c = getchar_cad()) != '\n' && c != ' ' && c != ',');

  while (c == ' ' || c == '\t')
    c = getchar_cad();

  if (EOF == c) {
    fprintf(stderr, "La cadena se ha terminado antes de leer el apellido\n");
    return 1;
  }

  if (',' == c) {
    fprintf(stderr, "Se ha ingresado una coma entre el nombre y el apellido\n");
    return 1;
  }

  if ('\n' == c) {
    fprintf(
        stderr,
        "Se ha ingresado un salto de línea antes de ingresar el apellido\n");
    return 1;
  }

  arr_nom[i] = '\0';
  Len_nom = i + 1;

  /**/
  /**/
  /* Leer apellido */
  /**/
  /**/

  i = 0;
  do {
    if (EOF == c) {
      if (0 == i) {
        fprintf(stderr, "No se ha leído nada en apellido\n");
        return 1;
      } else
        return 0;
    }

    arr_ap[i] = c;
    ++i;
    if (i == lim) {
      printf("Se ha alcanzado la longitud máxima para arr_ap: %d\n", lim);
      return 1;
    }
  } while ((c = getchar_cad()) != '\n' && c != ' ' && c != '\t' && c != ',');

  while (c == ' ' || c == '\t')
    c = getchar_cad();

  if (',' == c || EOF == c || '\n' == c) {
    Len_ap = i + 1;
    arr_ap[i] = '\0';
    return 0;
  } else {
    fprintf(stderr, "Se pretendía ingresar una tercera cadena para nombre (un "
                    "nomapellido?)\n");
    return 1;
  }
}

int push(char *ptr_nom, char *ptr_ap, struct Nombre *nodo) {
  struct Nombre *nuevo = malloc(sizeof(struct Nombre));
  if (nullptr == nuevo) {
    perror("malloc");
    return 1;
  }
  if (nullptr != nodo->next) {
    fprintf(stderr, "'nodo' no  está vacío?\n");
    return 1;
  }

  // Esto es re importante:
  nuevo->next = nullptr;

  nuevo->nom = ptr_nom;
  nuevo->ap = ptr_ap;

  nodo->next = nuevo;

  return 0;
}

void borrar_lista(struct Nombre *nodo) {
  struct Nombre *aux = nodo;
  while (nullptr != aux) {
    aux = nodo->next;
    free(nodo);
    nodo = aux;
  }
}

#define LIM_NOMBRE_Y_APELLIDO 25
#define LIM_LEER_CADENA 200

int leer_nombres(struct Nombre **to) {
  printf(
      "Ingrese los nombres, ingrese algo que no siga el formato para finalizar "
      "(ingresar sólo 'Nombre 'Apellido', )\n");

  char arr_nom[LIM_NOMBRE_Y_APELLIDO], arr_ap[LIM_NOMBRE_Y_APELLIDO];
  char *aux_nom = nullptr, *aux_ap = nullptr;

  int cantidad_personas = 0;

  struct Nombre root_nombres = {nullptr, nullptr, nullptr};
  struct Nombre *nodo = &root_nombres;

  char origen[LIM_LEER_CADENA];
  fgets(origen, LIM_LEER_CADENA, stdin);
  gege = origen;

  printf("Cadena leída: %s\n", gege);

  len_gege = 1 + strlen(origen);
  if (len_gege < 2)
    return 1;

  while (0 == m_fgets_v2(arr_nom, arr_ap, LIM_NOMBRE_Y_APELLIDO)) {
    ++cantidad_personas;
    aux_nom = malloc(Len_nom);
    if (nullptr == aux_nom) {
      perror("malloc");
      exit(BAD_ALLOC);
    }

    aux_ap = malloc(Len_ap);
    if (nullptr == aux_ap) {
      perror("malloc");
      exit(BAD_ALLOC);
    }

    __builtin_memcpy(aux_nom, arr_nom, Len_nom);
    __builtin_memcpy(aux_ap, arr_ap, Len_ap);

    push(aux_nom, aux_ap, nodo);
    nodo = nodo->next;
  }

  if (0 == cantidad_personas) {
    fprintf(stderr, "<<< Error, no se ha leído ningún nombre completo\n");
    return 1;
  }

  *to = root_nombres.next;
  return 0;
}

int mostrar_nombres_y_borrar_lista(struct Nombre *nodo) {
  struct Nombre *aux = nodo;

  printf("Todos los nombres:\n\n");
  int i = 1;
  while (nullptr != aux) {
    aux = nodo->next;
    printf("%2d) %s, %s\n", i, nodo->ap, nodo->nom);
    free(nodo);
    nodo = aux;
    ++i;
  }

  putchar(10);
  return 0;
}

int main(void) {
  struct Nombre *nombres;
  if (1 == leer_nombres(&nombres)) {
    fprintf(stderr, "<<< Error, no se pueden imprimir los nombres debido a que "
                    "leer_nombres retornó un error\n");
    return 1;
  }
  mostrar_nombres_y_borrar_lista(nombres);

  return EXIT_SUCCESS;
}
