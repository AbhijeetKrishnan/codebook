t = int(input())
for test in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    g = list(map(int, input().split()))
    front = sum([l_i <= g_i for l_i, g_i in zip(l, g)]) == n
    #print(front)
    back = sum([l_i <= g_i for l_i, g_i in zip(l, reversed(g))]) == n
    #print(back)
    if front and back:
        print("both")
    elif front:
        print("front")
    elif back:
        print("back")
    else:
        print("none")