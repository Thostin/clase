mat = []

k = 1
for i in range(0, 10):
    aux = []
    for j in range(0, 10):
        aux.append(k)
        k += 1
    mat.append(aux)

for m in mat:
    for i in m:
        print(f"""{i}""", end=" ")
    print("")
