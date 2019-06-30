exp = input()
ans = str(eval(exp))
print(ans)
for digit in ans:
    print('+' * ord(ascii(int(digit))) + ".>", end='\n')