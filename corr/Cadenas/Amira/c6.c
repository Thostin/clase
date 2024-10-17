/*obtener el diminutivo de un nombre dado, como pedro ----> pedrito*/
#include<stdio.h>
#include<string.h>
/*cadim = cambiar a diminutivo
lg = longitud*/
void cadim(char *nombre, char *diminutivo){
    int lg = strlen(nombre);
    strncpy(diminutivo, nombre, lg - 1); //copia el nombre sin el ultimo caracter al diminutivo
    diminutivo[lg- 1] = '\0'; //especifica el final
    if (nombre[lg - 1] == 'a')//si termina em a le agrega ita, sino ito
    {
        strcat(diminutivo, "ita");
    }
    else
    {
        strcat(diminutivo, "ito");
    }
}
int main(){
    char nombre[100], diminutivo[100];
    printf("Ingrese su nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';//eliminar salto de linea generado por fgets
    cadim(nombre, diminutivo);
    printf("\t hola %s", diminutivo);
    return 0;
}