from math import *

l, r, k = map(int, input().split())
start_pow = int(log(l, k))
start_val = int(pow(k, start_pow))
while (start_val < l):
    start_val = start_val * k
if (start_val > r):
    print("-1")
else:
    while (start_val <= r):
        print(int(start_val), end=' ')
        start_val = start_val * k
