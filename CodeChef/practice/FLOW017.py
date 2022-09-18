t = int(input())
for test in range(t):
	a = list(map(int, input().split()))
	a.sort()
	print(a[1])