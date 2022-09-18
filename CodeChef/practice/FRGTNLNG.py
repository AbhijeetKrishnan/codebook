t = int(input())

for test in range(t):
    n, k = map(int, input().split())
    words = input().split()
    hashmap = dict(zip(words, [False] * len(words)))
    for i in range(k):
        tmp = input().split()
        l = int(tmp[0])
        strings = tmp[1:]
        for phrase in strings:
            if phrase in hashmap.keys():
                hashmap[phrase] = True
    #print(hashmap)
    for i in words:
        if hashmap[i]:
            print("YES", end=' ')
        else:
            print("NO", end=' ')
    print()