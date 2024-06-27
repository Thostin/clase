arr = []
for i in range(0, 10):
    arr.append(10 - i)
print("Números del 1 al 10 en reversa y separados por comas:")

print(arr[0], end="")
for i in range(1, 10):
    print(", ", arr[i], end="")
print("")
