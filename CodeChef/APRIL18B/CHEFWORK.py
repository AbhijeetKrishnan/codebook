n = int(input())
c = list(map(int, input().split()))
t = list(map(int, input().split()))
min_a = 10**9
min_t = 10**9
min_at = 10**9
ans = 10**9
for i in range(n):
	if t[i] == 1:
		min_t = min(min_t, c[i])
	elif t[i] == 2:
		min_a = min(min_a, c[i])
	elif t[i] == 3:
		min_at = min(min_at, c[i])
ans = min(min_at, min_a + min_t)
print(ans)