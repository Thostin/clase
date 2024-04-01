#include <stdio.h>

int main(void){
  printf("Cantidad de alumnos hay en el quinto curso de informática: ");
  int n;

  if(!scanf(" %d", &n) || n <= 0 || n > 200){
    printf("Improper input\n");
    return 1;
  }

  int vec[n];
  for(int i = 0; i < n; ++i){
    printf("Edad de alumno %d: ", i+1);
    if(!scanf("%d", vec + i) || vec[i] <= 3 || vec[i] > 60){
      printf("Improper input\n");
      return 1;
    }
  }

  int sum = 0;
  for(int i = 0; i < n; ++i){
    sum += vec[i];
  }
  printf("Promdio de las edades: %.2lf\n", (double)sum / n);
  
  return 0;
}
