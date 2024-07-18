/*Simular 100 lanzamientos de 3 dados*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sumadados(int a[],int b[], int c[],int v[])  //funcion para lo de la suma
{
	int suma,i;
	for(i=0;i<19;i++)
	{
		suma = a[i]+b[i]+c[i];
		v[suma] += 1;
	}
}
int iguales(int a[],int b[],int c[])   //funcion para saber cuantas veces fueron iguales
{
	int i,tiradaI;
	tiradaI = 0;
	for(i=0;i<100;i++)
	{
		if (a[i] == b[i] && b[i] == c[i])
		{
			tiradaI += 1;  //contador
		}
	}
	return tiradaI;
}
int escalera(int a[],int b[],int c[])   //funcion para saber si sale escalera
{
	int i,j,aux,cantE;
	cantE = 0;
	for(i=0;i<100;i++)
	{
		if(a[i]<b[i] && b[i]<c[i])
		{
			cantE += 1;
		}
	}
	return cantE;
}
void ordenar(int a[])
{
	int i,j,aux;
	for(i=0;i<19;i++)
	{
		for(j=i+1;j<=18;j++)
		{
			if (a[i] > a[j])
			{
				aux = a[i];
				a[j] = a[i];
				a[i] = aux;
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	int i;
	//vectores para los dados con la longitud de las 100 tiradas
	int dado1[100];
	int dado2[100];
	int dado3[100];
	//cargamos los vectores con numeros aleatorios
	for (i=0;i<100;i++)
	{
		dado1[i] = 1+rand()%6;   
		dado2[i] = 1+rand()%6;
		dado3[i] = 1+rand()%6;
	}
	int vecsuma[19];
	for(i=0;i<19;i++)
	{
		vecsuma[i] = 0;
	}
	sumadados(dado1,dado2,dado3,vecsuma); //uso de la funcion
	ordenar(vecsuma);  //se ordena
	printf("\nEl numero que mas veces se presenta en la suma es: %d",vecsuma[18]);
	printf("\nLa cantidad de veces que salieron igual fue: %d",iguales(dado1,dado2,dado3));
	printf("\nLa cantidad de veces que salieron escalera fue: %d",escalera(dado1,dado2,dado3));
	return 0;
}
