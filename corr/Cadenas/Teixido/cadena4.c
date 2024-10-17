#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    char verbo[10];
    printf("introduzca un verbo infinitivo con terminacion ar");
    scanf("%s", verbo);
    while(strcmp(verbo[9], "r")!=0 || strcmp(verbo[8], "a")!=0){
        printf("este verbo no esta en el formato indicado");
        scanf("%s", verbo);
    }
    char lexema[8];
    for(i=0;i<8;i++){
        strcpy(lexema[i], verbo[i]);
    }
    printf("primera persona: yo %s", strcat(lexema, "o"));
    printf("segunda persona: tu %s", strcat(lexema, "as"));
    printf("tercera persona: el/ella %s", strcat(lexema, "a"));
    printf("primera persona plural: nosotros %s", strcat(lexema, "amos")); 
    printf("segunda persona plurla: ustedes %s", strcat(lexema, "an"));
    printf("tercera persona plural: ellos %s", strcat(lexema, "an"));

}  