def IMC(peso, h):
    return peso / (h * h)


m = float(input("Ingrese su peso en kilogramos: "))
h = float(input("Ingrese su altura en metros: "))

print(f"Tu índice de masa corporal es: {round(IMC(m, h), 2)}")
