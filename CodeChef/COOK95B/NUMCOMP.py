t = int(input())
for test in range(t):
    a, b, n = map(int, input().split())
    if n % 2 == 0:
        if abs(a) < abs(b):
            ans = 2
        elif abs(a) > abs(b):
            ans = 1
        else:
            ans = 0
    else:
        if a >= 0 and b >= 0:
            if a < b:
                ans = 2
            elif a > b:
                ans = 1
            else:
                ans = 0
        elif a >= 0 and b < 0:
            ans = 1
        elif a < 0 and b >= 0:
            ans = 2
        else:
            if abs(a) < abs(b):
                ans = 1
            elif abs(a) > abs(b):
                ans = 2
            else:
                ans = 0
    print(ans)