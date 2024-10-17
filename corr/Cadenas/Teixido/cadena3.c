#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char nro[5];
    printf("introduzca el numero");
    scanf("%s", nro);
    int ultimo = strlen(nro)-1;
    if(nro[0]==nro[ultimo]){
        printf("es capicua");
    }
    else{
        printf("no es capicua");
    }
}