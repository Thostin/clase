mat = []
for i in range(0, 4):
    aux = []
    for j in range(0, 4):
        n = int(input(f"""[{i}][{j}]: """))
        aux.append(n)
    mat.append(aux)

for i in range(0, 4):
    for j in range(0, 4):
        print(f"""{mat[i][j]} """, end="")
    print(f"""   {sum(mat[i])}""")
