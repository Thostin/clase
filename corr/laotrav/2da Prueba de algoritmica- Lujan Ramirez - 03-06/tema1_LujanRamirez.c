/*Calcular puntos de prestigio de cada cliente*/
#include <stdio.h>
#include <stdlib.h>
int validar(int n,int caso)  //funcion para validar
{
	switch(caso)
	{
		case 1:
			while(n<=1)
			{
				printf("Error: ingrese un numero mayor y positivo");
				scanf("%d",&n);
			}
		case 2:
			while(n<1 || n>2)
			{
				printf("Error: Debe de tener un prestamo o dos");
				scanf("%d",&n);
			}
		case 3:
			while(n>3)
			{
				printf("Error: Se puede deber hasta 3 meses");
				scanf("%d",&n);
			}
	}
	return n;
}
void prestigio(int a[],int b[],int p[],int t)  //funcion para calcular los puntos
{
	int i;
	for(i=0;i<t;i++)
	{
		switch(a[i])   //segun la cantidad de prestamo
		{
			case 1:   //si tiene 1
				switch(b[i])  //segun el atraso de pago
				{
					case 1:   //si es un mes
						p[i] = 1;
						break;
					case 2:   //si es dos meses
						p[i] = 3;
						break;
					case 3:   //si es tres meses
						p[i] = 6;
						break;
					default:   //si no se atraso
						p[i] = 0;
				}
			case 2:  //si tiene 2 prestamos 
				switch(b[i])  //segun el atraso
				{
					case 1:   //si es un mes
						p[i] = 1*2;
						break;
					case 2:   //si es dos meses
						p[i] = 3*2;
						break;
					case 3:   //si es tre meses
						p[i] = 6*2;
						break;
					default:   //si no tiene atraso
						p[i] = 0;
				}	
		}
	}
}
void ordenD(int a[],int t)  //ordenar de forma descendente
{
	int i,j,aux;
	for(i=0;i<t;i++)
	{
		for(j=i+1;j<=t-1;j++)
		{
			if (a[i] < a[j])
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
	int clientes,i;
	printf("\nIngrese la cantidad de clientes: ");
	scanf("%d",&clientes);
	validar(clientes,1);  //uso de funcion de validar
	//creamos vectores
	int prestamo[clientes];
	int pago[clientes];
	int pts[clientes];
	for(i=0;i<clientes;i++)
	{
		printf("\nIngrese la cantidad de prestamos del cliente %d: ",i+1);
		scanf("%d",&prestamo[i]);
		prestamo[i] = validar(prestamo[i],2);   //validacion
		printf("\nIngrese sus meses de atraso (hasta 3): ");
		scanf("%d",&pago[i]);
		pago[i] = validar(pago[i],3);  //validacion
		pts[i] = 0;
	}
	prestigio(prestamo,pago,pts,clientes);
	ordenD(pts,clientes);
	printf("\nEl cliente mas prestigioso tiene: %d",pts[clientes-1]);
	printf("\nResto de clientes en orden descendiente:");
	for(i=0;i<clientes-1;i++)
	{
		printf("\n%d",pts[i]);  //se muestran los puntos de los demas clientes
	}
	return 0;
}
