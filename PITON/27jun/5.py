print(
    "Ingrese los números ganadores de la lotería primitiva (entre 1 y 9999999), ingrese un rango inválido para finalizar:"
)
arr = []
while True:
    n = int(input("> "))
    if n <= 0 or n >= 10000000:
        break
    elif n in arr:
        print("Repetido")
    else:
        arr.append(n)
arr.sort()
print("Estos son los números (ordenados de manera ascendente):")
for i in arr:
    print(i)
