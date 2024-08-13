# from random import seed
from random import random
from random import seed


def max_pos(rival):
    max_elem = rival[0]
    pos_max = 0
    for i in range(1, len(rival)):
        if rival[i] > max_elem:
            pos_max = i
            max_elem = i
    # rival[pos_max] = -99
    return pos_max


def minmax(hechicera, rival, pos):
    pes = -1
    ulmax = 5000000000
    min = hechicera[0]
    pos_min = 0
    for i in range(0, len(hechicera)):
        if hechicera[i] < min:
            min = hechicera[i]
            pos_min = i

        if hechicera[i] == rival[pos]:
            ulmax = hechicera[i]
            del hechicera[i]
            return ulmax

        elif hechicera[i] > rival[pos] and hechicera[i] < ulmax:
            ulmax = hechicera[i]
            pes = i
    rival[pos] = -99
    if pes == -1:
        del hechicera[pos_min]
        return min
    else:
        del hechicera[pes]
        return ulmax


def batamon(hechicera, rival, enfrentamientos):
    rival_copy = rival.copy()
    hechicera_copy = hechicera.copy()

    for i in range(0, len(rival_copy)):
        cop_max = max_pos(rival_copy)
        enfrentamientos[cop_max] = minmax(hechicera, rival_copy, cop_max)

    for k in hechicera_copy:
        print(f"{k:2d} ", end="")
    print(f"\n", end="")

    for k in enfrentamientos:
        print(f"{k:2d} ", end="")
    print(f"\n", end="")

    # print("")
    for k in rival:
        print(f"{k:2d} ", end="")
    p = 0
    for i in range(0, n):
        if enfrentamientos[i] >= rival[i]:
            p += 1
    print("\nGanará un máximo de", p, "partidas")


# seed(34)

seed(int(input()))
n = int(input("Ingrese la cantidad de mostruos de cada rival: "))
if n < 1 or n > 200000:
    print("Improper len input")
    quit()

hechicera = []
rival = []

for i in range(0, n):
    hechicera.append(int(100 * random()))
    rival.append(int(100 * random()))

enfrentamientos = []
for i in range(0, n):
    enfrentamientos.append(0)

batamon(hechicera, rival, enfrentamientos)
