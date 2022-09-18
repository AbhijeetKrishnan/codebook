from collections import Counter

t = int(input())
for test in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = Counter(a)
    ans = sum([x - 1 for x in cnt.values()])
    print(ans)