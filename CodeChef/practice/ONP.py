ops = ['*', '+', '-', '^', '/']

t = int(input())
for test in range(t):
    exp = input()
    stack = []
    operators = []
    for c in exp:
        if c == '(':
            stack.append(c)
        elif c in ops:
            operators.append(c)
        elif c.isalpha():
            stack.append(c)
        elif c == ')':
            op2 = stack.pop()
            op1 = stack.pop()
            op = op1 + op2 + operators.pop()
            stack.pop()
            stack.append(op)
    print(stack[-1])