#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int longitud;
    printf("introduzca la cantidad de palabras a introducir");
    scanf("%d", &longitud);
    char lista[10][10];
    char temp[10];
    int i;
    int j;
    for(i=0;i<longitud;i++){
        printf("introduzca una palabra");
        scanf("%s", lista[i]);
    }
    for(i=0;i<=longitud;i++)
      for(j=i+1;j<=longitud;j++){
         if(strcmp(lista[i],lista[j])>0){
            strcpy(temp,lista[i]);
            strcpy(lista[i],lista[j]);
            strcpy(lista[j],temp);
         }
      }
    for(i=0;i<longitud;i++){
        printf("%s", lista[i]);
    }
}