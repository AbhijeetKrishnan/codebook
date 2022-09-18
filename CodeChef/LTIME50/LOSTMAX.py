t = int(input())

for test in range(t):
    a = list(map(int, input().split()))
    a = sorted(a)
    if a[-1] == (len(a) - 1):
        ans = a[-2]
    else:
        ans = a[-1]
    print(ans)