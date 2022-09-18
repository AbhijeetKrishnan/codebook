test = int(input())
for t in range(test):
	ans = 0
	op, nat = input().split()
	op = int(op)
	for i in range(op):
		l = input().split()
		if (l[0] == "CONTEST_WON"):
			rank = int(l[1])
			ans += 300 + max(0, 20 - rank)
		elif (l[0] == "TOP_CONTRIBUTOR"):
			ans += 300
		elif (l[0] == "BUG_FOUND"):
			severity = int(l[1])
			ans += severity
		else:
			ans += 50
	if (nat == "INDIAN"):
		ans = ans // 200
	else:
		ans = ans // 400
	print(ans)