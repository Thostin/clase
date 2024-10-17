#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char nro[10][10];
    int cantidad;
    printf("introduzca la cantidad");
    scanf("%d", &cantidad);
    int i;
    int j;
    int iguales;
    int k;
    char simetricos[10][10];
    for(i=0;i<cantidad;i++){
        printf("introdzuca el nro");
        scanf("%s", &nro[i]);
        for(j=0;j<strlen(nro[i]);j++){
            if(nro[j]==nro[n-j]){
                iguales++;
            }
        }
        if(iguales=strlen(nro[i])){
            strcopy(simetricos[k++], nro[i]);
        }
    }

    
    
    for(i=0;i<k;i++){
        printf("%d\n", simetricos[i]);
    }
}