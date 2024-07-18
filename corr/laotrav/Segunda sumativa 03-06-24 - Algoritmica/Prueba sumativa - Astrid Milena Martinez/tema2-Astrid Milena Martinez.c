#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Simular 100 lanzamientos de dados*/
/*
int concatenar_vectores(int a[], int b[], int c[]){
    int N = 300;
    int V[N];
    for (int i = 0; i < 100; i++)
    {
        V[i] = a[i];
    }
    for (int i = 0; i < 100; i++)
    {
        V[100 + i] = b[i];
    }
    for (int i = 0; i < 100; i++)
    {
        V[200 + i] = c[i];
    }
    return V;
}
*/
int suma_de_los_tres_dados(int a[], int b[], int c[]){
    int sum[100];
    for (int i = 0; i < 100; i++)
    {
        sum[i] = a[i] + b[i] + c[i];
    }  
    return sum;
}
int contar_escalera(int a[], int b[], int c[]){
    int escalera = 0;
    for (int i = 0; i < 100; i++)
    {
        if ((a[i] == 1 && b[i] == 2 && c[i] == 3) || (a[i] == 2 && b[i] == 3 && c[i] == 4) || (a[i] == 3 && b[i] == 4 && c[i] == 5) || (a[i] == 4 && b[i] == 5 && c[i] == 6))
        {
            escalera += 1;
        }
    }
     return escalera;
}
int cmpfnc(const void * a, const void * b){                 //para el qsort
    return (*(int*)a- *(int*)b);
}
int que_numero_se_presenta_mas(int arr[]){
    qsort(arr, 100, sizeof(int), cmpfnc);
    int cant_de_veces[6];
    int x = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (arr[j] == arr[i])
            {
                x++;
            }
        }
        cant_de_veces[i] = x;
    }
    int mayor = cant_de_veces[0];
    int numero = 0;
    for (int i = 0; i < 6; i++)
    {
        if (cant_de_veces[i] > mayor){
            mayor = cant_de_veces[i];
            numero = i;
        }
    }
    return numero;
}
int contar_cuantas_veces_sale_el_mismo_numero(int a[], int b[], int c[]){
    int mismo = 0;
    for (int i = 0; i < 100; i++)
    {
        if ((a[i] == b [i]) && (a[i] == c[i]))
        {
            mismo++;
        }
    }
    return mismo;
}
int main(){
    srand(time(NULL));
    int resultado_dado1[100], resultado_dado2[100], resultado_dado3[100];
    for (int i = 0; i < 100; i++)
    {
        resultado_dado1[i] = rand() % 6 + 1;     //generar aleatorios
        resultado_dado2[i] = rand() % 6 + 1;
        resultado_dado3[i] = rand() % 6 + 1;
    }
    //printf("El numero que se presenta mas veces como suma total de los tres dados es de: %d\n", que_numero_se_presenta_mas(suma_de_los_tres_dados(resultado_dado1, resultado_dado2, resultado_dado3)));
    printf("La cantidad de veces que los numeros formaron una escalera es: %d\n", contar_escalera(resultado_dado1, resultado_dado2, resultado_dado3));
    printf("Los dados dieron el mismo numero %d vez/veces", contar_cuantas_veces_sale_el_mismo_numero(resultado_dado1, resultado_dado2, resultado_dado3));
    return 0;
}