notes = [100, 50, 10, 5, 2, 1]
t = int(input())
for test in range(t):
    n = int(input())
    count = 0
    for note in notes:
        while n >= note:
            n -= note
            count += 1
    print(count)