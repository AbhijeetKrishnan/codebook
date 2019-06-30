n = int(input())
a = list(map(int, input().split()))
ans = len(set(a)) if 0 not in a else len(set(a)) - 1
print(ans)