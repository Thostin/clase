/*dado un texto t, formar una lista "diccionario" conteniendo todas las palabras diferentes que 
existen en t, ordenadas alfabeticamente*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// nimp = no importa - convierte todo a minusculas para facilitar comparar las palabras
void nimp(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        cadena[i] = tolower(cadena[i]);
    }
}

// comparar - ordena las palabras
int comparar(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

// nw = numero de palabras
int verificar(const char texto[], char diccionario[])
{
    int nw = 0;
    int inicio = 0;
    int longitud;
    char temp[50];
    
    for (int i = 0; ; i++)
    {
        if (texto[i] == ' ' || texto[i] == '.' || texto[i] == ',' || texto[i] == '?' || texto[i] == '\n' || texto[i] == '\0') /*no pude poner || texto[i] == '¿' :( )*/
        {
            if (i > inicio)
            {
                longitud = i - inicio;
                if (longitud >= 50)
                {
                    longitud = 50 - 1;
                }
                strncpy(temp, &texto[inicio], longitud);
                temp[longitud] = '\0';
                
                // verifica si la palabra ya esta en el diccionario
                int existe = 0;
                for (int f = 0; f < nw; f++)
                {
                    if (strcmp(&diccionario[f * 50], temp) == 0)
                    {
                        existe = 1;
                        break;
                    }
                }
                
                // agrega la word al diccionario, si es que no existe
                if (!existe)
                {
                    strcpy(&diccionario[nw * 50], temp);
                    nw++;
                    if (nw >= 100)
                    {
                        break;
                    }
                }
            }
            if (texto[i] == '\0')
            {
                break;
            }
            inicio = i + 1;
        }
    }
    return nw;
}

// use punteros pero q miedo -- imprime
void imprimir(char diccionario[], int nw)
{
    char *p[nw];
    for (int i = 0; i < nw; i++)
    {
        p[i] = &diccionario[i * 50];
    }
    qsort(p, nw, sizeof(char *), comparar);
    for (int a = 0; a < nw; a++)
    {
        printf("%s\n", p[a]);
    }
}

int main()
{
    char texto[] = "hola melon";
    printf("%s\n", texto);
    char diccionario[50 * 100];
    int nw;
    nimp(texto);
    nw = verificar(texto, diccionario);
    imprimir(diccionario, nw);
    return 0;
}
