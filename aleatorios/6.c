/*
 * Esta ya te la sabés
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT 5

typedef int type;

int main(void) {
  int primos[] = {1, 2, 3, 5, 7, 11};
  type arr[CANT];

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

  int mul;
  int jopta = 0;
  while (1) {
  restart:
    nom = arrnom[(++jopta) & 1];

    mul = 1;
    for (int j = 0; j < 5; ++j) {
      arr[j] = rand() % 6;
      mul *= primos[arr[j]];
    }

    for (int pop = 0; pop < 3;) {
      printf("Lanza %s... (presiona enter)", nom);
      getchar();

      for (int i = 0; i < CANT; ++i) {
        printf("%d ", arr[i] + 1);
      }
      putchar(10);
      ++pop;

      switch (mul) {
        // GENERALA
      case 1:
      case 32:
      case 243:
      case 3125:
      case 16807:
      case 161051:
        printf("%s obtuvo generala!\n", nom);
        goto restart;

        // POKER:

      case 16:
      case 81:
      case 625:
      case 2401:
      case 14641:
      case 2:
      case 162:
      case 1250:
      case 4802:
      case 29282:
      case 3:
      case 48:
      case 1875:
      case 7203:
      case 43923:
      case 5:
      case 80:
      case 405:
      case 12005:
      case 73205:
      case 7:
      case 112:
      case 567:
      case 4375:
      case 102487:
      case 11:
      case 176:
      case 891:
      case 6875:
      case 26411:
        printf("%s obtuvo poker!\n", nom);
        goto restart;

        // FAUL:

      case 8:
      case 27:
      case 125:
      case 343:
      case 1331:
      case 4:
      case 108:
      case 500:
      case 1372:
      case 5324:
      case 9:
      case 72:
      case 1125:
      case 3087:
      case 11979:
      case 25:
      case 200:
      case 675:
      case 8575:
      case 33275:
      case 49:
      case 392:
      case 1323:
      case 6125:
      case 65219:
      case 121:
      case 968:
      case 3267:
      case 15125:
      case 41503:
        printf("%s obtuvo Faul!\n", nom);
        goto restart;
        /// ESCALERA:

      case 210:
      case 2310:
        printf("%s obtuvo Escalera!\n", nom);
        goto restart;
      }

      if (pop + 1 == 4) {
        printf("No ha ganado nada, turno siguiente\n");
        goto restart;
      }
      printf("No has ganado nada, elige cuántos dados desea relanzar: ");
      if (!scanf("%d", &aux_cantidad_eleccion)) {
        printf("Improper input\n");
        return 1;
      }

      printf("Elige los dados que desea relanzar: \n");
      for (int y = 0; y < aux_cantidad_eleccion; ++y) {
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
          arr[aux_cherembito - 1] = rand() % 6;
        }
      }
      while (getchar() != '\n')
        ;

      fseek(stdin, -1, SEEK_CUR);

      mul = 1;
      for (int j = 0; j < 5; ++j) {
        mul *= primos[arr[j]];
      }
    }
  }

  return EXIT_SUCCESS;
}
