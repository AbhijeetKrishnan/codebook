def cnt_inversions(a):
    ans = 0
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if a[i] > a[j]:
                ans += 1
    return ans

def generate(a, k):
    ret = []
    for i in range(2**k):
        ret.append((cnt_inversions([a_i ^ i for a_i in a]), i))
    ret.sort()
    return ret

t = int(input())
for test in range(t):
    n, k, p = map(int, input().split())
    a = list(map(int, input().split()))
    _, ans = generate(a, k)[p-1]
    print(ans)