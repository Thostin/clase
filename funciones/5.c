#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct Div {
  int cociente, resto;
};

#undef div
/*5.1: Calcular el cociente y el resto de una división entera*/
void ddiv(struct Div *kopta, int dividendo, int divisor) {
  int ret = dividendo / divisor;
  kopta->cociente = ret;
  kopta->resto = dividendo - ret * divisor;
}

int is(int min, int max, int temperatura) {
  if (temperatura < min || temperatura > max)
    return 1;
  return 0;
}

int calcular_nota(int puntaje) {
  if (puntaje < 1)
    return 0;
  if (puntaje < 61)
    return 1;

  if (puntaje < 71)
    return 2;
  if (puntaje < 81)
    return 3;

  if (puntaje < 95)
    return 4;

  if (puntaje < 101)
    return 5;
  return 0;
}

void examen(void) {
  printf("Ingrese cuántos exámemes ha tenido: ");
  int lim;
  if (0 == scanf("%d", &lim) || lim < 1 || lim > 20) {
    printf("????\n");
    return;
  }

  int tot = 0;
  int8_t arr[lim];
  int8_t aux;
  for (int i = 0; i < lim; ++i) {
    printf("> ");
    if (0 == scanf("%hhu", &aux) || aux < 1 || aux > 100) {
      printf("No pongas que cualquier cosa...\n");
      return;
    }
    arr[i] = aux;
    tot += (int)aux;
  }
  printf("Correspondientes calificaciones para cada ¿examen?:\n");
  for (int i = 0; i < lim; ++i) {
    printf("%3d -> %d\n", arr[i], calcular_nota(arr[i]));
  }
}

int main(void) {
  examen();

  return 0;
}

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
void ordenar_cuatro_variables(int arr[4]) { qsort(arr, 4, sizeof(int), comp); }

struct Registro {
  struct Registro *next;
  int codigo;
  double capital;
  uint16_t dia_comercial;
  double interes; // Del 0 al 1;
};

void calcular_intereses(struct Registro *node) {
  int total_clientes = 0;
  double total_capital = 0.0L;
  double total_intereses = 0.0L;
  double aux;
  for (int i = 1; node; ++i) {
    ++total_clientes;
    total_capital += node->capital;
    aux = (double)((double)node->capital * node->interes *
                   ((double)(360 - node->dia_comercial)) / 360.0L);
    total_intereses += aux;
    printf("%5d -> %lf\n", i, aux);
    node = node->next;
  }
  printf("TOTAL CAPITAL:   %.13lf\n"
         "TOTAL CLIENTES:  %d\n"
         "TOTAL INTERESES: %.13lf\n",
         total_capital, total_clientes, total_intereses);
}

struct Reg_num {
  struct Reg_num *next;
  double a, b;
};

#define abs(a) ((a) < 0 ? -(a) : (a))
double calcular_y(struct Reg_num *node) {
  double sum = 0, abs1, abs2;
  while (node) {
    abs1 = abs(node->a);
    abs2 = abs(node->b);
    if (abs1 == abs2) {
      sum += node->a - 2 * node->b;
    } else if (abs1 > abs2) {
      sum += node->a + node->b;
    } else {
      sum += node->a + node->b - 5;
    }
    node = node->next;
  }
  return sum;
}
