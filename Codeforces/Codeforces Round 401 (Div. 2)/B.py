from collections import Counter

INF = 10**9

def min_flicks(seq, i, cnt, dp):
    if i >= len(seq):
        return 0
    if (i, cnt) not in dp:
        min_flick_val = INF
        for j in range(0, 10):
            if cnt[j] > 0:
                new_cnt = list(cnt)
                new_cnt[j] -= 1
                new_cnt = tuple(new_cnt)
                if j < seq[i]:
                    min_flick_val = min(min_flick_val, 1 + min_flicks(seq, i + 1, new_cnt, dp))
                elif j == seq[i]:
                    min_flick_val = min(min_flick_val, min_flicks(seq, i + 1, new_cnt, dp))
                else:
                    min_flick_val = min(min_flick_val, min_flicks(seq, i + 1, new_cnt, dp))
        dp[(i, cnt)] = min_flick_val
    return dp[(i, cnt)]

def max_flicks(seq, i, cnt, dp):
    if i >= len(seq):
        return 0
    if (i, cnt) not in dp:
        max_flick_val = 0
        for j in range(0, 10):
            if cnt[j] > 0:
                new_cnt = list(cnt)
                new_cnt[j] -= 1
                new_cnt = tuple(new_cnt)
                if j < seq[i]:
                    max_flick_val = max(max_flick_val, max_flicks(seq, i + 1, new_cnt, dp))
                elif j == seq[i]:
                    max_flick_val = max(max_flick_val, max_flicks(seq, i + 1, new_cnt, dp))
                else:
                    max_flick_val = max(max_flick_val, 1 + max_flicks(seq, i + 1, new_cnt, dp))
        dp[(i, cnt)] = max_flick_val
    return dp[(i, cnt)]

n = int(input())
seq = tuple(map(int, list(input())))
m_seq = tuple(map(int, list(input())))
cnt = [0] * 10
for digit in m_seq:
    cnt[digit] += 1
cnt = tuple(cnt)

dp = {}
print(min_flicks(seq, 0, cnt, dp))
dp = {}
print(max_flicks(seq, 0, cnt, dp))