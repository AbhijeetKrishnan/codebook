t = int(input())
for test in range(t):
    n, k = map(int, input().split())
    w = list(map(int, input().split()))
    min_k = min(k, n - k)
    w.sort()
    diff = sum(w[min_k:]) - sum(w[:min_k])
    print(diff)