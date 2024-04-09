#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT 5

typedef int type;

int cmp(const void *a, const void *b) { return (*(type *)a - *(type *)b); }

int main(void) {
  type arr[CANT];

  int gen, poker, foul, escalera;
  int cont;

  char *nom;
  int aux_cantidad_eleccion = 0;
  int aux_cherembito;

  char j1[100], j2[100];
  char *arrnom[] = {j1, j2};
  printf("Jugador 1: ");
  scanf("%99s", j1);

  printf("Jugador 2: ");
  scanf("%99s", j2);

  while (getchar() != '\n')
    ;

  srand(time(NULL));

  int jopta = 0;
  while (1) {
  kuera:
    nom = arrnom[(++jopta) & 1];
    printf("Se generan aleatorios\n");

    for (int j = 0; j < 5; ++j) {
      arr[j] = rand() % 6;
    }

    for (int pop = 0; pop < 3;) {
      printf("Lanza %s... (presiona enter)", nom);
      ++pop;
      getchar();
      qsort(arr, CANT, sizeof(int), cmp);

      for (int kl = 0; kl < CANT; ++kl)
        printf("%d ", 1 + arr[kl]);
      putchar(10);

      if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] &&
          arr[3] == arr[4]) {
        // ++gen;
        printf("%s obtuvo Generala\n", nom);
        goto kuera;
      } else {
        // printf("NO GENERALA\n");
        // printf("a");

        if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) ||
            (arr[1] == arr[2] && arr[2] == arr[3] && arr[3] == arr[4])) {
          // ++poker;
          printf("%s obtuvo Poker\n", nom);
          goto kuera;
        } else {
          // printf("NO POKER\n");
          if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[3] == arr[4]) ||
              (arr[0] == arr[1] && arr[2] == arr[3] && arr[3] == arr[4])) {
            // ++foul;
            printf("%s obtuvo Faul\n", nom);
            goto kuera;
          } else {
            // printf("NO FAUL\n");
            cont = 0;
            for (int aux = 0; aux < CANT - 1; ++aux) {
              if (arr[aux] + 1 != arr[aux + 1]) {
                cont = 1;
                goto pop;
              }
            }
          pop:
            if (0 == cont) {
              // ++escalera;
              printf("%s obtuvo Escalera\n", nom);
              goto kuera;
            }
          }
        }
      }
      if (++pop == 4)
        goto kuera;
      printf("No has ganado nada, elige cuántos dados desea relanzar: ");
      if (!scanf("%d", &aux_cantidad_eleccion)) {
        printf("Improper input\n");
        return 1;
      }

      printf("Elige los dados que desea relanzar: \n");
      for (int y = 0; y < aux_cantidad_eleccion; ++y) {
        // Reutilizando la variable cont
        printf("> ");
        if (!scanf(" %d", &aux_cherembito)) {
          printf("Improper input\n");
          return 1;
        }

        switch (aux_cherembito) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
          arr[aux_cherembito - 1] = rand() & 6;
        }
      }
    }
  }

  return EXIT_SUCCESS;
}
