#!/usr/bin/python
import itertools
s = input().split(',')
for i in range(len(s)):
    s[i] = s[i].split(';')

s = itertools.chain(*s)
s = list(s)

a = []
b = []

for i in range(len(s)):
    if s[i] == '0':
        a.append(s[i])
    elif s[i].isdigit() and s[i][0] != '0':
        a.append(s[i])
    else:
        b.append(s[i])

if len(a) != 0:
    print('"' + ','.join(a) + '"')
else:
    print("-")
if len(b) != 0:
    print('"' + ','.join(b) + '"')
else:
    print("-")
