def gen_T1(x, m):
    #a = x % m
    #b = (a * a) % m
    #c = (b * (a + 1)) % m
    #t1 = c // 2
    #return t1
    return ((x * x * (x + 1)) // 2) % m
def gen_T2(x, m):
    t2 = 1
    for i in range(1, (x + 2)):
        t2 = (t2 * (i % m)) % m
    return t2
def gen_STFM(x, m):
    return (gen_T1(x, m) + gen_T2(x, m) - 1)
n, m = map(int, input().split())
num = input().split()
sum = 0
for i in num:
    sum = (sum + gen_STFM(int(i), m)) % m
print(sum)