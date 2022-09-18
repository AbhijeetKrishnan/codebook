n = int(input())
a = list(map(int, input().split()))
unlucky = sum([a_i % 2 for a_i in a])
lucky = n - unlucky
if lucky > unlucky:
    print('READY FOR BATTLE')
else:
    print('NOT READY')