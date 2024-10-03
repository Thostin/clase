# Propiedades de listas.
#
# Son mutables, dinámicas, ordenadas, anidables,
# arbotrarias, indexables
#
# Esperemos que el profesor no ponga un P3 de olimpiada internacional
#


def invertir(arr, desde, hasta):
    index_desde = desde
    index_hasta = hasta

    while index_desde < index_hasta:
        aux = arr[index_desde]
        arr[index_desde] = arr[index_hasta]
        arr[index_hasta] = aux
        index_hasta -= 1
        index_desde += 1


def min_pos(arr, desde):
    pos_min = desde
    for i in range(desde, len(arr)):
        if arr[i] < arr[pos_min]:
            pos_min = i
    return pos_min


def verificar_si_no_hay_repeticiones(val, arr):
    for i in arr:
        if val == i:
            return 1
    return 0


def robosort(arr):
    cambios = []

    for i in range(0, len(arr)):
        aux_min_pos = min_pos(arr, i)
        # print("Return of min_pos: ", aux_min_pos)
        cambios.append(1 + aux_min_pos)
        invertir(arr, i, aux_min_pos)
    return cambios


kopta = input()
arr_list = kopta.split(" ")

n = int(arr_list[0])
if n <= 0 or n > 1000:
    print("Cantidad inválida de valores")
    quit()

arr = []

for i in range(0, n):
    k = int(arr_list[i + 1])
    if k <= 0 or k >= 1000001:
        print("k no se encuentra en el rango (0, 1000001)")
        quit()

        # if verificar_si_no_hay_repeticiones(k, arr) == 1:
    if k in arr:
        print("No se pueden repetir muestras")
        quit()
    arr.append(k)

# print("Para el arreglo: ")
# for i in arr:
# print(i, end="")
# print("")
# print("El orden de acciones que se precisa es: ")

f = robosort(arr)
# print("len(f): ", len(f))
print(f"""{n}  """, end="")
for i in f:
    print(i, "", end="")
print("")
