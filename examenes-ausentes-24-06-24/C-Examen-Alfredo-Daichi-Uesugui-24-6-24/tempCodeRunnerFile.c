#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int alumnos, afectada, temperatura;
    
    srand(time(NULL));

    //Minimo numero + el numero que da el maximo
    alumnos = rand() % 10 + 20;
   
    temperatura = rand() % 4 + 37;

    for (int i = 0; i < 100; i++){
    temperatura = rand() % 4 + 37;

        printf("%d\n", temperatura);
    }


}