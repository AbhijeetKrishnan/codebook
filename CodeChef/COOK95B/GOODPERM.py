import itertools as it
import collections

def construct(perm, a):
    perm = collections.deque(perm)
    ret = list(a)
    #print(perm)
    for i in range(len(ret)):
        if ret[i] == 0:
            ret[i] = perm.popleft()
            #print(i, ret)
    #print(a)
    return ret

def inv(perm):
    ret = 0
    for i in range(1, len(perm)):
        if perm[i] > perm[i-1]:
            ret += 1
    return ret


t = int(input())
for test in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    for perm in it.permutations(set(range(1, n + 1)) - set(a)):
        #print(perm)
        if inv(construct(perm, a)) == k:
            ans += 1
    print(ans)