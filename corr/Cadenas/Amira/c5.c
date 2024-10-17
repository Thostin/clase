/*dado un texto, codificar su contenido cambiando cada letra por la que le sigue en el alfabeto. ej la z por la a*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void codefica(char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) 
    {
        if (isalpha(texto[i])) 
        { // Comprueba si se trata de una letra
            if (texto[i] == 'z') 
            {
                texto[i] = 'a'; // si es z cambia a 'a'
            } 
            else if (texto[i] == 'Z') 
            {
                texto[i] = 'A'; // Lo mismo que el anterior pero con mayusculas
            } 
            else 
            {
                texto[i]++; // Change to the next letter in the abcs
            }
        }
    }
}
int main(){
    char texto[150];
    printf("Ingrese un texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; 
    codefica(texto); //invocamos al procedimiento
    printf("NUEVO TEXTO CODIFICADO: %s\n", texto);
    return 0;
}