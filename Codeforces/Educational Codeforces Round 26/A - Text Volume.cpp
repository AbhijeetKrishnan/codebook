import string

n = int(input())
s = input()
words = s.split()
capcount = [sum(1 for c in val if c.isupper()) for val in words]
ans = max(capcount)
print(ans)