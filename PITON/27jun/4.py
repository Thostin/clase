arr = []
notas = []
print("Ingrese las materias del curso (ingrese una única letra para finalizar):")

pal = "xdddd"
while True:
    pal = input("> ")
    if len(pal) > 1:
        arr.append(pal)
        n = int(input("Nota que sacó en esa materia: "))
        if n <= 0 or n >= 6:
            print("Nota impropia, chau")
            quit()
        notas.append(n)
    else:
        break

i = 0
while i < len(arr):
    if notas[i] != 1:
        del notas[i]
        del arr[i]
    else:
        i += 1

for i in range(0, len(arr)):
    print(f"""En {arr[i]} has sacado {notas[i]}
""")
