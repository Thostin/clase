#include <stdio.h>

int validacion(int validar) {
  printf("Error... Cantidad invalida. Vuelva a introducir: /n"); // Validacion.
                                                                 // Creo que
                                                                 // funciona.
  scanf("%d", &validar);
  return validar;
}

void ordenar_clientes(int prestigio[], int clientes) {
  for (int i = 0; i < clientes; i++) {
    for (int j = (i + 1); i < clientes; i++) {
      if (prestigio[i] <
          prestigio[j]) { // """"""""Ordena""""""""" los clientes dependiendo de
                          // la cercania a 0 del prestigio.
        int temp = prestigio[i];
        prestigio[i] = prestigio[j];
        prestigio[j] = temp;
      }
    }
  }
}

int main() {
  int clientes, cantidad_prestamos, meses_atraso;

  printf("Introduzca la cantidad de clientes: /n");
  scanf("%d", &clientes);
  while (clientes < 1) {
    clientes = validacion(clientes); // Validacion de la cantidad de clientes.
  }

  int prestigio[clientes];

  for (int i = 0; i < clientes; i++) {
    // Inicializa el prestigio de todos los clientes en 0.
    prestigio[i] = 0;
  }

  for (int i = 1; i <= clientes; i++) {
    printf("Introduzca la cantidad de prestamos (maximo dos prestamos) "
           "realizados por el cliente %d: ",
           i);
    scanf("%d", &cantidad_prestamos);
    while (cantidad_prestamos < 1 || cantidad_prestamos > 2) {
      cantidad_prestamos = validacion(
          cantidad_prestamos); // Validacion de la cantidad de prestamos.
    }

    for (int j = 0; i < cantidad_prestamos; i++) {
      printf("Introduzca cuantos meses se atraso el cliente %d con el pago del "
             "prestamo %d: ",
             i, j);
      scanf("%d", &meses_atraso);
      while (meses_atraso < 0 || meses_atraso > 3) {
        meses_atraso =
            validacion(meses_atraso); // Validacion de los meses de atraso.
      }

      while (meses_atraso > 0) {
        prestigio[i] -= meses_atraso; // Se le resta prestigio al cliente
                                      // dependiendo de sus meses de atraso.
        meses_atraso--;
      }
    }
  }

  ordenar_clientes(prestigio, clientes);
  printf("El cliente mas prestigioso es BRUNO GABRIEL BERNAL GONZALEZ. Su "
         "nivel de prestigio es %d. Impresionante. El mejor. \n",
         prestigio[0]);
  printf("El resto de clientes... \n"); // Se imprime el cliente mas prestigioso
                                        // y el resto descendentemente.
  for (int i = 0; i < clientes; i++) {
    printf("%d ", prestigio[i]);
  }

  return 0;
}
