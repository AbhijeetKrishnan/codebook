import re

pat = re.compile(r"(1+)(2+)(3+)(4+)(5+)(6+)7+\6\5\4\3\2\1")
t = int(input())
for test in range(t):
    n = int(input())
    s = input()
    s = s.replace(" ", "")
    if pat.fullmatch(s):
        print("yes")
    else:
        print("no")