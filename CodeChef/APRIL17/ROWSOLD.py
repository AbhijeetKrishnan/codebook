t = int(input())

for test in range(t):
    s = input()
    s += '1'
    train_cnt = 0
    train_pos = -1
    ans = 0

    i = 0
    while i != len(s):
        # Getting next 1
        while s[i] != '1':
            i += 1

        # Prev train has to be moved to i - 1 if prev train_pos and i
        # have absolute difference > 1
        if i - train_pos > 1:
            ans += train_cnt * (1 + (i - 1 - train_pos))

        train_cnt += 1
        train_pos = i

        i += 1

    print(ans)