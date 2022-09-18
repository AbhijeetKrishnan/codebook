t = int(input())
for test in range(t):
    a, b, c = map(int, input().split())
    if a + b + c == 180:
        print('YES')
    else:
        print('NO')