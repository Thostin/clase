#include <stdio.h>

#define ANO 12
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

char *anos[] = 
  {
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octubre",
    "Noviembre",
    "Diciembre"
  };

int main(int argc, char *argv[])
{
  printf("**AHORROS**\n");
  int lim = ANO;
  int n;
  int sum = 0;
  int arr_sum[ANO];
  int pos = 0;

  while(lim){
    printf("Ahorre algo: ");
    if(scanf(" %d", &n)){
      sum += n;
      arr_sum[pos] = sum;
    }
    else {
      if(getchar() == EOF)
        return 0;
      printf("Improper, retry\n");
      continue;
    }
    --lim; ++pos;
  }

  printf("En total ha ahorrado %d dinero.\n", sum);
  printf("Aquí un recuento de sus ahorros:\n");
  
  for(int i = 0; i < ANO; ++i)
    printf("%s: %d\n", anos[i], arr_sum[i]);
  
  return EXIT_SUCCESS;
}
