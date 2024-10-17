#include <stdint.h>
// #include <stdio.h>
#include <stdlib.h>

/*
struct Date;
struct Hora;
struct ISBN;
struct Len_string;
struct Libro_biblioteca;
struct Producto_super;
struct Auto;

struct Paciente;
struct EmpleadoAsistencia;
struct Disco_musica;
*/

typedef struct Libro_biblioteca Libro_biblioteca;
typedef struct ISBN ISBN;
typedef int Libro_genero_ID;

// Existen 195 países, que es menor a 255
typedef uint8_t Country;

typedef int Money;
typedef int SupermercadoProducto_ID;

typedef int MarcaVehiculo_ID;

typedef uint32_t Paciente_ID;
typedef uint32_t CI;

typedef unsigned Genero_ID;

// Los dias, el mes y el año empiezan en cero
struct Date {
  uint8_t dia : 5;
  uint8_t mes : 4;
  int16_t anio : 15;
};

struct Hora {
  // de 00 a 23
  uint8_t hora : 5;
  uint8_t minuto : 6;
};

struct ISBN {
  uint8_t prefijo : 1; // 978 y posteriormente 979
  uint16_t id_pais;
  uint16_t editor; // Logitud variable según la agencia
  uint16_t correlativo_titulo;

  /* Regla para la verificacion:
   * verificacion: x
   *
   * se hace 1 * d[0] + 3*d[1] + ... + 3/1 * d[n]
   * congruente a -x módulo 10
   *
   * x es el último dígito del ISBN
   * */
  uint8_t verificacion : 4;
};

// Para guardar una cadena arbitraria de longitud máxima 255
struct Len_string {
  uint8_t len;
  char *data;
} __attribute__((packed));

/* A la hora de guardar, no es suficiente con
 * simplemente escribir la estructura, hay que guardar los nombre a parte*/
struct Libro_biblioteca {
  struct Len_string autor;
  struct Len_string titulo;

  struct Date lanzamiento;
  Country pais;

  ISBN isbn;
  Libro_genero_ID genero_id;

  Libro_biblioteca *next;
};

struct Producto_super {
  SupermercadoProducto_ID cod;
  Money precio;
};

struct Auto {
  size_t size_reg;
  MarcaVehiculo_ID marca_id;
  struct Len_string modelo;
  Money precio;

  // Automotores seguido de un apellido arbitrario
  struct Len_string concesionario;
};

struct Paciente {
  size_t size_reg;
  Paciente_ID id;
  CI cedula;

  struct Len_string direccion;
  struct Len_string numero_telefono;
};

struct EmpleadoAsistencia {
  struct Date fecha;

  // 0 para no, 1 para sí, 2 para llegada tardía
  /* El objetivo del  bit extra de la llegada tardía
   * es para no recalcular a cada rato si un empleado
   * llegó tarde
   * */
  uint8_t asistencia : 2;
  struct Hora entrada, tiempo_trabajo;
};

struct Disco_musica {
  size_t size_reg;
  Genero_ID genero;
  struct Len_string artista;
  struct Len_string discografica;

  struct Len_string nombre_disco;

  struct Hora duracion;
  struct Date lanzamiento;
};
