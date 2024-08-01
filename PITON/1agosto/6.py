def media(listatkk):
    return sum(listatkk) / len(listatkk)


print("Ingrese una lista de números (ingrese un número negativo para finalizar):")

lista = []
while True:
    n = int(input("> "))
    if n < 0:
        break
    lista.append(n)
print(f"La media de los elementos es: {media(lista)}")
