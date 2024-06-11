#include <stdio.h>

// Éstas macros me salvaron mucho tiempo porque pensé que los sueldos eran
// double pero en realidad eran enteros...
#define LIM_INF_SALARIO 500000L
#define LIM_SUP_SALARIO 10000000L

#define FORMAT_SALARIO "%ld"

typedef long type_salario;

// Asumiendo que todos los punteros tienen el mismo tamaño
#define POINTER_SIZE sizeof(void *)

// Para poner "Primer año", "Segundo año", etc.
const char *ordinales[] = {"Primer", "Segundo", "Tercer", "Cuarto", "Quinto"};

#define CANTIDAD_ORDINALES sizeof(ordinales) / POINTER_SIZE

int main(void) {
  printf("Ingrese la cantidad de empleados: ");

  // Inicializando
  int cantidad_empleados = 0;

  if (!scanf(" %d", &cantidad_empleados) || cantidad_empleados < 1) {
    printf("Inválido\n");
    return 1;
  }

  type_salario salarios[cantidad_empleados];
  printf("Ingrese el salario de cada empleado:\n");
  printf("Límites de salarios (inclusivo):\n Inferior: " FORMAT_SALARIO
         "\n Superior: " FORMAT_SALARIO "\n\n",
         LIM_INF_SALARIO, LIM_SUP_SALARIO);

  for (int i = 0; i < cantidad_empleados; ++i) {
    printf("Empleado %d: ", i + 1);
    if (!scanf(" " FORMAT_SALARIO, salarios + i) ||
        salarios[i] < LIM_INF_SALARIO || salarios[i] > LIM_SUP_SALARIO) {
      printf("Salario inválido\n");
      return 1;
    }
  }

  printf(
      "\nAhora se aplicará un aumento compuesto del 5%% a los salarios por 5 "
      "años:\n");

  for (int j = 0; j < 5 && j < CANTIDAD_ORDINALES; ++j) {
    printf("\n***%s año***\n", ordinales[j]);

    for (int i = 0; i < cantidad_empleados; ++i) {
      printf("Empleado %d: " FORMAT_SALARIO "\n", i + 1, (salarios[i] *= 1.05));
    }
  }
  return 0;
}
