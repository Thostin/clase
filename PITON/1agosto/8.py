def decimal_a_binario(n):
    lista = []
    while n > 0:
        lista.append(n % 2)
        n /= 2
        n = int(n)
    return lista


def binario_a_decimal(cadena):
    n = 0
    pod = 1
    for i in range(len(cadena) - 1, -1, -1):
        n += pod * (1 if cadena[i] == "1" else 0)
        pod *= 2
    return n


n = int(input("Ingrese un número entero positivo: "))
print("Ese número en binario: ", end="")

lista = decimal_a_binario(n)
i = len(lista) - 1
while True:
    if i < 0:
        break
    print(f"{lista[i]}", end="")
    i -= 1
print("")

k = input("Ahora ingrese un número en binario: \n> ")
print(f"Ese número en decimal: {binario_a_decimal(k)}")
