n = int(input())
a = []
for i in range(n):
    a.append(input())
a.sort(key=len)
isValid = True
for i in range(1, n):
    if a[i - 1] not in a[i]:
        isValid = False
        break
if isValid:
    print("YES")
    for i in range(n):
        print(a[i])
else:
    print("NO")
