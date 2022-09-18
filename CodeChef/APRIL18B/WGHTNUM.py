wt = dict()
for d_n in range(10):
	for d_1 in range(1, 10):
		#print(d_n, d_1)
		if d_n - d_1 in wt.keys():
			wt[d_n - d_1] += 1
		else:
			wt[d_n - d_1] = 1
#print(sum(wt))
MOD = 10**9 + 7

def fast_pow(base, exponent, modulo):
	if exponent == 0:
		return 1
	elif exponent % 2 == 0:
		tmp = fast_pow(base, exponent // 2, modulo) % modulo
		tmp = (tmp * tmp) % modulo
		return tmp
	elif exponent % 2 == 1:
		tmp = fast_pow(base, exponent // 2, modulo) % modulo
		tmp = (tmp * tmp) % modulo
		tmp = (tmp * base) % modulo
		return tmp
		
t = int(input())
for test in range(t):
	n, w = map(int, input().split())
	if w in wt.keys():
		w = wt[w]
	else:
		w = 0
	ans = (w * fast_pow(10, n - 2, MOD)) % MOD
	print(ans)