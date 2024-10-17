//conjugar un verbo terminado en ar en tiempo presente
#include<stdio.h>
#include<string.h>
void conjugar(const char *verbo){
    char cdo[100]; //cdo = conjugado
    char n[100]; //nucleo de la palabra, ej cant de cantar
    int longitud = strlen(verbo);

    if (longitud < 3 || strcmp(verbo + longitud - 2, "ar") !=  0) // compara las ultimas letras con ar y da un aviso en caso de no terminar en ar
    {
        printf("La palabra debe terminar en 'ar': ");
        return;
    }

    strncpy(n, verbo, longitud - 2);
    n[longitud - 2] = '\0';
    printf("Yo %so\n", n);
    printf("Tu %sas\n", n);
    printf("El/Ella %sa\n", n); 
    printf("Nosotros %samos\n", n);
    printf("vosotros %sais\n", n);
    printf("Ustedes %san", n);
}
int main(){
    char verbo[100];
    printf("Ingrese una palabra sin conjugar: ");
    if (fgets(verbo, sizeof(verbo), stdin))
    {
        strtok(verbo, "\n"); 
    }
    conjugar(verbo);
    return 0;
}