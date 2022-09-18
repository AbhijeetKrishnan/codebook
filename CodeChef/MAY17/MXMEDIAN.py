test = int(input())

for t in range(test):
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted(a)
    b = []
    for i in range(n):
        b.append(a[i])
        b.append(a[2*n-1-i])
    print(b[n])
    for i in b:
        print(i, end=' ')
    print()