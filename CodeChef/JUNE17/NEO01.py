t = int(input())
for test in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted(a, reverse=True)
    ans = 0
    curr_sum = 0
    for i in range(n):
        curr_sum += a[i]
        if curr_sum * (i + 1) > ans:
            ans = curr_sum * (i + 1)
        else:
            ans += a[i]
    print(ans)