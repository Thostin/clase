#include <stdio.h>
#include <stdlib.h>

typedef struct Hour Hour;
typedef struct Hour* Hour_ptr;

#define nullptr NULL;
#define is_legal(n) ((n) > 24 ? 0 : 1)

struct Hour{
  uint8_t hour;
  Hour *next;
}__attribute__((packed));

Hour_ptr init(uint8_t n){
  Hour_ptr ret = calloc(1, sizeof(Hour));
  if(NULL == ret){
    perror("calloc: ");
    return nullptr;
  }

  ret -> hour = n;
  return ret;
}

// 1 means error and 0 means OK
int push(Hour_ptr aux, uint8_t n){
  aux -> next = calloc(1, sizeof(Hour));
  if(NULL == aux -> next){
    perror("calloc: ");
    return 1;
  }

  aux -> next -> hour = n;
  return 0;
}

void s_free(Hour_ptr Hour_aux){
  Hour_ptr aux;
  while(Hour_aux){
    aux = Hour_aux -> next;
    free(Hour_aux);
    Hour_aux = aux;
  }
}

void trab(void){
  printf("*Calculadora de trabajo ficticio**\n");
  printf("Introduzca el sueldo que debe percibir un empleado por cada hora que trabaja: ");

  unsigned por_hora;
  if(printf("\n> "), !scanf(" %u", &por_hora)){
    printf("Improper input\n");
    return;
  }

  int counter = 0;
  uint8_t aux;

  printf("Ahora introduzca las horas que trabajó cada empleado en la última semana: (introduzca algo inválido para finalizar; 0 se considera como que no trabajó)\n");
  if(printf("> "), !scanf(" %hhu", &aux)){
    printf("No se ha introducido nada, chau\n");
    return;
  }
  const Hour_ptr root = init(aux);
  Hour_ptr aux_ptr = root;

  while(printf("> "), scanf(" %hhu", &aux)){
    if(!is_legal(aux))
      break;
    if(push(aux_ptr, aux)){
      printf("Fatal error while calling function 'push'\n");
      return;
    }
    aux_ptr = aux_ptr -> next;
  }

  Hour_ptr kopta = root;
  unsigned sum = 0;
  for(int i = 1; kopta; ++i){
    printf("Trabajador %3d: Gs%d\n", i, (unsigned)(kopta -> hour) * por_hora);
    sum += (unsigned)(kopta -> hour);
    kopta = kopta -> next;
  }
  printf("TOTAL: Gs%d\n", sum * por_hora);
  s_free(root);
}

int main(void){
  trab();
  return 0;
}
