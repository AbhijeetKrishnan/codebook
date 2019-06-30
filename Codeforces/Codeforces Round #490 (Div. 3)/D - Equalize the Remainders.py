n, m = map(int, input().split())
a = list(map(int, input().split()))

mod = [[] for i in range(m)]
for i in range(n):
    mod[a[i] % m].append(i)
#print(mod)
k = n // m
free = []
for i in range(m):
    if len(mod[i]) > k:
        free.extend(mod[i][k:])
        mod[i] = mod[i][:k]
ans = 0
#print(free)
#print(mod)
for i in range(m):
    mlen = len(mod[i])
    if mlen < k:
        for j in free[:k - mlen]:
            ans += (i - a[j]) % m
            a[j] += (i - a[j]) % m
            mod[i].append(j)
        free = free[k - mlen:]
#print(mod)
print(ans)
print(' '.join([str(i) for i in a]))
