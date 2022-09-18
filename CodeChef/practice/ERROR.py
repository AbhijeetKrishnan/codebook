t = int(input())
for test in range(t):
    s = input()
    if '010' in s or '101' in s:
        print('Good')
    else:
        print('Bad')