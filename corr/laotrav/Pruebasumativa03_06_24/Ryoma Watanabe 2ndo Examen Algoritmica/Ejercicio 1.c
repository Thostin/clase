#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//El banco de la capital requiere de un programa que pueda seleccionar a aquel cliente de mayor prestigio para otorgarle bono exclusivo. El prestigio de un cliente se mide por su rapidez en los pagos. Si un cliente se retrasa un mes en un pago, es restado a su nivel de prestigio 1 punto, si se retrasa dos meses, se le resta 3 puntos (1 por el rpimer mes, 2 por el segundo) Solo se puede retrasar 3 meses. El cliente con mas cercania al 0 es el mas prestigioso. Permitir la carga de la cantidad n de clientes, la cantidad de prestamo realizados por cada uno (solo puede hacer hasta 2 prestamos), y los meses de retraso que tubo el cliente(solo puede retrasarse hasta 3 meses) Imprimir en pantalla al cliente mas prestigioso y seguido a el los otros clientes de manera descendente en referencia a su cercania al 0
//FUncion para calcular prestigio
void calcularprestigio(int n, int prestamo[], int retraso[], int cliente[])
{
    for (int i = 0; i < n; i++)
    {
        while (prestamo[i] != 0)
        {
            if (retraso[i] == 1)
            {
                cliente[i] += 1;
            }
            else if (retraso[i] == 2)
            {
                cliente[i] += 3;
            }
            else if (retraso[i] == 3)
            {
                cliente[i] += 6;
            } 
            prestamo[i]--;  
        }
    }
}
int main()
{
    //Pregunta la cantidad de clientes
    int n;
    printf("Cuantos clientes son?: ");
    scanf("%d", &n);
    while (n < 0)
    {
        printf("Error....Introduzca de nuevo cuantos clientes son: ");
        scanf("%d", &n);
    }
    //Definimos los arrays
    int* prestamo = (int*)malloc(n * sizeof(int));
    int* retraso = (int*)malloc(n * sizeof(int));
    int* cliente = (int*)malloc(n * sizeof(int));
    //Preguntamos cuanto prestamos se realizo
    for (int i = 0; i < n; i++)
    {
        printf("Cuantos prestamos realizo el cliente numero %d(El cliente puede hacer maximo 2 prestamos)?: ",(i + 1));
        scanf("%d", &prestamo[i]);
        while (0 > prestamo[i] || prestamo[i] > 2)
        {
            printf("Error....Introduzca de nuevo(No puede ser mas de dos o menor que uno): ");
            scanf("%d", &prestamo[i]);
        }
    }
    //Preguntamos los meses de retraso
    for (int i = 0; i < n; i++)
    {
        printf("Cuantos meses de retraso tubo el cliente numero %d?(Solo puede tener hasta 3 meses de retraso): ", (i + 1));
        scanf("%d", &retraso[i]);
        while (retraso[i] < 0 || retraso[i] > 3) 
        {
            printf("Error.... Introduzca de nuevo(Solo puede tener hasta 3 meses de retraso): ");
            scanf("%d", &retraso[i]);
        }
    }
    //La funcion
    calcularprestigio(n, prestamo, retraso, cliente);
    //Imprimir los datos
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (cliente[i] == a)
        {
            printf("Cliente numero %d", i);
        }
        a++;
    }
    //Liberar
    free(prestamo);
    free(retraso);
    free(cliente);
    return 0;
}