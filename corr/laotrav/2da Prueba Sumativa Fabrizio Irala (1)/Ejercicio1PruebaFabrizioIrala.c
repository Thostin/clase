#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {   /*Le pedimos al usuario el numero de clientes*/
    int N;
    printf("Introduce el numero de clientes \n");
    scanf("%d", &N);
    int Referencia = 0;
    Validacion(N, Referencia); /*Llamamos a la funcion para validarlo*/
    CalculoPuntosPerdidos(N);
    return 0;
}

void Validacion(int N, int Referencia) {
        while (N <= 0) {
            printf("No puede ser ni igual ni menor a 0 \n");
            scanf("%d", &N); /*La funcion tiene como fin validar el numero de clientes*/
        }
}

void ValidacionMeses(int Referencia, int Referencia2) {  /*Funcion de validacion para los prestamos*/
        while (Referencia2 > Referencia || Referencia2 <= 0) {
            printf("No puede ser ni mayor a %d ni menor/igual a 0. Si introdujiste 3, prueba de nuevo: ", Referencia);
            scanf("%d", &Referencia2);
            if (Referencia2 == 3) {
                break;
            }
        }
}


void CalculoPuntosPerdidos(int N) {
    int V[N];
    int P[N];
    int A[N];
    int Cliente = 0;
    int Puntos = 0;
    int Puntos[N];
    int Referencia, Referencia2;
    for (int i = 0; i < N; i++) { /*Realizamos el ciclo para calcular lo correspondiente de cada cliente*/
        Cliente++;
        Puntos = 0;
        printf("Introduce la cantidad de prestamos de este cliente: \n"); /*Pedimos la cantidad de prestamos del cliente*/
        scanf("%d", &P[i]);
        Referencia = 2;
        Referencia2 = P[i];
        int Atrasos = P[i];
        ValidacionMeses(Referencia, Referencia2); /*Validamos la cantidad de prestamos*/
        P[i] = Referencia2;
        for (int j = 0; j < Atrasos; j++) {
            printf("Introduce los meses de atraso por este pago: \n"); /*Solicitamos la cantidad de meses para poder validarla*/
            scanf("%d", &A[j]);

            while (A[j] > 3 || A[j] <= 0) {
                printf("Minimo 1 mes, maximo 3: \n"); /*Validamos la cantidad de meses de retraso*/
                scanf("%d", &A[j]);
            }
            

            if (A[j] == 1) { /*Calculamos la cantidad de puntos perdidos por cliente*/
                Puntos = Puntos - 1;
            }
            if (A[j] == 2) {
                Puntos = Puntos - 3;
            }
            if (A[j] == 3) {
                Puntos = Puntos - 6;
            }
        }
        printf("El cliente %d perdio %d puntos \n", Cliente, -(Puntos)); /*Imprimimos la cantidad de puntos perdidos por cliente.*/
    }

}