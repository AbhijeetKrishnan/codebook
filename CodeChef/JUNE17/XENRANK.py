t = int(input())
for test in range(t):
    u, v = map(int, input().split())
    diag = u + v
    top_rank = (diag * (diag + 1)) // 2 + 1
    ans = top_rank + (diag - v)
    print(ans)