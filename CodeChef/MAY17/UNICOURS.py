test = int(input())

for t in range(test):
    n = int(input())
    a = list(map(int, input().split()))
    ans = n - max(a)
    print(ans)