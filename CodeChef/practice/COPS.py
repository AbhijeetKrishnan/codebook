t = int(input())

for test in range(t):
    m, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    a = sorted(a)
    house = [1] * 100
    prev = 1
    for i in a:
        for j in range(max(prev - 1, i - x * y - 1), min(i + x * y, 100)):
            house[j] = 0
        prev = min(i + x * y, 100)
    ans = sum(house)
    print(ans)