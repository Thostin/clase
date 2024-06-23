/*
 * I discovered that pressing 'f' in normal mode just crashes neovim
 * and make lose all my progress, nothing to do with the swap file...
 * almost an hour to trash*/

/*
 * Hacer un AHORCADO jajajjaj
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void juego();

/*
 * Nota importante: se leerán dos espacios seguidos como el final de la
 * palabra*/

const char *words[] = {
    "hola", "bienvenido", "exterminador", "caminar", "pelea", "ventana", "amor",
    "matematica", "fisica", "ventilador", "proyector", "techo", "silla",
    "poste", "cartel", "pizarra", "ladrillo", "puerta", "interruptor",
    "enchufe", "hembra", "macho", "hombre", "mujer", "cable", "cortina",
    "bebedero", "camara", "telefono", "conector", "video", "escoba",
    "repasador", "basurero", "bolsa", "madera", "correr", "adinosin trifosfato",
    "campera", "poncho sesenta listas",
    /**/
    "agua", "plastico", "cabello", "gorro", "tapabocas", "mochila", "pared",
    "coordinacion", "streptococcus mutans", "chaqueta", "murcielago",
    "otorrinonaringologo", "nigga", "nigger", "electroencefalografista",
    "calculo integral", "milanesa de pollo", "pupitre", "brea",
    "hipopotomostrosesquipedaliofobia",

    "calculo diferencial", "camara hikvision", "electroban", "informatica",
    "parangarikutirimicuaru", "esternocleidomastoideo", "lobulo occipital",
    "caleidoscopio", "tubo de rayos catodicos", "adolf hitler", "dragon ball",
    "diodo emisor de luz", "escleroesterostico", "mitocondrias",
    "complejo de golgi", "esclerenquimas", "skibidi toilet", "musolini"};

const size_t count_words = sizeof(words) / 8;
// const int changes[] = {55, 86, 87, 88, 119, 150, 152};
const int changes[] = {55, 87, 119, 86, 88, 150, 152};
const char values[] = "o||/\\/\\";
char *act_word = NULL;
int len_act_word = 0;

/*
char screen[] = "                       |------|\n"   // 31
                "                       o      |\n"   // 55 :63
                "                      /|\\     |\n"  // 86, 87, 88 :95
                "                       |      |\n"   // 119 :127
                "                      / \\     |\n"; // 150, 152 :159
*/

#define INIT_WORD 128
char screen[] = "                       |------|\n"  // 31
                "                              |\n"  // 55 :63
                "                              |\n"  // 86, 87, 88 :95
                "                              |\n"  // 119 :127
                "                              |\n"  // 150, 152 :159
                "                               \n"  // 160
                "                               \n"; // 160

void dead_screen(int n) {
  if (n < 0 || n >= 7) {
    printf("Algo raro paso kp\n");
    return;
  }
  screen[changes[n]] = values[n];
}

int main(void) {
  srand(time(NULL));
  juego();
  return 0;
}

int make_screen(const char *str) {
  int chrs_count = 0;
  int pos_screen = INIT_WORD;

  // Assuming NULL-terminated string
  len_act_word = strlen(str);
  for (int i = 0; i < len_act_word; ++i) {
    if (str[i] != ' ') {
      screen[pos_screen] = '*';
      ++chrs_count;
    }
    pos_screen[screen + 32] = '_';
    ++pos_screen;
  }

  return chrs_count;
}

int act_screen(int c) {
  int cant = 0;

  for (int i = 0; i < len_act_word; ++i) {
    if (c == act_word[i]) {
      if (c == screen[i + INIT_WORD]) {
        printf(
            "Esta letra ya fue adivinada (resta intentos de todas formas)\n");
        return 0;
      }
      screen[i + INIT_WORD] = c;
      ++cant;
    }
  }

  return cant;
}

const int lim_att = 7;

void juego() {
  int rand_word = rand() % count_words;
  int att = 0;

  // int actter, c;
  char c;
  int ret, tot = 0;
  act_word = words[rand_word];

  // len_act_word = strlen(act_word);
  const int cant_chrs = make_screen(act_word);

  while (1) {
    printf("%s", screen);
    if (tot == cant_chrs) {
      printf("Ganaste!\n");
      exit(0);
    }

    if (7 == att) {
      printf("No adivinaste la palabra, la palabra era: %s\n", act_word);
      return;
    }

    // printf("actual_letters: %d\n", tot);
    printf("> ");
    while ((c = getchar()) == ' ' || c == '\t' || c == '\n')
      ;
    /*
        printf("Letter readed: %c\n", c);
        getchar();
        getchar();
    */

    if ((ret = act_screen(c)) == 0) {
      dead_screen(att);
      ++att;
    }
    tot += ret;

    // printf("\n\n");
    system("clear");
  }
}

/*
int len_oracion(char *str) {
  int ret = 0;
  while (*str && *str != ' ')
    ++ret;
  if (0 == ret) {
    printf("Somethig happened\n");
    return -1;
  }
  return ret;
}
*/
