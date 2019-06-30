def reverse(s, r):
    #print(s, r, s[:r][::-1], s[r:])
    return s[:r][::-1] + s[r:]

n = int(input())
s = input()
for i in range(2, n+1):
    if n % i == 0:
        #print(i)
        s = reverse(s, i)
print(s)