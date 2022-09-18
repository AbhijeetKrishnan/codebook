t = int(input())

for test in range(t):
    s = input()
    cnt = 0
    i = 0
    ans = 0
    for c in s:
        if c is '<':
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            break
        if cnt == 0:
            ans = i + 1
        i += 1
    print(ans)