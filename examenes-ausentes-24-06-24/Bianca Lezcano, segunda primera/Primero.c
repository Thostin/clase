//Ejercicio uno
#include <stdio.h>
#define TAMANIO 10 //No pueden haber más de diez tareas asignadas
#define CANTIDADALUMNOS 5
int Dato, i, j, Total[TAMANIO], TareasPuntaje [TAMANIO], Cedula [CANTIDADALUMNOS], AlumnosAprobados = 0, AlumnosDesaprobados = 0, ContadorGlobal = 0, Suma, SumaDos;
int Verificador (int Menor, int Limite);
int Lectura (int CantidadLectura);
int Igualdad (int ContadorIgualdad);
int main() {
	//Se toma que hay sólo cinco alumnos
	int Tareas;
	int Contador = 0, ContadorDos = 0;
	while (Contador<5) {
		printf ("Alumno %d\nMaestro, ingresa la cantidad de tareas asignadas\n", Contador+1);
		scanf ("%d", &Dato);
		Verificador (5, 10); //Señalizo que se puede asignar de cinco a diez tareas
		Tareas = Dato;
		printf ("Ingrese la cédula del alumno\n");
		scanf ("%d", &Dato);
		Verificador (5000000, 8000000); //Señalizo que se puede asignar solamente cédulas que van desde el cinco millones hasta el ocho millones
		Cedula[Contador] = Dato;
		Igualdad (Contador+1);
		Cedula[Contador] = Dato;
		while (ContadorDos<Tareas) {
			printf ("¿Cuál es el puntaje total de la tarea %d?\n", ContadorDos+1);
			scanf ("%d", &Dato);
			Verificador (5, 30); //Señalizo que la tarea no puede tener menos de cinco puntos o más de treinta puntos
			TareasPuntaje[ContadorDos] = Dato;
			printf ("¿Cuál a sido el puntaje del alumno %d en la tarea %d?\n", Contador+1, ContadorDos+1);
			scanf ("%d", &Dato);
			Verificador (0, TareasPuntaje[ContadorDos]); //Señalizo que el puntaje no puede ser menor a cero o mayor al total antes inicializado
			Total [ContadorDos] = Dato;
			ContadorDos++;
		}
		ContadorDos = 0;
		Lectura (Tareas);
		Contador++;
		if (Contador == 5) {
			printf ("En el recuento final hubo\n%d alumnos aprobados\n%d alumnos desaprobados", AlumnosAprobados, AlumnosDesaprobados);	
		}
	}
	return 0;
}
int Verificador (int Menor, int Limite) {
	while (Dato<Menor || Dato>Limite) {
		printf ("Ingrese el dato correctamente\n");
		scanf ("%d", &Dato);
	}
	return 0;
}
int Igualdad (int ContadorIgualdad) {
	int Iguales = 0;
	for (i=0;i<ContadorIgualdad;i++) {
		for (j=0;j<ContadorIgualdad;j++) {
			if (Cedula[i] == Cedula[j]) {
				Iguales++;
			}
		}
	}
	if (Iguales>1) {
		printf ("Error, ingrese correctamente la cédula\n");
		scanf ("%d", &Dato);
		Verificador (5000000, 8000000); 
		Cedula[ContadorIgualdad-1] = Dato;
	}
	return 0;
}
int Lectura (int CantidadLectura) {
	//Importante: 70% escrito en decimal es 0.7 
	ContadorGlobal++;
	int Contador = 0, Porcentaje, Bandera = 1, Faltantes;
	printf ("Los datos del alumno %d (con cédula %d) son los siguientes\nDe las tareas asignadas (%d)\n", ContadorGlobal, Cedula[ContadorGlobal-1], CantidadLectura);
	while (Contador<CantidadLectura) {
		//Importante: 70% escrito en decimal es 0.7
		Suma = SumaDos = 0;
		for (i=0;i<CantidadLectura;i++) {
			Suma = Suma + TareasPuntaje[i];
			SumaDos = SumaDos + Total[i];
		}
		Porcentaje = Suma * 0.7;
		if (SumaDos>=Porcentaje) {
			Bandera = 1;
		}
		if (SumaDos<Porcentaje) {
			Bandera = 0;
		}
		printf ("Tarea número %d (el total es %d)\nPuntos obtenidos: %d\n", Contador+1, TareasPuntaje[Contador], Total[Contador]);
		if (Total[Contador] == TareasPuntaje[Contador]) {
			printf ("Tuvo total de puntos\n");
		}
		else {
			printf ("Puntos perdidos: %d\n", TareasPuntaje[Contador]-Total[Contador]);
		}
		if (Bandera == 1) {
			printf ("Quiere decir que aprobo la prueba\n");
			if (Total[Contador] == TareasPuntaje[Contador]) {
				printf ("Con total de puntos en la prueba\n\n");
			}
			else {
				printf ("Faltandole %d puntos para el total en la prueba\n\n", TareasPuntaje[Contador] - Total[Contador]);
			}
		}
		else { 
			Faltantes = (TareasPuntaje[Contador]*0.7)-Total[Contador]; //Hay que utilizar variable para que el resultado se tome como un entero, en caso de poder ser de tipo flotante
			printf ("Quiere decir que desaprobo en la prueba\n");
			printf ("Faltandole %d puntos para aprobar\n\n", Faltantes+1); //Le sumo uno, por el hecho de que los valores están redondeados
		}
		Contador++;
	}
	//Divido todos los datos entre cinco porque quiero saber el puntaje de sólo un alumno
	printf ("En total\nPuntos obtenidos: %d \nPuntos perdidos: %d \nQuiere decir que\n", SumaDos, (Suma-SumaDos));
	if (SumaDos<Porcentaje) {
		printf ("DESAPROBO\nFaltandole %d puntos para pasar\n\n", (Porcentaje-SumaDos));
		AlumnosDesaprobados++;
	}
	else { 
		printf ("APROBO\n\n");
		AlumnosAprobados++;
	}
	return 0;
}
