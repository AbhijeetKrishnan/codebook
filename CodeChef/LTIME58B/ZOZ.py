t = int(input())
for test in range(t):
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	ans = 0
	asum = sum(a)
	for i in range(n):
		if a[i] + k > asum - a[i]:
			ans += 1
	print(ans)