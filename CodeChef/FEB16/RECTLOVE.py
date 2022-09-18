def get_xy(k, m):
    x = ((k - 1) // m) + 1
    y = k % m
    if y == 0:
        y = m
    return x, y

def nc2(n):
    return (n * (n - 1)) // 2

t = int(input())
for test in range(t):
    n, m, k = map(int, input().split())
    hearts = list(map(int, input().split()))
    ans = 0
    for i in hearts:
        x, y = get_xy(i, m)
        #print(x, y)
        term = x * y * (n - x + 1) * (m - y + 1)
        ans = ans + term
    total_rec = nc2(n + 1) * nc2(m + 1)
    #print(ans, total_rec)
    ans = ans / total_rec
    print('%.20f' % ans)