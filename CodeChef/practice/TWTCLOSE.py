n, k = map(int, input().split())
state = [0] * n
ans = 0
for click in range(k):
    s = input()
    if "CLICK" in s:
        cmd, id = s.split()
        id = int(id) - 1
        state[id] ^= 1
        if state[id] == 0:
            ans -= 1
        else:
            ans += 1
    else:
        state = [0] * k
        ans = 0
    print(ans)