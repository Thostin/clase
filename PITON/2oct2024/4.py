def suma_columnas(mat):
    ret = []
    for i in range(0, 4):
        par = 0
        for j in range(0, 4):
            par += mat[j][i]
        ret.append(par)
    return ret


print("Ingrese los elementos de la matriz 4 * 4:")

mat = []
for i in range(0, 4):
    aux = []
    for j in range(0, 4):
        lopta = int(input(f"""[{i}][{j}]: """))
        aux.append(lopta)
    mat.append(aux)

print("Suma de cada columna:", suma_columnas(mat))
