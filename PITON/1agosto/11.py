def es_letra(c):
    s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if c in s:
        return True
    return False


c = input("Ingrese una letra: ")
if es_letra(c):
    print("Es una letra alfabética")
else:
    print("No es una letra alfabética")
