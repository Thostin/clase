#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CLEAR "clear"

#ifdef _WIN32
#undef CLEAR 
#define CLEAR "cls"
#endif 

time_t atoulong(char *str){
  int len = strlen(str);
  int mul = 1;
  time_t ret = 0;
  while(--len >= 0){
    ret += (str[len] - '0') * mul;
    mul *= 10;
  }

  return ret;
}

void set_clock(time_t sec){
  time_t init = time(NULL);
  time_t dif = 0;
  time_t act = init;

  time_t hour, min, seg;
  //printf("sec: %ld", sec);
  //getchar();

  do{
    system(CLEAR);
    hour = dif / 3600;
    min = (dif -= 3600 * hour) / 60;
    seg = dif - min;

    printf("%ld:%ld:%ld\n", hour, min, seg);
    act = time(NULL);
  } while((dif = act - init) < sec);
  system(CLEAR);
  hour = dif / 3600;
  min = (dif -= 3600 * hour) / 60;
  seg = dif - min;
  printf("%ld:%ld:%ld\n", hour, min, seg);

}

int main(int argc, char *argv[]){
  fclose(stdin);
  if(argc != 2){
    printf("Improper input\n");
    return 1;
  }

  set_clock(atoulong(argv[1]));
  return 0;
}
