def IVA(plata, porcentaje):
    if plata < 0 or porcentaje < 0 or porcentaje > 100:
        return 0
    return plata * (1 + porcentaje / 100)


# main
n = int(input("Ingrese la plata que tiene: "))
p = int(input("Ahora ingrese el porcentaje IVA: "))

print(f"A {n}$ se le aplica {p}% de IVA: {int(IVA(n,p))}")
