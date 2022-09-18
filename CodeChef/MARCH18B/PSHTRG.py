n, q = map(int, input().split())
a = list(map(int, input().split()))
for query in range(q):
    v1, v2, v3 = map(int, input().split())
    if v1 == 1:
        a[v2-1] = v3
    elif v1 == 2:
        b = a[v2-1:v3]
        b.sort()
        #print(a, b)
        i = (v3 - v2 + 1) - 3
        while i >= 0 and b[i] + b[i+1] <= b[i+2]:
            i -= 1
        if i >= 0:
            print(b[i] + b[i+1] + b[i+2])
        else:
            print(0)