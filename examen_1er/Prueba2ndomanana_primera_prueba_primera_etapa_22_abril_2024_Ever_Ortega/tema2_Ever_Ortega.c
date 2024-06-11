#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Algunas macros para que el código sea más "portable"
#define FORMAT_SIZE "%ld"
#define LIM_SUP_ARREGLO 10000L
#define type_longitud_arreglo long

void mostrar_arreglo(int *, long size);

// Puedo hacer todo en línea. pero gcc no deja saltar una declaración de arreglo
// con un goto. Hay casos en los que quiero hacer eso: cuando el desplazamiento
// es múltiplo de la longitud del arreglo.
void rotar(int arreglo[], int rotation, long longitud_arreglo);

int main(void) {
  printf("Ingrese el tamaño del arreglo (TAMAÑO MÁXIMO: " FORMAT_SIZE "): ",
         LIM_SUP_ARREGLO);

  // Inicializando
  type_longitud_arreglo longitud_arreglo = 0;

  // Verificar si el usuario ha escrito cualquier cosa
  if (!scanf(" " FORMAT_SIZE, &longitud_arreglo) || longitud_arreglo < 1 ||
      longitud_arreglo > LIM_SUP_ARREGLO) {
    printf("Entrada inválida\n");
    return 1;
  }

  // Inicializando
  int rotation = 0;
  printf("Ingrese por cuánto desea desplazar el arreglo: ");
  if (!scanf(" %d", &rotation) || rotation < 0) {
    printf("Rotación inválida\n");
    return 1;
  }

  // Hay una función que hace esto, pero no recuerdo el nombre
  srand(time(NULL));
  int arreglo[longitud_arreglo];
  for (type_longitud_arreglo i = 0; i < longitud_arreglo; ++i) {
    // Números del 0 all 99
    arreglo[i] = rand() % 100;
  }

  printf("Arreglo original:\n");
  mostrar_arreglo(arreglo, longitud_arreglo);

  // Rotar el arreglo
  // La operación módulo retorna 0 si el módulo es 1
  // Hacer esto es equivalente a rotar el arreglo por lo que se dice
  rotation %= longitud_arreglo;

  if (0 != rotation)
    rotar(arreglo, rotation, longitud_arreglo);

  printf("\n\nArreglo después de desplazarlo por %d unidades:\n", rotation);
  mostrar_arreglo(arreglo, longitud_arreglo);
  putchar(10);

  return 0;
}

void mostrar_arreglo(int *arr, long size) {
  printf("{%d", *arr);
  for (int i = 1; i < size; ++i) {
    printf(", %d", arr[i]);
  }
  putchar('}');
}

void rotar(int arreglo[], int rotation, long longitud_arreglo) {
  int aux[rotation]; // Lo voy a necesitar

  // Manipulación del arreglo
  memcpy(aux, &arreglo[longitud_arreglo - rotation], sizeof(int) * rotation);
  memcpy(arreglo + rotation, arreglo,
         sizeof(int) * (longitud_arreglo - rotation));
  memcpy(arreglo, aux, sizeof(int) * rotation);
}
