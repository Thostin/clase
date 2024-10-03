def sanar(mag, VidaInicial, VidaActual, Distancia):
    # Buscar los luchadores con la mínima distancia primero
    # No fuimos capaces de encontrar el agoritmo más eficiente
    # No, un algoritmo de la menor razón no termina siendo lo óptimo
    # pero ya no hay tiempo de desarrollar algo con la función zeta de Riemann
    magia = [3, 5]

    max_gen = 0
    n = len(VidaInicial)
    for k in range(0, n):
        max_ratio = 0
        max_ratio_pos = 0
        i = 0

        while i < len(VidaInicial):
            if VidaInicial[i] == VidaActual[i]:
                del VidaInicial[i]
                del VidaActual[i]
                del Distancia[i]
                continue
            elif VidaInicial[i] - VidaActual[i] > 10:
                if (
                    10 / magia[Distancia[i] - 1] > max_ratio
                    and magia[Distancia[i] - 1] <= mag
                ):
                    max_ratio = 10 / magia[Distancia[i] - 1]
                    max_ratio_pos = i
            elif (VidaInicial[i] - VidaActual[i]) / magia[
                Distancia[i] - 1
            ] > max_ratio and magia[Distancia[i] - 1] <= mag:
                max_ratio = (VidaInicial[i] - VidaActual[i]) / magia[Distancia[i] - 1]
                max_ratio_pos = i
            i += 1
        if 0 == max_ratio:
            return max_gen
        elif VidaInicial[max_ratio_pos] - VidaActual[max_ratio_pos] > 10:
            max_gen += 10
            VidaActual[max_ratio_pos] += 10
            mag -= magia[Distancia[max_ratio_pos] - 1]
        else:
            max_gen += VidaInicial[max_ratio_pos] - VidaActual[max_ratio_pos]
            mag -= magia[Distancia[max_ratio_pos] - 1]
            del VidaInicial[max_ratio_pos]
            del VidaActual[max_ratio_pos]
            del Distancia[max_ratio_pos]
    return max_gen


n = int(input("Ingrese la cantidad de luchadores que posee: "))
if n <= 0 or n >= 51:
    print("Error por pelotudo")
    quit()
magia = int(input("Ingrese la cantidad de magia que posee el hechicero: "))
if magia <= -1 or magia >= 101:
    print("Error por pelotudo")
    quit()

print("A continuación ingrese los datos de cada luchador: ")

VidaInicial = []
VidaActual = []
Distancia = []

for i in range(0, n):
    VidaInicial.append(int(input(f"Vida inicial del luchador {i}: ")))
    VidaActual.append(int(input(f"Vida actual del luchador {i}: ")))
    Distancia.append(int(input(f"Distancia actual del luchador {i}: ")))
    if not (1 <= VidaActual[i] <= VidaInicial[i] <= 100) or not (
        1 <= Distancia[i] <= 2
    ):
        print("Fin por pelotudo")
        quit()

print(
    f"La máxima cantidad de puntos de vida que se pueden regenerar que se pudo encontrar es: {sanar(magia, VidaInicial, VidaActual, Distancia)}"
)
