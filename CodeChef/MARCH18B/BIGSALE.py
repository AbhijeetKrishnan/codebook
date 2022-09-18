t = int(input())
for test in range(t):
    n = int(input())
    ans = 0
    for cases in range(n):
        p, q, d = map(int, input().split())
        ans += q * (d/100)**2 * p
    print("%.9f" % ans)