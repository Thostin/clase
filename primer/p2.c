#include <stdio.h>

int main(void){
  char str[9];
  str[8] = 0;
  size_t *p = (char *)str;

  *p = 72164673719462210;
    //72057595806248787;
   // 8026097768406018147;

  printf("%s\n", str);

  return 0;
}
