t = int(input())

for test in range(t):
    n = int(input())
    s = input()
    one_cnt = sum(map(int, list(s)))
    ans = one_cnt * (one_cnt + 1) // 2
    print(ans)