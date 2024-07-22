#include "func.h"
#include <stdio.h>

/*
 * Es de esos problemas que requieren de funciones recursivas
 *
 * En teoría puedo optimizar muchísimo, usando cada bit como 1 o 0
 * */

#define LIM_SUP 50

typedef struct Path Path;
typedef int type_map;
typedef unsigned type_steps;

struct Path {
  unsigned mov : 2;
  // De 1 a tres colgados, si tiene menos es que fracasó como movimiento
  unsigned colgados : 3;
  Path *above;

} __attribute__((packed));

Path *current_shortest_path = nullptr;
unsigned current_steps = 2000000000;

void rellenar_mod_2(type_map *arr, int f_c) {
  for (int i = 0; i < f_c; ++i) {
    arr[i] = rand() % 8 <= 2 ? 1 : 0;
  }
}

// init_y es la fila, init_x es la columna
/*
 * Cómo funciona: Se llama recursivamente, si llega a un estado en el que no
 * tiene movimientos válidos, entonces retorna EXIT_FAILURE. Si llega al
 * objetivo retorna EXIT_SUCCESS. Si ninguna de las llamadas recursivas retorna
 * EXIT_SUCCESS, entonces retorna EXIT_FAILURE, caso contrario retorna
 * EXIT_SUCCESS. La función verifica de antemano si ya se ha llegado a la
 * posición siguiente en menos pasos antes de hacer la llamada, y también
 * verifica que sea una posición válida, a eso lo llamo verificar que sea un
 * movimiento válido. Está claro que no se debe retroceder, por ende, si fue
 * hacia la derecha, no debe probar si un movimiento a la izquierda es válido,
 * porque ya se sabe que no lo será, pero de todas formas no pasaría nada ya que
 * la cantidad de pasos será inferior (Adelanto: opté por lo segundo porque
 * pienso que así el código será más legible y corto). Estoy casi convencido de
 * que estas son las condiciones suficientes para que el algoritmo encuentre el
 * camino más corto. Si la función retorna EXIT_FAILURE en _main() o
 * current_shortest_path es nullptr después de llamar a la función, es que no
 * existe camino posible. Una optimización sería que si se encuentra rodeado de
 * 1's, entonces marque esa casilla del mapa como un 1, ya que de todas formas
 * no hay manera de que esa posición sea una de la que se pueda llegar al
 * objetivo con las reglas antes mencionadas; otra opción es que se marque con
 * un 0 esa posición en el mapa de pasos, para que ninguna llamada recursiva se
 * encuentre conque pueda llegar hasta ahí en menos pasos, y por ende será a
 * partir de ese momento una casilla inválida.
 * */

void clear_path(Path *ptr) {
  if (nullptr == ptr)
    return;
  if (ptr->above != nullptr && 0 == --((ptr->above)->colgados))
    clear_path(ptr->above);
  free(ptr);
  ptr = nullptr;
}

type_map *lab_access_func;
type_steps *positions;

int f, c;

int is_legal_position(int fil, int col, type_steps steps) {
  if (fil < 0 || fil >= f || col < 0 || col >= c ||
      lab_access_func[fil * c + col] == 1 ||
      positions[fil * c + col] <= steps || steps >= current_steps)
    return 0;
  return 1;
}

// y: filas.
// x: columnas.
int obj;
int encontrar_camino_mas_corto(int y, int x, type_steps steps, Path *from) {
  // Se asume que es una posición válida
  positions[y * c + x] = steps;
  ++steps;

  if (nullptr != from)
    from->colgados = 4;
  int legal_pos_1 = is_legal_position(y - 1, x, steps);
  int legal_pos_2 = is_legal_position(y, x + 1, steps);
  int legal_pos_3 = is_legal_position(y + 1, x, steps);
  int legal_pos_4 = is_legal_position(y, x - 1, steps);
  int sum = legal_pos_1 + legal_pos_2 + legal_pos_3 + legal_pos_4;

  if (nullptr != from)
    from->colgados = sum;
  if (0 == sum) {
    // Solo en este caso se limpia todo
    clear_path(from);
    from = nullptr;
    return EXIT_FAILURE;
  }
  //
  // Uno de los path_n queda sin utilizarse sí o sí
  Path *path1, *path2, *path3, *path4;
  int ret = 0;
#define mova(legal_pos, path, move, Y, X)                                      \
  if (legal_pos) {                                                             \
    path = malloc(sizeof(Path));                                               \
    path->above = from;                                                        \
    path->mov = move;                                                          \
    if (obj == (Y) * c + X) {                                                  \
      clear_path(current_shortest_path);                                       \
      current_shortest_path = path;                                            \
      current_steps = steps;                                                   \
      if (nullptr != from)                                                     \
        from->colgados = 1;                                                    \
      return EXIT_SUCCESS;                                                     \
    }                                                                          \
    ret += encontrar_camino_mas_corto(Y, X, steps, path);                      \
  }

  mova(legal_pos_1, path1, 0, y - 1, x);
  mova(legal_pos_2, path2, 1, y, x + 1);
  mova(legal_pos_3, path3, 2, y + 1, x);
  mova(legal_pos_4, path4, 3, y, x - 1);

  return ret == 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}

#define MUNECO 99
void mostrar_matriz_sin_ceros(int *mat, int f, int c) {
  putchar(' ');
  for (int i = 0; i < c + 1; ++i) {
    printf("__");
  }
  putchar(10);
  for (int i = 0; i < f; ++i) {
    printf("| ");
    for (int j = 0; j < c; ++j) {
      if (0 == mat[c * i + j])
        printf("  ");
      else if (MUNECO == mat[c * i + j])
        printf("\u25A0 ");
      else
        printf("%" TYPE_FORMAT " ", mat[c * i + j]);
    }
    printf(" |");
    putchar(10);
  }
  putchar(' ');
  for (int i = 0; i < c + 1; ++i) {
    printf("__");
  }
  putchar(10);
}

void mostrar_matriz_con_ceros(int *mat, int f, int c) {
  putchar(' ');
  for (int i = 0; i < c + 1; ++i) {
    printf("__");
  }
  putchar(10);
  for (int i = 0; i < f; ++i) {
    printf("| ");
    for (int j = 0; j < c; ++j) {
      if (MUNECO == mat[c * i + j])
        printf("\u25A0 ");
      else
        printf("%" TYPE_FORMAT " ", mat[c * i + j]);
    }
    printf(" |");
    putchar(10);
  }
  putchar(' ');
  for (int i = 0; i < c + 1; ++i) {
    printf("__");
  }
  putchar(10);
}

#define TIME_SPAN 100000
/* No sé cómo, pero esta función salió a la primera que fachaaaaa
 * */
void mostrar_matriz_animada(int *mat, int f, int c) {

  for (int k = 1; k <= f; ++k) {
    putchar(' ');
    for (int i = 0; i < c + 1; ++i) {
      printf("__");
    }
    putchar(10);
    for (int i = 0; i < k; ++i) {
      printf("| ");
      for (int j = 0; j < c; ++j) {
        if (0 == mat[c * i + j])
          printf("  ");
        else if (MUNECO == mat[c * i + j])
          printf("\u25A0 ");
        else
          printf("%" TYPE_FORMAT " ", mat[c * i + j]);
      }
      printf(" |");
      putchar(10);
    }
    for (int i = k; i < f; ++i) {
      printf("| ");
      for (int j = 0; j < c; ++j) {
        printf("%" TYPE_FORMAT " ", mat[c * i + j]);
      }
      printf(" |");
      putchar(10);
    }
    putchar(' ');
    for (int i = 0; i < c + 1; ++i) {
      printf("__");
    }
    putchar(10);
    putchar(10);
    usleep(60000);
    system("clear");
  }

  // putchar(10);
}

int _main(void) {
  srand(time(nullptr));
  int filas, columnas;

  system("clear");
  printf("Ingrese las dimensiones de la matriz de f * c:\nf> ");
  leer_dimension(&filas);
  printf("c> ");
  leer_dimension(&columnas);

  f = filas;
  c = columnas;
  type_map lab[f * c];

  // Aquí se guardarán las posiciones en las que el personaje ya ha estado
  type_steps pos_buf[f * c];
  __builtin_memset(pos_buf, 255, f * c * sizeof(type_steps));
  positions = pos_buf;
  lab_access_func = lab;
#define INIT_F 0
#define INIT_C 0
#define OBJ_F (f - 1)
#define OBJ_C (c - 1)

  rellenar_mod_2(lab, f * c);

  // obj = c * f - 1
  obj = OBJ_F * c + OBJ_C;
  lab[INIT_F * c + INIT_C] = 0;
  lab[obj] = 0;

  printf("El mapa:\n");
  mostrar_matriz_con_ceros(lab, f, c);
  printf("\n\n");

  encontrar_camino_mas_corto(INIT_F, INIT_C, 0, nullptr);

  printf("Veamos si se pudo... ");
  if (nullptr != current_shortest_path) {
    printf("Sí se pudo, sí se pudo\n\n");

    const char *mensajes[] = {"Up", "Right", "Down", "Left"};
    Path *aux = current_shortest_path;
    int moves[current_steps];
    unsigned i = current_steps - 1;
    while (nullptr != current_shortest_path) {
      printf("%s ", mensajes[current_shortest_path->mov]);
      moves[i] = current_shortest_path->mov;
      --i;
      current_shortest_path = current_shortest_path->above;
      free(aux);
      aux = current_shortest_path;
    }
    getchar();
    printf("\n\nPresiona ENTER para animar... ");
    getchar();

    *lab = MUNECO;
    system("clear");
    int pos_f = 0, pos_c = 0;
    mostrar_matriz_animada(lab, f, c);

    mostrar_matriz_sin_ceros(lab, f, c);
    usleep(TIME_SPAN);

    for (i = 0; i < current_steps; ++i) {
      // printf("%s ", mensajes[moves[i]]);
      lab[pos_f * c + pos_c] = 0;
      switch (moves[i]) {
      case 0:
        --pos_f;
        lab[pos_f * c + pos_c] = MUNECO;
        break;
      case 1:
        ++pos_c;
        lab[pos_f * c + pos_c] = MUNECO;
        break;
      case 2:
        ++pos_f;
        lab[pos_f * c + pos_c] = MUNECO;
        break;
      case 3:
        --pos_c;
        lab[pos_f * c + pos_c] = MUNECO;
      }
      system("clear");
      mostrar_matriz_sin_ceros(lab, f, c);
      if (i + 1 < current_steps)
        putchar(10);
      usleep(TIME_SPAN);
    }
  } else
    printf("No se pudo :(");
  putc(10, stdout);

  return EXIT_SUCCESS;
}

int main(void) { return _main(); }
