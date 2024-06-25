#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Cargamos unos 8 numeros al cada numero telefonico, de forma aleatoria, y 
hay q aclarar cada numero telefonico comienza en 0*/
int cargar_numeros_de_telefono(int valor){
    for (int i = 0; i < 9; i++)
    {
        valor*=10;
        valor+=rand()%10;
    }
    return valor;
}

//Funcion para mostrar los numeros telefonicos que terminan en 2
void mostrar_los_numero_telefonicos_que_terminan_en_2(int vector[], int cant){
    int aux=0;
    printf("Mostrando los numeros que terminan en 2\n");
    for (int i = 0; i < cant; i++)
    {
        aux=vector[i];
        aux%=10;
        if (aux==2)
        {
            printf("El habitante %d tiene su numero terminado en 2 y es: %d\n", i+1, vector[i]);
        }
    }
}

int main()
{
    //Inicializando mi variable de cantidad de personas en Vallemi
    int n;
    srand(time(NULL));
    printf("BIENVENIDO A LA GUIA TELEFONICA DE VALLEMI\n");
    printf("Ingrese la cantidad de personas en la cuidad: ");
    scanf("%d", &n);
    while (n<1)
    {
        printf("ERROR\nIngrese la cantidad de personas en la cuidad: ");
        scanf("%d", &n);
    }
    
    //Inicializamos y cargamos el vector
    int telefonos[n];
    for (int i = 0; i < n; i++)
    {
        telefonos[i]=0;
        telefonos[i]=cargar_numeros_de_telefono(telefonos[i]);
    }

    //Mostramos los habitantes y sus numeros correspondientes
    for (int i = 0; i < n; i++)
        printf("El habitante %d tiene su numero: 0%d\n", i+1, telefonos[i]);

    //Llamando al procedimiento
    mostrar_los_numero_telefonicos_que_terminan_en_2(telefonos, n);
    printf("\nFinalizo el programa\n"); //Esto era pq no me compilaba pero lo dejo
    return 0;
}
