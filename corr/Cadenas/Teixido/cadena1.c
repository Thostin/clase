
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TEXT_SIZE 1024

int main() {
    char texto[MAX_TEXT_SIZE];
    printf("Introduzca el texto: ");
    fgets(texto, sizeof(texto), stdin);
    

    size_t len = strlen(texto);
    if (len > 0 && texto[len-1] == '\n') {
        texto[len-1] = '\0';
    }
    
    char *tokens[MAX_TOKENS];
    char *saveptr;
    char *token;
    int token_count = 0;
    
    token = strtok_r(texto, " ", &saveptr);
    while (token != NULL && token_count < MAX_TOKENS) {
        diccionario[token_count] = strdup(token);
        token_count++;
        token = strtok_r(NULL, " ", &saveptr);
    }
    
    
    for (int i = 0; i < token_count - 1; i++) {
        for (int j = i + 1; j < token_count; j++) {
            if (strcmp(tokens[i], tokens[j]) > 0) {
                char *temp = diccionario[i];
                diccionario[i] = diccionario[j];
                diccionario[j] = temp;
            }
        }
    }
    

    printf("diccionario\n");
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", diccionario[i]);
        free(diccionario[i]); 
    }
    
    return 0;
}


    

    

  

