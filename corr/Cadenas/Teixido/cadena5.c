#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1023];
    printf("Introduzca un texto: ");
    scanf("%s", text);

    int length = strlen(text);
    char encriptado[length + 1];
    
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) { 
            if (text[i] == 'Z') {
                encriptado[i] = 'A';
            } else if (text[i] == 'z') {
                encriptado[i] = 'a';
            } else {
                encriptado[i] = (char)(text[i] + 1);
            }
        } else {
            encriptado[i] = text[i];
        }
    }
    
    encriptado[length] = '\0'; 
    
    printf("Texto encriptado: %s\n", encriptado);
    
    return 0;
}
