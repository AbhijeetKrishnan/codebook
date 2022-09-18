from math import ceil

t = int(input())
for test in range(t):
    n, h = map(int, input().split())
    a = list(map(int, input().split()))
    lo = 1
    hi = max(a)
    while lo < hi:
        k = (lo + hi) // 2
        hrs = sum([ceil(x / k) for x in a])
        if hrs <= h:
            hi = k
        else:
            lo = k + 1
        #print(lo, hi)
    print(hi)