seq = [0]
last_seen = {}
for i in range(1, 128):
    x = seq[i - 1]
    if x not in last_seen:
        seq.append(0)
    else:
        seq.append(i - 1 - last_seen[x])
    last_seen[x] = i - 1

if __name__ == '__main__':
    t = int(input())
    for test in range(t):
        n = int(input())
        freq = 0
        for i in range(n):
            if seq[i] == seq[n - 1]:
                freq += 1
        print(freq)