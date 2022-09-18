t = int(input())

for test in range(t):
    n, u, d = map(int, input().split())
    h = list(map(int, input().split()))
    i = 0
    usedPara = False
    while i + 1 < n:
        if 0 <= h[i+1] - h[i] <= u:
            i += 1
        elif 0 <= h[i] - h[i+1] <= d:
            i += 1
        elif 0 < h[i] - h[i+1] and not usedPara:
            i += 1
            usedPara = True
        else:
            break
    print(i+1)