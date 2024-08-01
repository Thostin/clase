#include "func.h"
#include <stdio.h>

/* Supongo que en cada casilla pide cuánto se pegó con ese método de pago y en
 * qué ciudad */
int _main(void) {
  int n_fac, forma_de_pago, sucursal, monto_de_venta, dat[12];
  __builtin_memset(dat, 0, 48);

  while (1) {
    printf("Número de factura: ");
    if (1 != scanf(" %d", &n_fac) || n_fac <= 0 || n_fac >= 6000000 ||
        n_fac == 9999)
      break;
    printf("Sucursal: ");
    if (1 != scanf(" %d", &sucursal) || sucursal <= 0 || sucursal >= 5)
      break;
    if (1 != scanf(" %d", &forma_de_pago) || forma_de_pago <= 0 ||
        forma_de_pago >= 4)
      break;
    if (1 != scanf(" %d", &monto_de_venta) || monto_de_venta <= 0 ||
        monto_de_venta >= 10000000)
      break;

    dat[3 * sucursal + forma_de_pago] += monto_de_venta;
  }

  printf("| Sucursal/Forma de pago | Efectivo | Cheque | ");
  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
