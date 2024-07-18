#include <stdio.h>
/*
#include <stdlib.h>
#include <time.h>
*/
// Ejercicio uno: el banco de la capital requiere de un programa que pueda
// seleccionar a aquel cliente de mayor prestigio para otorgarle bono
// expclusivo. El prestigio de un cliente se mide por su rapidez en los pagos.
// Si un cliente se retrasa un mes en un pago, es restado a su nivel de
// prestigio 1 punto, si se retrasa dos meses, se le resta 3 puntos (1 por el
// primer mes, 2 por el segundo), si se retrasa tres meses, se le resta 6 puntos
// (1 por el primer mes, 2 por el segundo, 3 por el tercero). Permitir la carga
// de la cantidad (N) de clientes, la cantidad de préstamos realizados por cada
// uno y los meses de retraso que tuvo en cada pago. Imprimir en pantalla al
// cliente más prestigioso junto a su nombre y seguido a él a los otros clientes
// de manera descendente en referencia a su cercanía con el 0.

int Pagos(int Clientes);
int Validar(int Inicio, int Fin);
int Clientes, Prestamos, Retraso, Dato, i;

int main() {
  printf("Bienvenido al Banco de la Capital\nIngrese la cantidad de clientes a "
         "registrar\n");
  scanf("%d", &Clientes);
  Dato = Clientes;
  Validar(1, 100);
  Clientes = Dato;
  Pagos(Clientes);
  return 0;
}

int Pagos(int Clientes) {
  int Prestigio, ContadorUno, ContadorDos, Orden[Clientes];
  ContadorUno = ContadorDos = Prestigio = 0;
  while (ContadorUno < Clientes) {
    printf("\tCliente %d\n\n", ContadorUno + 1);
    printf("¿Cuántos prestamos realizó?\n\n"); // Sólo puede hacer MÁXIMO dos
                                               // prestamos
    scanf("%d", &Prestamos);
    Dato = Prestamos;
    Validar(1, 2);
    Prestamos = Dato;
    while (ContadorDos < Prestamos) {
      printf("Prestamo %d\n\n¿Cuántos meses de retraso tuvo?\n",
             ContadorDos + 1);
      scanf("%d", &Retraso);
      Dato = Retraso;
      Validar(1, 3);
      Retraso = Dato;
      if (Retraso == 3) {
        Prestigio = Prestigio + (-6);
      } else {
        if (Retraso == 2) {
          Prestigio = Prestigio + (-3);
        } else {
          if (Retraso == 1) {
            Prestigio = Prestigio + (-1);
          } else {
            Prestigio = Prestigio + 0;
          }
        }
      }
      ContadorDos++;
    }
    Orden[ContadorUno] = Prestigio;
    ContadorDos = Prestigio = 0;
    ContadorUno++;
  }
  ContadorUno = 0;
  printf("Los datos registrados finalmente son\n");
  while (ContadorUno < Clientes) {
    printf("Cliente %d con prestigio %d\n\n", ContadorUno + 1,
           Orden[ContadorUno]);
    ContadorUno++;
  }
  return 0;
}

int Validar(int Inicio, int Fin) {
  while (Dato < Inicio || Dato > Fin) {
    printf("Ingrese el dato correctamente\n");
    scanf("%d", &Dato);
  }
  return Dato;
}
