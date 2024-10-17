#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    char palabrasecreta[1024];
    
    printf("introduzca la palabra: ");
    scanf("%s", palabrasecreta);
    
    int length = strlen(palabrasecreta);
    char adivinanza[length + 1];
    
    for(i = 0; i < length; i++) {
        adivinanza[i] = '*';
    }
    adivinanza[length] = '\0';

    int chances;
    printf("introduzca cuántas oportunidades tendrá el jugador: ");
    scanf("%d", &chances);

    char letra;
    for(i=0;i<chances;i++){
        printf("%s", adivinanza);
        printf("introduzca la letra ");
        scanf("%c", &letra);
        if(strchr(palabrasecreta, letra)!=NULL){
            for(i=0;i<length;i++){
                if(palabrasecreta[i]==letra){
                    adivinanza[i]=letra;
                }
            }
        }

    }
    if(strcmp(palabrasecreta,adivinanza)==0){
        printf("felicidades!");
    }else{
        printf("bueno, sera mejor la proxima")
    }
}
