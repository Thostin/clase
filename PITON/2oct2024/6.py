def suma_filas(n, mat):
    ret = []
    for i in range(0, n):
        ret.append(sum(mat[i]))

    return ret


def suma_columnas(n, mat):
    ret = []
    for i in range(0, 3):
        par = 0
        for j in range(0, n):
            par += mat[j][i]
        ret.append(par)
    return ret


print(
    "Cada fila tiene tres elementos que son, respectivamente, la cantidad de lavadoras, secadoras y cocinas vendidas en esa semana; cada fila representa una semana. Así la fila i representa a la semana i + 1\n"
)

sem = int(input("Ingrese la cantidad de semanas de operación: "))
mat = []

for i in range(0, sem):
    aux = []
    for j in range(0, 3):
        k = int(input(f"""[{i}][{j}]: """))
        if k < 0 or k > 1000:
            print("Cantidad inválida de ventas")
            quit()
        aux.append(k)
    mat.append(aux)

print("Cantidad de productos vendidos cada semana:", suma_filas(sem, mat))
print(
    "Cantidad de cada producto vendido a lo larfo de todas las semanas:",
    suma_columnas(sem, mat),
)
