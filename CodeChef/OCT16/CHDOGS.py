"""
Author: rashomon
Platform: Codechef
URL: https://www.codechef.com/OCT16/problems/CHDOGS
Problem name: Chef and Three Dogs
"""

t = int(input())
for test in range(t):
    s, v = map(int, input().split())
    ans = (2 * s) / (3 * v)
    print('%.15f' % ans)