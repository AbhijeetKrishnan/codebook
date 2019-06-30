n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
i = 0
while i < len(a) and a[i] <= k:
    ans += 1
    i += 1
j = len(a) - 1
while j > i and a[j] <= k:
    ans += 1
    j -= 1
print(ans)