arr = []
print("Ingrese las materias del curso (ingrese una única letra para finalizar):")

pal = "xdddd"
while True:
    pal = input("> ")
    if len(pal) > 1:
        arr.append(pal)
    else:
        break

for l in arr:
    print(f"""Yo estudio {l}
""")
