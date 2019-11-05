from itertools import zip_longest
import math

def dist(u, v):
    x1, y1 = u
    x2, y2 = v
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

def grouper(iterable, n=2, fillvalue=None):
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)

def min_distance(x, A, B, C):
    min_c = min(grouper(C), key=lambda c: dist(c, x))
    min_b = min(grouper(B), key=lambda b: dist(min_c, b) + dist(b, x))
    min_a = min(grouper(A), key=lambda a: dist(min_b, a) + dist(a, x))
    print(min_a, min_b, min_c, dist(min_a, x) + dist(min_b, min_a) + dist(min_c, min_b))
    return dist(min_a, x) + dist(min_b, min_a) + dist(min_c, min_b)

if __name__ == '__main__':
    t = int(input())
    for test in range(t):
        x = tuple(map(int, input().split()))
        n, m, k = map(int, input().split())
        N = list(map(int, input().split()))
        M = list(map(int, input().split()))
        K = list(map(int, input().split()))

        print(min(min_distance(x, N, M, K), min_distance(x, M, N, K)))
