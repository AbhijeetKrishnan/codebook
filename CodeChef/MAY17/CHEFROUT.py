import re

m = re.compile('^(C)*(E)*(S)*$')

test = int(input())

for t in range(test):
    s = input()
    if m.fullmatch(s):
        print('yes')
    else:
        print('no')