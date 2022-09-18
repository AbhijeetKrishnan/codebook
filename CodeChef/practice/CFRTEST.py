t = int(input())
for test in range(t):
    n = int(input())
    d = list(map(int, input().split()))
    ans = n - (len(d) - len(set(d)))
    print(ans)