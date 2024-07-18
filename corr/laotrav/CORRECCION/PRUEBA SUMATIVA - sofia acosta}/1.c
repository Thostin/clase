
#include <stdio.h>
#include <stdlib.h>

void orden(int vector[], int cant, int nro_cl[]) {
  for (int i = 0; i < cant; i++) {
    for (int j = i + 1; j < cant; j++) {
      if (vector[i] > vector[j]) {
        int aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
        int aux2 = nro_cl[i];
        nro_cl[i] = nro_cl[j];
        nro_cl[j] = aux2;
      }
    }
  }
}

int validar(int validador_max, int variable, int validador_min) {
  while (variable > validador_max || variable <= validador_min) {
    printf("\n Error...debe introducirse un numero mayor a %d o menor o igual "
           "a %d : ",
           validador_min, validador_max);
    scanf("%d", &variable);
  }
  return variable;
}

int puntos(int meses_retraso) {
  if (meses_retraso == 1) {
    return 1;
  } else if (meses_retraso == 2) {
    return 3;
  } else if (meses_retraso == 3) {
    return 6;
  } else if (meses_retraso == 0) {
    return 0;
  }

  return -1;
}

int validar_clientes(int n_clientes[], int posicion, int cant_clientes) {
  if (n_clientes[posicion] <= 0 || n_clientes[posicion] > cant_clientes) {
    return 1;
  }

  if (posicion != 0) {
    for (int k = 0; k < posicion; k++) {
      if (n_clientes[k] == n_clientes[posicion]) {
        return 2;
      }
    }
  }

  return 0;
}

int main(void) {
  int n_cli;
  printf("Introduzca la cantidad de clientes : ");
  scanf("%d", &n_cli);

  while (n_cli <= 0) {
    printf("\n error..Introduzca un numero mayor a cero : ");
    scanf("%d", &n_cli);
  }

  int clientes[n_cli],
      nro_cliente[n_cli]; // almacena la cantidad de puntos de cada cliente

  for (int i = 0; i < n_cli; i++) {
    clientes[i] = 0; // n contadores, 1 para cada cliente
  }

  int cant_presta, val = 0; // val es para validar el nro de cliente
  int retraso;              // cantidad de meses de retraso
  for (int i = 0; i < n_cli; i++) {
    printf("\n Introduzca el numero del cliente: ");
    scanf("%d", &nro_cliente[i]);
    val = validar_clientes(nro_cliente, i, n_cli);

    while (val == 2 || val == 1) {
      if (val == 2) {
        printf("\n Error...ese cliente ya fue registrado anteriormente, "
               "introduzca nuevamente : ");
        scanf("%d", &nro_cliente[i]);
      } else if (val == 1) {
        printf("\n El numero de cliente no puede ser menor ni igual a cero ni "
               "mayor que %d, introduzca nuevamente : ",
               n_cli);
        scanf("%d", &nro_cliente[i]);
      }
      val = validar_clientes(nro_cliente, i, n_cli);
    }

    printf("\n Introduzca la cantidad de prestamos que realizara : ");
    scanf("%d", &cant_presta); // cantidad de prestamos
    cant_presta = validar(2, cant_presta, 0);
    for (int a = 0; a < cant_presta; a++) {
      printf(
          "\n introduzca la cantidad de meses atrazados en el prestamo %d : ",
          a + 1);
      scanf("%d", &retraso); // cantidad de meses de retraso
      retraso = validar(3, retraso, -1);
      clientes[i] += puntos(retraso);
    }
  }

  orden(clientes, n_cli, nro_cliente);
  printf("\n\nORDEN DESCENDENTE DE PRESTIGIOSIDAD !! \n");
  printf("\n el cliente mas prestigioso es el cliente nro %d con tan %d puntos "
         "menos.  ",
         nro_cliente[0], clientes[0]);
  for (int j = 1; j < n_cli; j++) {
    printf("\n Cliente nro %d con %d puntos menos. ", nro_cliente[j],
           clientes[j]);
  }
  return 0;
}
