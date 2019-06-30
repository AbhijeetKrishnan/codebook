from collections import Counter
from string import ascii_lowercase

n, k = map(int, input().split())
s = input()
freq = Counter(s)
for c in ascii_lowercase:
    if k <= freq[c]:
        freq[c] -= k
        break
    else:
        k -= freq[c]
        freq[c] = 0
ans = []
for c in s[::-1]:
    if freq[c] > 0:
        ans.append(c)
        freq[c] -= 1
print(''.join(ans[::-1]))
