arr = list("abcdefghijklmnopqrstuvwxyz")

j = 0
while j < len(arr):
    del arr[j]
    j += 3

print(arr[0], end="")
for i in range(1, len(arr)):
    print(", ", arr[i], end="")
print("")
