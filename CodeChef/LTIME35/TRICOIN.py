import math
t = int(input())
for test in range(t):
	n = int(input())
	ans = (math.sqrt(8 * n + 1) - 1) / 2
	ans = int(ans)
	print(ans)