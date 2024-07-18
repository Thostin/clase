// El Banco de la Capital requiere de un programa que pueda seleccionar a aquel
// cliente de mayor prestigio para otorgarle bono exclusivo. El prestigio de un
// cliente se mide por su rapidez en los pagos. Si un cliente se retrasa un mes
// en un pago, es restado a su nivel de prestigio 1 punto, si se retrasa dos
// meses, se le resta 3 puntos(1 por el primer mes, 2 por el segundo), si se
// atrasa tres meses, se le reta 6 puntos(1 por el primer mes, 2 por el segundo,
// 3 por el tercero). El cliente con un puntaje mas cerecano al cero, es decir,
// menos puntajes restados, es el mas prestigioso. Permitir la carga de la
// cantidad (N) de clientes, la cantidad de prestamos realizados por cada uno y
// lo meses de retraso que tuvo en cada pago. Imprimir en pantalla al cliente
// mas prestigio junto a su nombre y seguido a el a otros clientes de manera
// descendente en referencia a su cercania con el 0.
#include <stdio.h>
int va(int cantpres, int mesret, int clien) {
  while (clien <= 0) {
    printf("Errorrr...Introduzca de nuevo");
    scanf("%d", &clien);
  }
  while (cantpres <= 0 || cantpres > 2) {
    printf("Errorrr...Introduzca de nuevo");
    scanf("%d", &cantpres);
  }
  while (mesret <= 0 || mesret > 3) {
    printf("Errorrr...Introduzca de nuevo");
    scanf("%d", &mesret);
  }
}

int pres(int clien[], int cantpres, char clie, int mesret) {
  int i = 0;
  printf("Introduzca la cantidad de clientes");
  scanf("%d", &clien[i], va(clien));
  printf("Introduzca el nombre del cliente %d:\n");
  scanf("%d", &clie);
  printf("Introduzca la cantidad de prestamo de cliente %d(un cliente solo "
         "puede tener 2 préstamos):");
  scanf("%d", &cantpres, va(cantpres));
  printf("Introduzca la cantidad de mes de retraso (máximo 3 meses)");
  scanf("%d", &mesret, va(mesret));
}
3 int calcu(int cantpres, int clien[], int mesret, int p, int i) {
  p = 100;
  for (i = 0; i < clien; i++) {
    if (cantpres == 1) {
      switch (mesret) {
      case 1:
        p - 1;
      case 2:
        p - 3;
      case 3:
        p - 6;
      }
    }
    if (cantpres == 2) {
      switch (mesret) {
      case 1:
        p - 2;
      case 2:
        p - 6;
      case 3:
        p - 12;
      }
    }
  }
}

int main() {
  printf("El cliente mas prestigioso es:");
  return 0;
}
