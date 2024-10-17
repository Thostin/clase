#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#define IO_ERROR 5773
#define LIM_SUP_DIM 30

#define nullptr NULL
#define BAD_ALLOC 224

#define LIM_VAL 100

// len es la cantidad de elementos de la matriz
void cargar_matriz(int *mat, int len) {
  for (int i = 0; i < len; ++i) {
    mat[i] = rand() % LIM_VAL;
  }
}
int leer_dimension(int *n) {
  printf("Ingrese el valor de la dimension: ");
  if (1 != scanf(" %d", n) || *n <= 0 || *n > LIM_SUP_DIM) {
    fprintf(stderr, "Error en la lectura de dimensión\n");
    return 1;
  }
  return 0;
}

typedef int type;

int is_prime(int n) {
  // No hace falta porque sólo se le pasará valores no negativos
  if (n < 0)
    return 0;
  switch (n) {
  case 0:
  case 1:
    return 0;
  case 2:
  case 3:
    return 1;
  }

  const int Lim = (int)sqrt((double)n);

  if (!(n & 1))
    return 0;

  for (int imp = 3; imp <= Lim; imp += 2) {
    if (0 == n % imp)
      return 0;
  }
  return 1;
}

struct Lista {
  int n;
  struct Lista *next;
};

int push(int n, struct Lista *nodo) {
  struct Lista *nuevo = malloc(sizeof(struct Lista));
  if (nullptr == nuevo) {
    perror("malloc");
    return 1;
  }
  if (nullptr != nodo->next) {
    fprintf(stderr, "'nodo' no  está vacío?\n");
    return 1;
  }

  nuevo->next = nullptr;
  nuevo->n = n;

  nodo->next = nuevo;

  return 0;
}

void cargar_y_borrar(int *arr, struct Lista *nodo) {
  struct Lista *aux = nodo;
  int i = 0;
  while (nullptr != aux) {
    arr[i] = nodo->n;
    aux = nodo->next;
    free(nodo);
    nodo = aux;
    ++i;
  }
}

void imprimir_matriz(int *mat, int M) {
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      printf("%2d ", mat[M * i + j]);
    }
    putchar(10);
  }
}

// En este caso M es la longitud del lado de la matriz
int NoDiagonal_Vector_es_primo(int *mat, int M) {
  struct Lista root = {0, nullptr};
  struct Lista *nodo = nullptr;

  nodo = &root;

  int cantidad_de_nodos = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      if (M - 1 != i + j && is_prime(mat[M * i + j])) {
        if (1 == push(mat[M * i + j], nodo)) {
          fprintf(stderr, "<<< No se ha creado un nuevo nodo\n");
          return 1;
        }
        nodo = nodo->next;
        ++cantidad_de_nodos;
      }
    }
  }

  if (0 == cantidad_de_nodos) {
    printf("No hay ningún elemento de la matriz que satisfaga las condiciones "
           "dadas\n");
    return 0;
  }

  int vect[cantidad_de_nodos];
  cargar_y_borrar(vect, root.next);

  printf("El vector de todos los números que no están en la diagonal "
         "secundaria y que son primos es: \n"
         "%d",
         *vect);

  for (int i = 1; i < cantidad_de_nodos; ++i) {
    printf(", %d", vect[i]);
  }
  putchar(10);

  return 0;
}

int main(void) {
  srand(time(NULL));
  int M;
  if (leer_dimension(&M))
    exit(IO_ERROR);

  type *mat = malloc(M * M * sizeof(type));
  if (nullptr == mat) {
    perror("malloc");
    exit(BAD_ALLOC);
  }

  cargar_matriz(mat, M * M);
  printf("Matriz generada pseudoaleatoriamente:\n");
  imprimir_matriz(mat, M);

  NoDiagonal_Vector_es_primo(mat, M);
  return EXIT_SUCCESS;
}
