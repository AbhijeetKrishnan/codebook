t = int(input())
while t > 0:
    n, s = map(int, input().split())
    sum = n * (n + 1) / 2
    #print(sum)
    ideal_rank_list = []
    for i in range(1, n + 1):
        ideal_rank_list.append(i)
    #print(ideal_rank_list)
    ptr = n - 1
    #print(ptr)
    nop = 0
    #print(nop)
    while (ptr >= 0) and (sum > s):
        nop += 1
        #print(nop)
        if (ideal_rank_list[ptr] - (sum - s)) < 1:
            sum = sum - ideal_rank_list[ptr] + 1
            #print(sum)
        else:
            sum = s
            #print(sum)
        ptr -= 1
        #print(ptr)
    print(nop)
    t = t - 1