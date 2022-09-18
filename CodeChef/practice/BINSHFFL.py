def set_bits(n):
    return bin(n).count("1")

t = int(input())
for test in range(t):
    a, b = map(int, input().split())
    if a == b:
        ans = 0
    elif b == 0 or (a > 0 and b == 1):
        ans = -1
    else:
        set_bits_a = set_bits(a)
        set_bits_b_less_1 = set_bits(b - 1)
        if set_bits_a <= set_bits_b_less_1:
            ans = set_bits_b_less_1 - set_bits_a + 1
        else:
            ans = 2
    print(ans)