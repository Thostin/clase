#include <stdio.h>
#include <stdlib.h>
/*El banco exclusivo de la capital requiere de un programa que pueda seleccionar a aquel cliente de mayor prestigio para otorgarle un bono
exclusivo. El prestigio de un cliente se mide por su rapidez en los pagos. Si un cliente se retrasa un mes en un pago, es restado a su nivel 
de prestigio un punto, si se retrasa por dos meses, se le resta 3 puntos (1 por el primer mes, 2 por el segundo)*. El cliente con un puntaje
cercano al 0, es decir menos puntajes restados, es el mas prestigioso*/
void validacion_de_clientes(int N){
        while (N < 0 || N > 100)    //Validacion de clientes
        {
            printf("Error...Introduzca otro numero: ");
            scanf("%d", &N);
        }
}
void validacion_de_prestamos(int N){
    while (N < 0 || N > 2)
        {
            printf("Error...Introduzca otro numero: ");
            scanf("%d", &N);
        }
}
void validacion_de_meses(int N){
    while (N < 0 || N > 3)
        {
            printf("Error...Introduzca otro numero: ");
            scanf("%d", &N);
        }
}
int encontrar_el_menor(int arr[],int size){             //encontarr el numero de cliente con la menor de cantidad de atraso
    int menor = arr[0];
    int cliente;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < menor){
            menor = arr[i];
            cliente = i;
        }
    }
    return cliente;
}
int cmpfnc(const void * a, const void * b){                 //para el qsort
    return (*(int*)a- *(int*)b);
}
int main(){
    int N_clientes, meses_de_atraso = 0, puntos = 0;
    printf("Introduzca la cantidad total de clientes: ");  //registrar la cantidad de clientes
    scanf("%d", &N_clientes);
    validacion_de_clientes(N_clientes); 
    int prestamos[N_clientes];                       //Vector para la cantidad de prestamos
    int puntos_de_atraso[N_clientes];                //Vector para los puntos de atraso()
    for (int i = 0; i < N_clientes; i++)
    {
        printf("Introduzca la cantidad de prestamos del cliente N %d: ", i+1);
        scanf("%d", &prestamos[i]);
        validacion_de_prestamos(prestamos[i]);
        printf("Introduzca la cantidad de meses de atraso del cliente N %d: ", i+1);
        scanf("%d", &meses_de_atraso);
        validacion_de_meses(meses_de_atraso);
        for (int k = 1; k <= meses_de_atraso; k++)
        {
            puntos += k;
        }
        puntos_de_atraso[i] = puntos*prestamos[i]; //calcular la cantidad de puntos asumiendo que tiene el mismo retraso en todos los prestamos
    }
    printf("El cliente mas prestigioso o con menor cantidad de puntos es el N: %d\n", encontrar_el_menor(puntos_de_atraso, N_clientes)+1);
    printf("Los puntos de atraso de los demas clientes de menor a mayor:\n");
    qsort(puntos_de_atraso, N_clientes, sizeof(int), cmpfnc);
    for (int i = 0; i < N_clientes; i++)
    {
        printf("%d\n", puntos_de_atraso[i]);
    }
    return 0;
}