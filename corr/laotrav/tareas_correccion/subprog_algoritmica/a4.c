/*Los alumnos dew una materia se dviden en dos secciones llamadas seccion uno y
 * seccion ds. cada seccion tiene su propia lista de alumnos en la cual figuran
 * sus numeros de matricula. escribir un algoritmo que reciba la cantidad de
 * alumnos y los numeros de matricula en cada seccion, forme dos arreglos con
 * los datos de cada seccion y luego combine ambas listas en una sola, ordenada
 * por numeor de matricula*/

#include <stdio.h>
/*se define una funcion para cargar datos, combinar listas y ordenarlos con
 * cuatro parametros mecnionados a continuacion*/
void cargardatos(int long1, int long2, int sec1[], int sec2[]) {
  int longitudotal =
      long1 + long2;   /*se calcula la longitud total que tendra el vector*/
  int c[longitudotal]; /*se define un vector 'c' con la longitud antes
                          mencionada*/
  for (int i = 0; i < long1; i++) /*se cargan los elementos de la seccion uno en
                                     c, con limite de alumnos de tal seccion*/
  {
    c[i] = sec1[i];
  }
  for (int i = 0; i < long2; i++) /*se cargan los datos de la segunda seccion en
                                     c, con limite de longitud de tal seccion*/
  {
    c[long1 + i] = sec2[i];
  }
  /*ordena el arreglo combinado*/
  for (int i = 0; i < longitudotal - 1; i++) {
    for (int j = 0; j < longitudotal - i - 1; j++) {
      if (c[j] > c[j + 1]) {
        int aux = c[j];
        c[j] = c[j + 1];
        c[j + 1] = aux;
      }
    }
  }
  for (int i = 0; i < longitudotal;
       i++) /*basicamente se imprime el nuevo vector ya ordenado*/
  {
    printf("Matricula nro %d: %d\n", i + 1, c[i]);
  }
}

int main() {
  int long1, long2;
  /*--------------------------------------------*/
  printf("Introduce la cantidad de alumnos de la primera seccion: ");
  scanf("%d", &long1);
  /*--------------------------------------------*/
  int sec1[long1]; /*se define la longitud de la seccion uno con la cantidad de
                      alumnos que la conforman*/
  /*--------------------------------------------*/
  for (int i = 0; i < long1; i++) /*se cargan los datos*/
  {
    printf("Introduzca el numero de matricula de cada alumno: alumno nro %d: ",
           i + 1);
    scanf("%d", &sec1[i]);
  }
  /*--------------------------------------------*/
  printf(
      "Introduzca la cantidad de alumnos que conforman la segunda seccion: ");
  scanf("%d", &long2);
  /*--------------------------------------------*/
  int sec2[long2]; /*se define la longitud o 'cantidad de alumnos que conforman
                      la segunda seccion' del vector o 'la segunda secc'*/
  /*--------------------------------------------*/
  for (int i = 0; i < long2; i++) /*se cargan los datos otv*/
  {
    printf("Introduzca el numero de matricula de cada alumno: alumno nro %d: ",
           i + 1);
    scanf("%d", &sec2[i]);
  }
  /*--------------------------------------------*/
  cargardatos(
      long1, long2, sec1,
      sec2); /*se invoca al procedimiento de combinar y ordenar las listass*/
  return 0;
}
