t = int(input())
for test in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    if x1 != x2 and y1 != y2:
        print('sad')
    elif x1 > x2:
        print('left')
    elif x1 < x2:
        print('right')
    elif y1 > y2:
        print('down')
    elif y1 < y2:
        print('up')