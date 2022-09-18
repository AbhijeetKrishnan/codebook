n = int(input())
F = list(map(int, input().split()))
q = int(input())

for qq in range(q):
	i = list(map(int, input().split()))
	if i[0] == 1:
		p = i[1]
		f = i[2]
		F[p-1] = f
	elif i[0] == 2:
		R = i[1]
		prod = 1
		counter = 1
		while counter <= n:
			prod *= F[counter-1]
			counter += R
		first_digit = str(prod)[:1]
		ans = prod % (10**9 + 7)
		print(first_digit, str(ans))