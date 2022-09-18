for tt in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    print(sum(l) - n * min(l))