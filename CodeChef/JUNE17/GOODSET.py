t = int(input())
x = list(range(400, 501))
for test in range(t):
    n = int(input())
    for i in range(n):
        print(x[i], end=' ')
    print()