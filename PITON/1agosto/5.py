import math


def area_circulo(radio):
    return math.pi * radio * radio


def volumen_cilindro(radio, h):
    return area_circulo(radio) * h


r = int(input("Ingrese el radio del cilindro: "))
h = int(input("Ingrese la altura del cilindro: "))

print(f"El volumen del cilindro es: {volumen_cilindro(r, h)}")
