t = int(input())

for tt in range(t):
    a, b, c = map(int, input().split())
    a, b, c = sorted([a, b, c])
    ans = (a * (b - 1) * (c - 2)) % (10 ** 9 + 7)
    print(ans)