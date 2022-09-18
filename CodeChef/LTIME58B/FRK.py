n = int(input())
ans = 0
for i in range(n):
	u = input()
	isFriend = False
	if "ch" in u:
		isFriend = True
	elif "he" in u:
		isFriend = True
	elif "ef" in u:
		isFriend = True
	if isFriend:
		ans += 1
print(ans)