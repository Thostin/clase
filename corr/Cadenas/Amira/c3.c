//verificar si un nro es capicua
#include<stdio.h>
#include<string.h>

int main(){
    char longcad[100], invertida[100]; //se determina la longitud de la cadena y se crea cm una copia de esta que sera de utilidad mas adelamte 
    printf("Introduce un numero: ");
    scanf("%99s", longcad);
    int len = strlen(longcad);
    strcpy(invertida, longcad); //se crea una copia exacta de la cadena longcad en invertida
    int inicio = 0;
    int fin = len - 1;
    //invertir la cadena
    while (inicio < fin)
    {
        char aux = invertida[inicio];
        invertida[inicio] = invertida[fin];
        invertida[fin] = aux;
        inicio++;
        fin--;
    }
    //imprimir los resultados
    if (strcmp(longcad, invertida) == 0)
    {
        printf("El numero es capicua");
    }
    else
    {
        printf("El numero no es capicua");
    }
    return 0;
}