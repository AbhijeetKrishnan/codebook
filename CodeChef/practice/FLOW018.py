t = int(input())
for test in range(t):
	n = int(input())
	fact = 1
	while n > 0:
		fact *= n
		n -= 1
	print(fact)