#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    char nombre[1024];
    char newname[2048];  
    int ultimo;
    
    printf("Introduzca el nombre: ");
    scanf("%s", nombre);
  
    ultimo = strlen(nombre) - 1;
    char genero;
    printf("Introduzca el genero de la persona (m/f): ");
    scanf("%c", &genero);
    for(i=0;i<ultimo-1;i++){
        nombre[i]=newname[i];
    }

    if (genero == 'm') {
        if (nombre[ultimo] == 'i' || nombre[ultimo] == 'y') {
            strcat(newname, "icito");
        } else {
            strcat(newname, "ito");
        }
    } else if (genero == 'f') {
        if (nombre[ultimo] == 'i' || nombre[ultimo] == 'y') {
            strcat(newname, "icita");
        } else {
            strcat(newname, "ita");
        }
    } else {
        printf("genero no reconocido.\n");
        
    }
    
    printf("diminutivo %s\n", newname);
    return 0;
}
