t = int(input())

for test in range(t):
    x, y, k, n = map(int, input().split())
    possible = False
    for i in range(n):
        p, c = map(int, input().split())
        if y + p >= x and k >= c:
            possible = True
    if possible:
        print("LuckyChef")
    else:
        print("UnluckyChef")