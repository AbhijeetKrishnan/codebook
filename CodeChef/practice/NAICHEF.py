from collections import Counter

t = int(input())
for test in range(t):
    n, a, b = map(int, input().split())
    x = Counter(list(map(int, input().split())))
    ans = (x[a] * x[b]) / (n * n)
    print('%.10f' % ans)