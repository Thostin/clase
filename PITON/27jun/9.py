print("Ingrese las palabras (ingrese una única letra para finalizar):")

arr = []
pal = "xdddd"
while True:
    pal = input("> ")
    if len(pal) > 1:
        arr.append(pal)
    else:
        break

i = -1
nuevo = []
while i >= -len(arr):
    nuevo.append(arr[i])
    i -= 1

print("Estas son las palabras: ")
for i in nuevo:
    print(i, " ", end="")
print("")
