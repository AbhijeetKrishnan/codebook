from math import *

n = int(input())
g = dict()
for u in range(1, n+1):
    g[u] = []
for edge in range(1, n):
    u, v, w = map(int, input().split())
    g[u].append((v, w))
    g[v].append((u, w))
for u in range(1, n+1):
    g[u].sort(key=lambda edge: edge[1])

#print(g)
ans = dict()
stack = []
new_stack = []
new_stack.append(1)
ans[1] = (0, 0)
l = 0
sign = -1
curr_y = 0
while new_stack:
    #print("Point d")
    stack = list(new_stack)
    new_stack = []
    l += 1
    #print(l)
    sign = -sign
    curr_y = ans[stack[-1]][1]
    while stack:
        #print("Point c")
        e = stack.pop()
        xp = ans[e][0]
        yp = ans[e][1]
        for v, w in g[e]:
            #print("Point b")
            if v not in ans.keys():
                #print("Point a")
                new_stack.append(v)
                x = l
                y = yp + sign * sqrt(w**2 - (l - xp)**2)
                #print(v, y)
                if sign == 1:
                    y = ceil(y)
                elif sign == -1:
                    y = floor(y)
                if sign == 1 and y <= curr_y:
                    y = curr_y + 1
                elif sign == -1 and y >= curr_y:
                    y = curr_y - 1
                curr_y = y
                ans[v] = (x, y)
#print(ans)
for i in range(1, n+1):
    print(ans[i][0], ans[i][1])