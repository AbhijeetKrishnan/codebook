def func(n, k):
    v = 0
    p = 0
    while n > 0:
        v += min(k, n)
        n = max(n - k, 0) # Vasya
        p += n // 10
        n -= n // 10 # Petya
    return v >= p

n = int(input())
lo = 1
hi = n
while lo <= hi:
    mid = (lo + hi) // 2
    if func(n, mid):
        hi = mid - 1
    else:
        lo = mid + 1
print(lo)