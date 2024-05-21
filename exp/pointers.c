#include <stdio.h>

int f(void) {

  // 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

  int arro[] = {45, 73, 1729, 1777, 23, 37, 91, 9756, 75, 1725, 613286}; // 0000

  const int *ptr = arro;
  int *const ptr2 = arro;

  ptr2[8] = 10;

  printf("tamano: %zu\n", sizeof(ptr));

  printf("arro[0] = %d\n", *(ptr + 0));
  printf("arro[0] = %d\n", 0 [ptr]);
  printf("arro[1] = %d\n", ptr[1]);
  printf("arro[1] = %d\n\n", *(ptr + 1));

  int gapo[70];
  gapo[55] = 56;

  for (int *init = arro; init < arro + (sizeof(arro) / sizeof(int)); ++init) {
    printf("%d ", *init);
  }

  printf("\n\n");

  return 89;
}

// 0x8p46529066
int main(void) { return 0; }

/*
invocar funcion:
copiar los argumentos
pasarle el puntero a los argumentos
tengo que pasarle mi posicion: p23
jump a la funcion
p23

decirle donde retornar
saltar hasta ahi

scyn
wrcynmrv
rvkusth
ser6uebti7
rt7ijt78bkr

puntero a los argumentos
a donde regresar
a donde retornar
ergtj57
trkyn6
rtvbkun67
4vt6ukbmj
56cb46i7b
copiar el valor de retorno
jump a donde estaba

fscnb 0x006734872
*/
/*
Los punteros son direcciones de memoria
0xc2378562490

indica a donde se localiza un unico byte
*/
