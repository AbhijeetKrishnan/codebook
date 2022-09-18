test = int(input())

for t in range(test):
    n = int(input())
    a = list(map(int, input().split()))

    lowest_zero = n
    num_zeroes = 0

    for i in range(n):
        if a[i] == 0:
            num_zeroes += 1
            if i < lowest_zero:
                lowest_zero = i

    ans = 1000 * num_zeroes + 100 * (n - lowest_zero)
    print(ans)