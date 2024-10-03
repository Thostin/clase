def medias_examenes_convocatorias(n, mat):
    ret = []
    par_sum = 0
    for i in range(0, 6):
        for j in range(0, n):
            par_sum += mat[j][i]
        ret.append(par_sum / n)
        par_sum = 0
    return ret


def medias_alumnos(n, mat):
    ret = []
    for i in range(0, n):
        ret.append(sum(mat[i]) / 6)
    return ret


def ultra_media(n, mat):
    parho_suma = 0
    for i in range(0, n):
        parho_suma += sum(mat[i])
    return parho_suma / (6 * n)


def cant_alumnos_sup_media(n, mat):
    temp = ultra_media(n, mat)
    p = medias_alumnos(n, mat)

    cant = 0
    for i in p:
        if i > temp:
            cant += 1
    return cant


n = int(input("Ingrese la cantidad de alumnos: "))
if n <= 0 or n >= 31:
    print("Inválidos o demasiados alumnos")
    quit()


print("Puntos por cada examen: 7")

mat = []
for i in range(0, n):
    aux = []
    print("Primera ocasión:\nTest: ")
    z = int(input())
    if z < 0 or z > 7:
        print("Inválido")
        quit()
    aux.append(z)

    print("Problemas: ")
    z = int(input())
    if z < 0 or z > 7:
        print("Inválido")
        quit()
    aux.append(z)

    print("Segunda ocasión:\nTest: ")
    z = int(input())
    if z < 0 or z > 7:
        print("Inválido")
        quit()
    aux.append(z)

    print("Problemas: ")
    z = int(input())
    if z < 0 or z > 7:
        print("Inválido")
        quit()
    aux.append(z)

    print("Tercera ocasión:\nTest: ")
    z = int(input())
    if z < 0 or z > 7:
        print("Inválido")
        quit()
    aux.append(z)

    print("Problemas: ")
    z = int(input())
    if z < 0 or z > 7:
        print("Inválido")
        quit()
    aux.append(z)

    mat.append(aux)

print("Medias en cada tipo de examen en cada convocatoria:")
print(medias_examenes_convocatorias(n, mat), end="\n\n")


print("Media de cada alumno:")
print(medias_alumnos(n, mat))


print(
    "Cantidad de alumnos con puntaje superior a la media:",
    cant_alumnos_sup_media(n, mat),
)
