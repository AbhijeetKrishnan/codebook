a, b, c, n = map(int, input().split())
ans = n - (a + b - c)
if a > n or b > n:
    ans = -1
if c > min(a, b):
    ans = -1
if a + b - c > n:
    ans = -1
if n - (a + b - c) < 1:
    ans = -1
print(ans)