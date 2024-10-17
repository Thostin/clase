#include "func.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  // int8_t x1, x2;
  int x1, x2;
  int R;
} factura_t;

typedef struct list_t {
  factura_t factura;
  struct list_t *next;
} list_t;

#ifndef IMPROPER_INPUT
#define IMPROPER_INPUT 2
#endif /* ifndef IMPROPER_INPUT */

int dirichlet_delta_function(int n) { return 1 ? n == 0 : 0; }

int suma_columna(int *arr, int c, int f, int n_c) {
  int sum = 0;
  for (int i = 0; i < f; ++i) {
    sum += arr[c * i + n_c];
  }
  return sum;
}

int sum_arr(int *arr, int f_c) {
  int sum = 0;
  for (int i = 0; i < f_c; ++i) {
    sum += arr[i];
  }
  return sum;
}

int _main(void) {
  system("clear");
  unsigned arr[12] = {0};

  printf("Sucursales:\n1- Centro\n2- Villa Morra\n3- Sajonia\n4- Barrio "
         "Jara\n\nFormas de pago:\n1- Efectivo\n2- Cheque\n3- Targeta\n"
         "Ingrese 9999 en número de factura para finalizar\n"
         "Formato de inserción de facturas: xxx-xxx-yyyy\n");

  factura_t f;
  list_t *facs_ptr = nullptr;
  list_t *aux_ptr = nullptr;
  list_t *before = nullptr;
  int x, y, dinero;
  int i = 0;
  while (1) {
    printf("Ingrese el número de factura:\n"
           "> ");
    if (3 != scanf("%d-%d-%d", &f.x1, &f.x2, &f.R) || f.x1 <= 0 || f.x2 <= 0 ||
        f.R <= 0) {
      printf("Improper input\n");
      exit(IMPROPER_INPUT);
    }
    if (9999 == f.R)
      break;

    aux_ptr = malloc(sizeof(list_t));
    aux_ptr->next = nullptr;
    aux_ptr->factura = f;
    if (0 == i) {
      facs_ptr = aux_ptr;
      before = aux_ptr;
      ++i;
    } else {
      before->next = aux_ptr;
    }

    printf("Forma de pago:\n> ");
    if (1 != scanf(" %d", &x) || x <= 0 || x >= 4) {
      printf("Improper input\n");
      exit(IMPROPER_INPUT);
    }
    printf("Sucursal:\n> ");
    if (1 != scanf(" %d", &y) || y <= 0 || y > 4) {
      printf("Improper input\n");
      exit(IMPROPER_INPUT);
    }
    printf("Monto a pagar:\n> ");
    if (1 != scanf(" %d", &dinero) || dinero < 2000 || dinero > 50000000) {
      printf("Improper input\n");
      exit(IMPROPER_INPUT);
    }

    arr[3 * (y - 1) + x - 1] += dinero;
  }

  printf("Registro de facturas:\n");
  while (nullptr != facs_ptr) {
    printf("%d-%d-%d\n", facs_ptr->factura.x1, facs_ptr->factura.x2,
           facs_ptr->factura.R);
    facs_ptr = facs_ptr->next;
  }
  putchar(10);

  char *nombre_sucursales[] = {"Centro", "Villa Morra", "Sajonia",
                               "Barrio Jara"};
  printf("_____________________________________________________________________"
         "___________________________\n"
         "| Sucursal / Forma de pago |    Efectivo    |     Cheque     |    "
         "Targeta     | "
         "    TOTALES    |\n");
  for (int i = 0; i < 4; ++i) {
    printf("| %24s | %14d | %14d | %14d | %14d |\n", nombre_sucursales[i],
           arr[3 * i], arr[3 * i + 1], arr[3 * i + 2],
           arr[3 * i] + arr[3 * i + 1] + arr[3 * i + 2]);
  }
  printf("| %24s | %14d | %14d | %14d | %14d |\n", "TOTALES",
         suma_columna((int *)arr, 3, 4, 0), suma_columna((int *)arr, 3, 4, 1),
         suma_columna((int *)arr, 3, 4, 2), sum_arr((int *)arr, 12));
  printf("_____________________________________________________________________"
         "___________________________\n");

  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
