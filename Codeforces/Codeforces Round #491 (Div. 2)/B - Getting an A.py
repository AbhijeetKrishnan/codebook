def my_round(n):
    if n - int(n) >= 0.5:
        return int(n) + 1
    else:
        return int(n)

n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = 0
while my_round(sum(a) / n) < 5:
    a[0] = 5
    a.sort()
    ans += 1
print(ans)