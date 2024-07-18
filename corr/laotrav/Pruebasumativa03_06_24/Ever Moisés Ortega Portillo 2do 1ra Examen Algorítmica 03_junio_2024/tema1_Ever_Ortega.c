#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#define PRESTIGIO_INICIAL 0
#define CLIENTES_MIN 1
#define CLIENTES_MAX 150

/*
 * El prestigio de un cliente se mide mediante la rapidez de sus pagos.
 * Si se retrasa un mes en un pago se resta 1 punto a su nivel, si se retrasa 2
 * meses, se le resta 3 puntos, si son 3, 6 puntos, 1 + 2 + 3, fórmula de Gauss:
 * n * (n + 1) / 2*/

void menu(void);

struct Cliente {
  char nombre[100];
  // Cantidad de meses de retraso por cada posible préstamo: si es -1, entonces
  // no posee ese préstamo Cada cliente posee por lo menos un préstamo
  uint8_t meses_de_retraso[2];
  unsigned short prestigio;
} __attribute__((packed));

typedef struct Cliente Cliente;

int main(void) {
  menu();
  return EXIT_SUCCESS;
}

void init_clientes(Cliente *arr, int cantidad_clientes) {
  __builtin_memset(arr, 0, cantidad_clientes * sizeof(Cliente));
  for (int i = 0; i < cantidad_clientes; ++i) {
    arr[i].prestigio = PRESTIGIO_INICIAL;

    // Verificar si funciona:
    *(int *)&(arr[i].meses_de_retraso) =
        (PRESTIGIO_INICIAL << 16) + 128 + (128 << 8);
    // Xd sí funcionó.
  }
}

// 0 para OK y 1 para error
int leer_cliente(Cliente *cli) {
  printf("Ingrese el nombre: ");
  if (!scanf("%99s", cli->nombre)) {
    printf("Entrada impropia\n");
    return 1;
  }
  while (getchar() != '\n')
    ;

  printf("Posee uno o dos préstamos (1 / 2): ");
  int cant;
  if (!scanf(" %d", &cant) || cant <= 0 || cant >= 3) {
    printf("Un cliente posee un préstamo o dos, caso contrario no es cliente, "
           "sino criminal o desconocido para el BANCO DE LA CAPITAL\n");
    return 1;
  }

#define leer_retraso(var)                                                      \
  if (!scanf(" %d", &var) || var < 0 || var >= 4) {                            \
    printf(                                                                    \
        "No puede ser, un cliente no puede retrasarse una cantidad negativa "  \
        "de meses o más de tres, como máximo puede retrasarse tres meses y " \
        "caso contrario es denunciado por el BANCO DE LA CAPITAL antes del "   \
        "cuarto mes de retraso\n");                                            \
    return 1;                                                                  \
  }

  /*
   * sé que puedo calcular acá mismo el prestigio, pero hay que seguir las
   * reglas
   * */
  if (1 == cant) {
    printf("Ingrese el atraso del único préstamo: ");
    leer_retraso(cant);
    cli->prestigio += cant * (cant + 1) / 2;
    cli->meses_de_retraso[0] = cant;
  } else {
    printf("Ingrese los meses de retraso que tiene en el primer préstamo: ");
    leer_retraso(cant);
    cli->prestigio += cant * (cant + 1) / 2;
    cli->meses_de_retraso[0] = cant;
    printf("Ingrese los meses de retraso del segundo préstamo: ");
    leer_retraso(cant);
    cli->prestigio += cant * (cant + 1) / 2;
    cli->meses_de_retraso[1] = cant;
  }

  return 0;
}

int comparar(const void *a, const void *b) {
  return ((Cliente *)a)->prestigio - ((Cliente *)b)->prestigio;
}

void menu(void) {
  printf("***BANCO DE LA CAPITAL***\n"
         "Ingrese la cantidad de clientes: ");
  int cantidad_clientes;
  if (!scanf("%d", &cantidad_clientes) || cantidad_clientes < CLIENTES_MIN ||
      cantidad_clientes > CLIENTES_MAX) {
    printf("Error: Entrada impropia\n");
    return;
  }

  Cliente clientes[cantidad_clientes];
  init_clientes(clientes, cantidad_clientes);
  for (int i = 0; i < cantidad_clientes; ++i) {
    if (leer_cliente(clientes + i)) {
      printf("\n <<< error\n");
      return;
    }
  }

  qsort(clientes, cantidad_clientes, sizeof(Cliente), comparar);
  printf("Clientes con sus respectivos prestigios:\n"
         "________________________________________________________________\n"
         "|                 Nombre                 | Prestigio | P1 | P2 |\n");
  for (int i = 0; i < cantidad_clientes; ++i) {
    printf("| %38s | %9d | %2d | ", clientes[i].nombre, clientes[i].prestigio,
           clientes[i].meses_de_retraso[0]);
    if (clientes[i].meses_de_retraso[1] == 128) {
      printf("-- |\n");
    } else {
      printf("%2d |\n", clientes[i].meses_de_retraso[1]);
    }
  }
}
