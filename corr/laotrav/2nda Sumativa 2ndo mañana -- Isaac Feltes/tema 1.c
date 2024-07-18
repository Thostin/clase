#include <stdio.h>
#include <stdlib.h>

#define client_max 100

int comparar_int(const void *a, const void *b){
    int Aint = *(int *)a;
    int Bint = *(int *)b;

    return (Aint - Bint);
}

int mayor_prestigio(int *x, int *z,int l){
    for (size_t i = 0; i < l; i++) //Inicio el arreglo que define el numero con los prestigiosos
    {
        z[i] = 0;
    }
    


    int cont_presti;
    cont_presti = 0;
    for (size_t i = 0; i < l; i++)
    {
        if (x[i] == 0)
        {
            cont_presti++;
            z[i] = i;
        }
        
    }
    return cont_presti;
}

int main(void){
    int N;
    int cant_pres;
    int cant_at;


    printf("ingrese la cantidad de clientes \n");
    while (1)
    {
        scanf("%d", &N);
        if (N > 0 && N <= client_max)
        {
            break;
        }
        else {
            printf("Error, valor no válido \n");
        }
        
    }
    
    int Atrasos[N]; //Defino los arreglos
    int prestigio[N];
    int num_clientes[N];
    int num_prestigio[N];

    for (size_t i = 0; i < N; i++) //Inicio los identificadores de clientes, Me va a servir para identificar el/los que tienen mayor prestigio (cero)
    {
        num_clientes[i] = i+1;
    }
    


    for (size_t i = 0; i < N; i++)
    {

        printf("Ingrese la cantidad de prestamos para el cliente %d \n", i); //Pido la cantidad de clientes hasta que sea un numero valido
            while (1)
            {
                scanf("%d", &cant_pres);
                if (cant_pres > 0 && cant_pres < 3)
                {
                    break;
                }
                else {
                    printf("Error solo puede tener hasta dos prestamos pendientes, vuelva a introducir \n");
                }
            }


            for (size_t g = 0; g < cant_pres; g++) //Pido la cantidad de prestamos y el atraso en meses para cada uno
            {
                printf("Ingrese los meses atrasados en el prestamo %d \n", g);
                while (1)
                {
                   scanf("%d", &Atrasos[i]);
                   if (Atrasos[i] >= 0 && Atrasos[i] < 4)
                   {
                        if (Atrasos[i] == 3)
                        {
                            prestigio[i] -= 6;
                            break;
                        }
                        else if (Atrasos[i] == 2)
                        {
                            prestigio[i] -= 3;
                            break;
                        }
                        else if (Atrasos[i] == 1)
                        {
                            prestigio[i] -= 1;
                        }
                        break;
                   }
                    else {
                        printf("Solo puede tener hasta tres meses atrasados. Aguarde su denuncia ;) (Jodita, vuelva a introduir un numero valido)\n"); //Validacion si introduce mas de tres meses
                    }
                }
            }
    }
    int prestigiosos = mayor_prestigio(prestigio, num_prestigio, N);
    printf("Los clientes más prestigiosos son los números: \n"); //Mencionar los cleintes con mayor prestigio
    for (size_t i = 0; i < N; i++)
    {
        if (num_prestigio[i] == 0)
        {
            continue;
        }
        printf("%d \n\n", num_prestigio[i]+1);   
    }
    
    qsort(prestigio, N, sizeof(int), comparar_int);

    printf("Así queda la lista ordenada de los clientes y su prestigio \n\n"); //Listar los clientes en base al prestigio
    for (size_t i = 0; i < N; i++)
    {
        printf("%d ---->", prestigio[i]);
        printf("%d \n", num_clientes[i]);
    }
    
    return 0;
}