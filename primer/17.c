#include <stdio.h>
#include <stdlib.h>

typedef union Week Week;
typedef union Week* Week_ptr;

typedef struct Week_list Week_list;;
typedef struct Week_list* Week_list_ptr;

#define nullptr NULL
#define is_legal(a) (a > 24 ? 0 : 1)

struct __Week{
  unsigned hour_1 : 5;
  unsigned hour_2 : 5;
  unsigned hour_3 : 5;
  unsigned hour_4 : 5;
  unsigned hour_5 : 5;
  unsigned hour_6 : 5;
  unsigned hour_7 : 5;
};

union Week{
  struct __Week w;
  uint64_t carrer;
};

struct Week_list{
  Week week;
  Week_list_ptr next;
};

Week_list_ptr init(Week w){
  Week_list_ptr _w = calloc(1, sizeof(Week_list));
  if(NULL == _w){
    perror("calloc: ");
    return nullptr;
  }
  _w -> week = w;
  return _w;
}

// 1 means error and 0 means OK
int push(Week_list_ptr aux, Week w){
  aux -> next = calloc(1, sizeof(Week_list));
  if(NULL == aux -> next){
    perror("calloc: ");
    return 1;
  }

  (aux -> next) -> week = w;
  return 0;
}

void s_free(Week_list_ptr root){
  Week_list_ptr aux;
  while(root){
    aux = root -> next;
    free(root);
    root = aux;
  }
}

int leer_semana(Week_ptr w){
  unsigned aux;

  printf("Lunes: ");
  if(!scanf(" %u", &aux) || !is_legal(aux)) return 1;
  w -> w.hour_1 = aux;
  while(getchar() != '\n');

  printf("Martes: ");
  if(!scanf(" %u", &aux) || !is_legal(aux)) return 1;
  w -> w.hour_2 = aux;
  while(getchar() != '\n');

  printf("Miércoles: ");
  if(!scanf(" %u", &aux)|| !is_legal(aux)) return 1;
  w -> w.hour_3 = aux;
  while(getchar() != '\n');

  printf("Jueves: ");
  if(!scanf(" %u", &aux)|| !is_legal(aux)) return 1;
  w -> w.hour_4 = aux;
  while(getchar() != '\n');

  printf("Viernes: ");
  if(!scanf(" %u", &aux)|| !is_legal(aux)) return 1;
  w -> w.hour_5 = aux;
  while(getchar() != '\n');

  printf("Sábado: ");
  if(!scanf(" %u", &aux)|| !is_legal(aux)) return 1;
  w -> w.hour_6 = aux;
  while(getchar() != '\n');

  printf("Domingo: ");
  if(!scanf(" %u", &aux)|| !is_legal(aux)) return 1;
  w -> w.hour_7 = aux;
  while(getchar() != '\n');

  return 0;
}

void mostrar_trabajadores(Week_list_ptr root, unsigned por_hora){
  Week_list_ptr aux = root;
  unsigned sum = 0;

  system("clear");
  printf("**REGISTRO**\n\n");
  for(int i = 1; aux; ++i){
    printf("\nTrabajador %d:\n", i);
    printf("Lunes: ");
    if(aux -> week.w.hour_1 == 0)
      printf("No trabajó");
    else
      printf("%u horas", aux -> week.w.hour_1);
    putchar(10);
    sum += aux -> week.w.hour_1;

    printf("Martes: ");
    if(aux -> week.w.hour_2 == 0)
      printf("No trabajó");
    else
      printf("%u horas", aux -> week.w.hour_2);
    putchar(10);
    sum += aux -> week.w.hour_2;

    printf("Miércoles: ");
    if(aux -> week.w.hour_3 == 0)
      printf("No trabajó");
    else
      printf("%u horas", aux -> week.w.hour_3);
    putchar(10);
    sum += aux -> week.w.hour_3;

    printf("Jueves: ");
    if(aux -> week.w.hour_4 == 0)
      printf("No trabajó");
    else
      printf("%u horas", aux -> week.w.hour_4);
    putchar(10);
    sum += aux -> week.w.hour_4;

    printf("Viernes: ");
    if(aux -> week.w.hour_5 == 0)
      printf("No trabajó");
    else
      printf("%u horas", aux -> week.w.hour_5);
    putchar(10);
    sum += aux -> week.w.hour_5;

    printf("Sábado: ");
    if(aux -> week.w.hour_6 == 0)
      printf("No trabajó");
    else
      printf("%u horas", aux -> week.w.hour_6);
    putchar(10);
    sum += aux -> week.w.hour_6;

    printf("Domingo: ");
    if(aux -> week.w.hour_7 == 0)
      printf("No trabajó");
    else
      printf("%u horas", aux -> week.w.hour_7);
    putchar(10);
    printf("--------------------\n");
    sum += aux -> week.w.hour_7;
    aux = aux -> next;
  }

  printf("\n-----------------\n");
  printf("TOTAL A PAGAR: Gs%u\n", sum * por_hora);
}

void trab(void){
  printf("**CALCULADORA DE PAGO**\n");
  printf("Ingrese el pago por hora que debe percibir un trabajador: ");

  unsigned por_hora;
  if(!scanf(" %u", &por_hora)){
    printf("Improper input\n");
    return;
  }

  printf("Deberá ingresar las horas que trabajó cada empleado cada día de la semana, introduzca algo inválido para finalizar; 0 simboliza que ese día el empleado no trabajó.\n");
  Week w;
  printf("Trabajador 1: \n");
  if(leer_semana(&w)){
    printf("No se ha introducido nada, chau\n");
    return;
  }
  const Week_list_ptr root = init(w);
  Week_list_ptr kopta = root;

  for(int i = 2; 1; ++i){
    printf("\nTrabajador %d: \n", i);
    if(leer_semana(&w))
      break;
    if(push(kopta, w)){
      printf(" <<< trab: Fatal error <push>\n");
      return;
    }
    kopta = kopta -> next;
  }

  mostrar_trabajadores(root, por_hora);
  s_free(root);
}

int main(void){
  // printf("sizeof(Week): %zu\n", sizeof(Week));
  trab();
  return 0;
}
