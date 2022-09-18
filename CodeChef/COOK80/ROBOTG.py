t = int(input())
for tt in range(t):
    n, m = map(int, input().split())
    s = input()
    min_x = max_x = min_y = max_y = 0
    curr_x = curr_y = 0
    for c in s:
        if c == 'U':
            curr_y += 1
        elif c == 'D':
            curr_y -= 1
        elif c == 'L':
            curr_x -= 1
        elif c == 'R':
            curr_x += 1
        min_x = min(min_x, curr_x)
        max_x = max(max_x, curr_x)
        min_y = min(min_y, curr_y)
        max_y = max(max_y, curr_y)

    if (max_x - min_x + 1) <= m and (max_y - min_y + 1) <= n:
        print("safe")
    else:
        print("unsafe")