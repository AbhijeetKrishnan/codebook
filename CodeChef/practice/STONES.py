t = int(input())

for tt in range(t):
    j = input()
    s = input()
    ans = 0
    for c in s:
        if c in j:
            ans += 1

    print(ans)