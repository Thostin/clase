#include <stdio.h>
#include <stdlib.h>
/*
    El Banco de la Capital requiere de un programa que pueda seleccionar a aquel cliente de
    mayor prestigio para otorgarle un bono exclusivo. El prestigio de un cliente se mide por su
    rapidez en los pagos. Si un cliente se retrasa un mes en un pago, es restado a su nivel de
    prestigio 1 punto, si se retrasa dos meses, se le resta 3 puntos (1 por el primer mes, 2
    por el segundo), si se atrasa tres meses, se le resta 6 puntos (1 por el primer mes, 2 por
    el segundo, 3 por el tercero). El cliente con un puntaje mas cercano a cero, es decir, menos
    puntajes retrasados, es el mas prestigioso.
    Permitir la carga de la cantidad (N) de clientes, la cantidad de prestamos realizados por
    cada uno y los meses de retraso que tuvo en cada pago.
    Imprimir en pantalla al cliente mas prestigioso junto a su nombre y seguido a el a los otros
    clientes de manera descendente en referencia a su cercania a cero.
*/
void ordenPrestigo(int vec[],int n,int cods[]){//funcion para crear orden de prestigio
    for (int i = 0; i < n -1; i++)
    {
        for (int j = 0; j < n - i -1; j++)
        {
            if (vec[j] < vec[j+1])
            {
                int aux = vec[j];//intercambiamos los valores de prestigio
                vec[j] = vec[j+1];
                vec[j+1] = aux;

                aux = cods[j];//intercambiamos los codigos de cliente segun prestigio
                cods[j] = cods[j+1];
                cods[j+1] = aux;
            }
        }
    }
}

int validarPositivo(int n){//subprograma para validar numeros positivos

    while (n < 0)
    {
        printf("Introduzca un dato valido!: ");
        scanf("%d",&n);
    }
    return n;
}

int validarMaxMin(int n, int max, int min){//subprograma para validar numeros utilizando parametros

    while (n > max || n < min)
    {
        printf("Introduzca un dato valido!: ");
        scanf("%d",&n);
    }

    return n;
}


int main(){

    int N;//introducimos y validamos la cantidad de clientes
    printf("Introduzca la cantidad de clientes: ");
    scanf("%d",&N);
    N = validarPositivo(N);

    int clientes[N];//inicializamos el vector clientes
    for (int x = 0; x < N; x++)
    {
        clientes[x] = 0;
    }
    
    int codClients[N];
    int prestamos;
    for (int x = 0; x < N; x++)//ciclo de clientes
    {
        codClients[x] = x+1;
        printf("Usted es el cliente %d: \n",codClients[x]);//asignamos un codigo de cliente al cliente

        printf("Cuantos prestamos tiene? (min = 1 - max = 2): ");//cargamos y validamos la cantidad de prestamos
        scanf("%d",&prestamos);
        prestamos = validarMaxMin(prestamos,2,1);
        
        int atraso;
        for (int i = 0; i < prestamos; i++)//cargamos y validamos los meses de atraso por prestamo
        {
            printf("Cuantos meses se atraso en el pago %d?: ",i+1);
            scanf("%d",&atraso);
            atraso = validarMaxMin(atraso,3,1);
            switch (atraso)//restamos prestigio segun el atraso
            {
            case 1:
                clientes[x] -= 1;
                break;
            
            case 2:
                clientes[x] -= 3;
                break;

            default:
                clientes[x] -= 6;
                break;
            }
        }
        
    }
    ordenPrestigo(clientes,N,codClients);
    printf("El orden de privilegio es: \n");
    for (int i = 0; i < N; i++)
    {
        printf("CLIENTE %d: %d\n",codClients[i],clientes[i]);
    }
    

    return 0;
}