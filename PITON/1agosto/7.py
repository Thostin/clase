def quad(listatkk):
    lista = []
    for i in listatkk:
        lista.append(i * i)
    return lista


print("Ingrese una lista de números (ingrese un número negativo para finalizar):")
lista = []
while True:
    n = int(input("> "))
    if n < 0:
        break
    lista.append(n)
print("Los cuadrados de todos los elementos son:")

kp = quad(lista)
for i in kp:
    print(f"{i} ", end="")
print("")
