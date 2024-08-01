alt = [int(input(f"""Alumno {1}> """))]
m = n = alt[0]
pos = lo = 0
for i in range(1, 2000):
    alt.append(int(input(f"""Alumno {i + 1}> """)))
    if 60 > alt[i - 1] or 60 > alt[i] or 200 < alt[i - 1] or 200 < alt[i]:
        break
    m = alt[i] if alt[i] > m else m
    if alt[i] < n:
        n = alt[i]
        pos = i
    if lo < abs(alt[i] - alt[i - 1]):
        lo = abs(alt[i] - alt[i - 1])
print(
    "Cantidad de alumnos:",
    len(alt) - 1,
    "\nLa altura del escolar más alto es:",
    m,
    "\nEl alumno más bajo se encuentra en la posición",
    pos + 1,
    "y mide",
    n,
    "\nLa mayor diferencia entre alumnos consecutivos es",
    m,
    "\nLa altura promedio es",
    int((sum(alt) - alt[-1]) / len(alt)),
)
