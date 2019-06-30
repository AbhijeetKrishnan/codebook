l = list(map(int, input().split()))
l = l[1:]
l.sort()
ans = ' '.join(str(x) for x in l)
print(ans)