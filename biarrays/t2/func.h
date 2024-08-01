#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef MAXLINE
#define MAXLINE 100
#endif /* ifndef MAXLINE */

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

typedef int type;
#define TYPE_FORMAT "d"

#define nullptr NULL

/* Números enteros no negativos entre 0 y 19 */
void rellenar(type *matriz, int f, int c);
void _rellenar(type *matriz, int f_c);

/*
 * f_a: cantidad de filas
 * c_a: cantidad de columnas
 * */
int *multiplicar_matrices(int *mat_a, int *mat_b, int f_a, int c_a, int f_b,
                          int c_b);

void mostrar_matriz_almacen(int *mat, int f, int c);
void leer_dimension(int *n);
int minimax(int *mat, int f, int c);
int suma_fila(int *mat, int c, int n_f);

/* f: cantidad de filas
 * c: camtidad de columnas
 * */
void mostrar_matriz(int *mat, int f, int c);
