import itertools
import math

def dist(u, v):
    x1, y1 = u
    x2, y2 = v
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

def grouper(iterable, n=2, fillvalue=None):
    args = [iter(iterable)] * n
    return itertools.zip_longest(*args, fillvalue=fillvalue)

if __name__ == '__main__':
    t = int(input())
    for test in range(t):
        x = tuple(map(int, input().split()))
        n, m, k = map(int, input().split())
        N = list(grouper(list(map(int, input().split()))))
        M = list(grouper(list(map(int, input().split()))))
        K = list(grouper(list(map(int, input().split()))))

        min_n2k = {}
        for i in range(n):
            min_n2k[i] = K.index(min(K, key=lambda k: dist(k, N[i])))
        min_m2k = {}
        for j in range(m):
            min_m2k[j] = K.index(min(K, key=lambda k: dist(k, M[j])))

        min_distance = dist(N[0], x) + dist(M[0], N[0]) + dist(K[0], M[0])
        for i in range(n):
            for j in range(m):
                min_distance = min(min_distance, dist(N[i], x) + dist(M[j], N[i]) + dist(K[min_m2k[j]], M[j]))
                min_distance = min(min_distance, dist(M[j], x) + dist(N[i], M[j]) + dist(K[min_n2k[i]], N[i]))
        print(min_distance)
            
