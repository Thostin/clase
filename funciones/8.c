#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nullptr (void *)0x0

struct Producto {
  struct Producto *next;
  int cantidad;
  double precio;
};

void push(struct Producto *node, int cantidad, double precio) {
  while (node->next) {
    node = node->next;
  }
  node->next = malloc(sizeof(struct Producto));
  node = node->next;
  node->next = nullptr;
  node->cantidad = cantidad;
  node->precio = precio;
}

void mostrar_compras(struct Producto *node) {
  double total_a_pagar = 0.0L;
  while (node) {
    printf("(%d, %.2lf)\n", node->cantidad, node->precio);
    total_a_pagar += node->cantidad * node->precio;
    node = node->next;
  }

  printf("TOTAL A PAGAR: %.2lf\n", total_a_pagar);
}

void leer_productos(void) {
  printf("Ingrese los productos que se desea comprar:\n");
  int cantidad;
  double precio;
  struct Producto *node = nullptr;
  printf("Cantidad: ");
  if (0 == scanf(" %d", &cantidad) || cantidad < 1) {
    printf("Primera cantidad inválida... error...\n\n");
    return;
  }
  printf("Precio: ");
  if (0 == scanf("%lf", &precio) || precio < 0.5L) {
    printf("Primer precio inválido... error...\n\n");
    return;
  }

  node = malloc(sizeof(struct Producto));
  node->next = nullptr;
  node->cantidad = cantidad;
  node->precio = precio;

  struct Producto aux;
  while (cantidad) {
    printf("Cantidad: ");
    if (0 == scanf(" %d", &cantidad) || cantidad < 1 ||
        0 == printf("Precio: ") || 0 == scanf(" %lf", &precio) ||
        precio < 0.5L) {
      printf("Finalizado\n");
      break;
    }
    push(node, cantidad, precio);
  }
  printf("El usuario compró todo esto:\n");
  mostrar_compras(node);
}
int main(void) {
  leer_productos();
  return EXIT_SUCCESS;
}
