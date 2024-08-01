def fac(n):
    if n < 0:
        return -1
    elif n == 0:
        return 1
    k = n
    while n - 2 > 0:
        n -= 1
        k *= n
    return k


n = int(input("Ingrese un entero positivo: "))
print(f"{n}! = {fac(n)}")
