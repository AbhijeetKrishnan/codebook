t = int(input())
for test in range(t):
	n = input()
	ans = 0
	for c in n:
		if c == '4':
			ans += 1
	print(ans)