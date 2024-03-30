#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_t list_t;
typedef struct list_t *listptr_t;

struct list_t {
  listptr_t next;
  void *data;
};

#ifndef err_t
typedef int err_t;
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif /* ifndef MACRO*/

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif /* ifndef EXIT_SUCCESS */

#ifndef nullptr
#define nullptr 0x0
#endif /* ifndef nullptr */

// Toma como parámetro una dirección de memoria de donde se
// guardará el puntero al inicio de la lista
err_t initl(listptr_t *root, const void *init_data, const size_t size) {
  *root = (listptr_t)malloc(sizeof(list_t));
  if (nullptr == root)
    goto err0;

  (*root)->data = malloc(size);
  if (nullptr == (*root)->data)
    goto err1;

  memcpy((*root)->data, init_data, size);

  return EXIT_SUCCESS;

err1:
  free(*root);
err0:
  return EXIT_FAILURE;
}

// El valor de retorno es para ver si hubo errores
// Aloja un puntero con el dato que se le especifica
// Overwrites, if written before, the *next pointer
// No revisa si el programador se equivoca al pasar los punteros
err_t pushl(listptr_t const where, const void *data, const size_t size) {

  if (nullptr == where || nullptr == data || 0 == size) {
    return EXIT_FAILURE;
  }

  listptr_t aux = (listptr_t)malloc(sizeof(list_t));

  if (nullptr == aux)
    goto err0;

  aux->data = malloc(size);
  if (nullptr == aux->data)
    goto err1;

  memcpy(aux->data, data, size);

  where->next = aux;
  return EXIT_SUCCESS;

err1:
  free(aux);
err0:
  return EXIT_FAILURE;
}

// Liberar una lista desde *node
// No hay manera de que falle, salvo que se le pase un
// nullptr como argumento.
// Repito: NO hay manera de que falle salvo esa.
// Toma como argumento un puntero a otro puntero para borrar el puntero original
err_t freel(listptr_t *node) {
  if (nullptr == node)
    return EXIT_FAILURE;

  listptr_t aux1 = *node;
  *node = nullptr; // Chau puntero

  listptr_t aux2;
  while (aux1) {
    aux2 = aux1->next;
    // C standard: "If ptr is a null pointer, no action occurs."
    free(aux1->data);
    free(aux1);
    aux1 = aux2;
  }

  return EXIT_SUCCESS;
}

// Searches for *ret in *data member from node
// Returns EXIT_SUCCESS if found element and EXIT_FAILURE if not,
// in case of EXIT_FAILURE, leaves *ret unchanged.
// Stores pointer where comparission whith target success in ret
// Also returns EXIT_FAILURE if *node or its *data are nullptr
// Note: Checks both *data and *next pointers for a nullptr, just to be safe
// Will not segfault unless a non-nullptr non-malloc/calloc/realloc-allocated
// pointer occurs
err_t findl(listptr_t node, const void *target, const size_t size,
            listptr_t *const ret) {

  while (node && node->data) {
    if (!memcmp(node->data, target, size)) {
      *ret = node;
      return EXIT_SUCCESS;
    }
    node = node->next;
  }

  return EXIT_FAILURE;
}

// Same as findl, but requires a comparision function
// Will not segfault unless a non-nullptr non-malloc/calloc/realloc-allocated
// pointer occurs
err_t ffindl(listptr_t node, const void *target, listptr_t *const ret,
             int (*cmp)(const void *, const void *)) {

  while (node && node->data) {
    if (!cmp(node->data, target)) {
      *ret = node;
      return EXIT_SUCCESS;
    }
    node = node->next;
  }

  return EXIT_FAILURE;
}

// Reads the list from *node and stores *data values
// to an unknown fixed size array
// dst should be allocated before calling compactl
err_t compactl(listptr_t node, void *dst, const size_t size) {
  while (node && node->data) {
    memcpy(dst, node->data, size);
    node = node->next;
    dst = (char *)dst + size;
  }
  return EXIT_SUCCESS;
}
