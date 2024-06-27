#include <stdio.h>
#include <stdlib.h>

// Funcion para qsort
int compfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

// Funcion para reducir la condena y mostrar el perfil de cada prisionero
void reducimiento(int vector[], int cant) {
  int libros[cant];
  for (int i = 0; i < cant; i++) {
    printf("Cuantos libros leyo el reo %d: ", i + 1);
    scanf("%d", &libros[i]);
    while (libros[i] >= 1) {
      switch (libros[i]) {
      case 1:
        vector[i] -= 3;
        break;
      case 2:
        vector[i] -= 5;
        break;
      case 3:
        vector[i] -= 6;
        break;
      default:
        vector[i] -= 6;
        break;
      }
      libros[i] -= 3;
    }
    if (vector[i] < 0) {
      vector[i] = 0;
    }
  }
  int aux;
  for (int i = 0; i < cant; i++) {
    libros[i] = 0;
    aux = vector[i];
    while (aux >= 0) {
      if (aux >= 6) {
        libros[i] += 3;
        aux -= 6;
      } else if (aux >= 5) {
        libros[i] += 2;
        aux -= 5;
      } else {
        libros[i] += 1;
        aux -= 3;
      }
    }

    printf("El prisionero %d esta con %d meses de condena, ahora, y podria "
           "librarse con %d libros\n",
           i + 1, vector[i], libros[i]); // Ns pq me sale 3958793759378 en
                                         // cantidad de libros en el primer reo
  }
  qsort(vector, cant, sizeof(int), compfunc);
  printf("Prisioneros ordenados de forma ascendente");
  for (int i = 0; i < cant; i++) {
    printf("%d\n", vector[i]);
  }
}
int main() {
  int n;
  printf("Ingrese la cantidad de prisioneros: ");
  scanf("%d", &n);
  int prisioneros[n], prisioneros_despues_de_leer[n];
  for (int i = 0; i < n; i++) {
    printf("Ingrese la cantidad de meses que tiene como condena el reo %d: ",
           i + 1);
    scanf("%d", &prisioneros[i]);
    prisioneros_despues_de_leer[i] = prisioneros[i];
  }
  reducimiento(prisioneros_despues_de_leer, n);
  return 0;
}
// Ok, lgmt ns como hacer para sumar los libros,si me pueden ayudar con eso
