#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
    Escribir un algoritmo que simule 100 lanzamientos de tres dados. Generar procedimientos que
    permitan realizar lo siguiente:
    a) Cual es el numero que mas veces se presenta como suma total de los tres dados?
    b) En cuantas tiradas los 3 dados dieron el mismo numero?
    c) En cuantas tiradas los numeros formaron una escalera? (1,2,3 o 2,3,4 etc.)
*/
int comparar(const void *p, const void *q){//funcion de comparacion para qsort

    int a = *(int *)p;
    int b = *(int *)q;
    return (a-b);

}

int esEscalera(int vec[]){//funcion para verificar si los tres dados dieron una escalera

    if (vec[0] < vec[1] && vec[1] < vec[2])
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}

int igualdad(int vec[]){//funcion para verificar la igualdad entre los dados
    
    if (vec[0] == vec[1] && vec[1] == vec[2])
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void sumaDados(int vec[], int nros[])//funcion para calcular cuantas veces sale un numero
{
    int suma = vec[0] + vec[1] + vec[2];
    for (int i = 3; i <= 18; i++)
    {
        if (suma == i)
        {
            nros[i - 3]++;
        }
        
    }
    
}

int detMasVeces(int vec[])//funcion para determinar cual numero salio mas veces
{
    int max = 0;
    int num;
    for (int i = 0; i <= 15; i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
            num = i;
        }
        
    }
    return num + 3;
}

int main(){

    srand(time(NULL));//inicializamos semilla y variables
    int dado[3];
    int masSum;
    int numSuma[16];
    for (int i = 0; i < 16; i++)
    {
        numSuma[i] = 0;
    }
    int iguales = 0;
    int escalera = 0;
    for (int x = 0; x < 100; x++)//ciclo de lanzamientos
    {
        for (int i = 0; i < 3; i++)//se "tiran" los dados
        {
            dado[i] = rand()%6 + 1;
        }
        qsort(dado,sizeof(dado)/sizeof(dado[0]),sizeof(int),comparar);//funcion para ordenar elementos de arreglo (dados)
        if (esEscalera(dado) == 1)//verificamos si es escalera utilizando la funcion
        {
            escalera++;
        }
        if(igualdad(dado) == 1)//verificamos si los 3 dados son iguales utilizando la funcion
        {
            iguales++;
        }
        sumaDados(dado,numSuma);//sumamos los dados y se suma la cantidad de veces que salio X numero
        masSum = detMasVeces(numSuma);//determinamos cual salio mas veces
    }
    
    printf("El numero que mas veces salio como suma de los dados es %d \n",masSum);//imprimimos resultados
    printf("Los dados salieron todos iguales %d veces\n",iguales);
    printf("Los dados formaron una escalera %d veces\n",escalera);
    

    return 0;
}