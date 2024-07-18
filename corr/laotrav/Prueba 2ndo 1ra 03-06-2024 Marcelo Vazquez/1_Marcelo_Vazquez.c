#include <stdio.h>
//Validacion para los datos correspondientes
int validacion(int numero_a_verificar, int valor_mayor, int valor_menor){
	while (numero_a_verificar < valor_menor || numero_a_verificar > valor_mayor){
		printf("El numero no puede ser menor a %d ni mayor a %d\n", valor_menor, valor_mayor);
		printf("Introduzca de nuevo el dato\n");
		scanf("%d",&numero_a_verificar);
	}
	return numero_a_verificar;
}
//Funcion main
int main() {
	int i, cantidad_clientes;
	//Se lee la cantidad de clientes
	printf("Introduzca la cantidad de clientes\n");
	scanf("%d",&cantidad_clientes);
	
	//Inicializo los arrays
	int prestamos[cantidad_clientes	];
	int meses_de_atraso[cantidad_clientes];
	int prestigio[cantidad_clientes];
	
	//Se calcula
	for(i=0; i<cantidad_clientes; i++){
		printf("Introduzca la cantidad de prestamos del cliente %d\n", i+1);
		scanf("%d",&prestamos[i]);
		validacion(prestamos[i], 2, 1);
		printf("Introduzca la cantidad de meses de atraso del cliente %d\n", i+1);
		scanf("%d",&meses_de_atraso[i]);
		validacion(meses_de_atraso[i], 3, 1);
		if(meses_de_atraso[i] == 1){
			prestigio[i] = -1;
		}
		if(meses_de_atraso[i] == 2){
			prestigio[i] = -3;
		}
		if(meses_de_atraso[i] == 3){
			prestigio[i] = -6;
		}
		if(prestamos[i] == 2){
			prestigio[i] = prestigio[i] * 2;
		}
		printf("El prestigio del cliente %d es %d\n", i+1, prestigio[i]);
	}
	
	return 0;
}
