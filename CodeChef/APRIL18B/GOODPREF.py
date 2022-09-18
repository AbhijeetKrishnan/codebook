from math import *

t = int(input())
for test in range(t):
    s, n = input().split()
    n = int(n)
    s_len = len(s)
    a = [0] * s_len
    b = [0] * s_len
    if s[0] == 'a':
        a[0] = 1
    else:
        b[0] = 1
    for i in range(1, s_len):
        if s[i] == 'a':
            a[i] = a[i-1] + 1
            b[i] = b[i-1]
        else:
            a[i] = a[i-1]
            b[i] = b[i-1] + 1
    #print(a)
    #print(b)
    ans = 0
    if a[s_len-1] < b[s_len-1]:
        for i in range(s_len):
            if a[i] > b[i]:
                ans += max(min(ceil((a[i] - b[i]) / (b[s_len-1] - a[s_len-1])) - 1, n - 1), -1) + 1
    elif a[s_len-1] > b[s_len-1]:
        for i in range(s_len):    
            ans += n - min(max(floor((b[i] - a[i]) / (a[s_len-1] - b[s_len-1])) + 1, 0), n)
    elif a[s_len-1] == b[s_len-1]:
        for i in range(s_len):
            if a[i] > b[i]:
                ans += n
    print(ans)