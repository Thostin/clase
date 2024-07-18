#include <stdio.h>

// No es correcto
int t1(int p, int r) { // prestigio del cliente
  int pre = 0;
  if (r == 1) {
    pre = p * 1;
  } else if (r == 2) {
    pre = p * 3;
  } else if (r == 3) {
    pre = p * 6;
  }
  return pre;
}

// Funciona
void ord(
    int c[], int n,
    int pre[]) { // ordenar los prestigios del cliente en el orden descendente
  int a;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (pre[j] < pre[j + 1]) {
        a = pre[j];
        pre[j] = pre[j + 1];
        pre[j + 1] = a;
        a = c[j];
        c[j] = c[j + 1];
        c[j + 1] = a;
      }
    }
  }
}

// El cliente no puede no atrasarse en ningún préstamo
int vali(int v, int can) { // validacion
  while (v <= 0 || v > can) {
    printf("error, introduzca de nuevo ");
    scanf("%d", &v);
  }
  return v;
}

int main() {
  int n; // variable de cantidad de cliente
  printf("introduzca la cantidad de clientes "); // cantidad de clientes
  scanf("%d", &n);
  n = vali(n, 10000000); // validacion
  int c[n], p, r, pre[n];
  for (int i = 0; i < n; i++) {
    c[i] = i + 1; // prestamo de cada cliente
    printf("introduzca la cantidad de prestamos del cliente %d ",
           i + 1); // cantdad de prestamos del cliente
    scanf("%d", &p);
    p = vali(p, 2);
    printf("introduzca su mes de retraso en total "); // mes de retraso de los
                                                      // prestamos
    scanf("%d", &r);
    r = vali(r, 3);
    pre[i] = t1(p, r);
    printf("el prestigio de este cliente es -%d\n",
           pre[i]); // imprimir el prestigio de este cliente
  }
  ord(c, n, pre); // ordenar en orden descendente
  printf("los clientes ordenados por su cantidad de prestamo\n"); // imprimir
                                                                  // los ordenes
  for (int i = 0; i < n; i++) {
    printf("cliente %d con prestigio -%d\n", c[i], pre[i]);
  }
  return 0;
}
