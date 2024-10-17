#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int comparar(const void *a, const void *b){
    return strcmp(*(const char **)a, *(const char **)b);
}

void convertir(char *palabla){
    for (int i = 0; palabla[i]; i++)
    {
        palabla[i] = tolower(palabla[i]);
    }
}
int main(){

    char buffer[100];
    int n;

    printf("Introduce la cantidad de palabras a ordenar: ");
    scanf("%d", &n);
    
    getchar();/*se come el salto de linea*/

    char *palabras[n];

    for (int i = 0; i < n; i++)
    {
        printf("Introduce la palabra nro [%d]: ", i+1);
        fgets(buffer, sizeof(buffer), stdin);

        size_t longitud = strlen(buffer);

        if (longitud > 0 && buffer[longitud - 1] == '\n')
        {
            buffer[longitud - 1] = '\0';
        }

        convertir(buffer);

        palabras[i] = malloc(strlen(buffer) + 1);

        if (palabras[i] == NULL)
        {
            printf("Error al asignar memoria. \n");
            return 1;
        }

        strcpy(palabras[i], buffer);

    }

    printf("\nPalabras sin ordenar: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", palabras[i]);
    }

    qsort(palabras, n, sizeof(char *), comparar);

    printf("\nPalabras ordenadas: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", palabras[i]);
        free(palabras[i]);
    }
    
return 0;
}