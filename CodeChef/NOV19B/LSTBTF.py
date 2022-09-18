import math

poss = [None]
poss.append({
    3: '2',
    8: '3',
    15: '4',
    24: '5',
    35: '6',
    48: '7',
    63: '8',
    80: '9',
})

def digitSum(n):
    r = 0
    while n:
        r, n = r + ((n % 10) ** 2), n // 10
    return r

def isPerfectSquare(n):
    return math.sqrt(n) - math.floor(math.sqrt(n)) == 0

def isBeautifulNumber(n):
    digit_sum = digitSum(n)
    # print(f'digitSum of {n} is {digit_sum}')
    if isPerfectSquare(digit_sum):
        return True
    return False

def squares(a, b):
    start = math.ceil(math.sqrt(a))
    end = math.floor(math.sqrt(b))
    for num in range(start, end + 1):
        yield num ** 2

for i in range(2, 40):
    poss.append({})
    for key, value in poss[i - 1].items():
        for base, orig_value in poss[1].items():
            new_key = key + base
            new_value = ''.join(sorted(value + orig_value))
            if new_key not in poss[i]:
                poss[i][new_key] = new_value
            elif new_value < poss[i][new_key]:
                poss[i][new_key] = new_value

# print(poss)

if __name__ == '__main__':
    t = int(input())
    for test in range(t):
        digs = int(input())
        found = False
        n = digs
        max_change = 81 * n
        for i in range(1, digs + 1):
            min_ans = '9' * digs
            for square in squares(n, max_change):
                diff = square - n
                # print(f'Square: {square}, diff: {diff}')
                if diff > i * 80: # change to all 9s
                    break
                if diff == 0:
                    found = True
                    ans = '1' * digs
                    min_ans = min(min_ans, ans)
                # print(f'diff = {diff} in poss[{i}] = {diff in poss[i]}')
                if diff in poss[i]:
                    # print(f'While updating ans: diff = {diff} in poss[{i}] = {diff in poss[i]}')
                    found = True
                    ans = ('1' * (digs - len(poss[i][diff])) + poss[i][diff])
                    
                    min_ans = min(min_ans, ans)
                    # print(ans, min_ans)
            if found:
                print(min_ans)
                # if not isBeautifulNumber(int(min_ans)):
                #     print(digs, min_ans)
                # for poss_ans in range(int(min_ans) - 1, int('1' * digs), -1):
                #     if '0' not in str(poss_ans) and isBeautifulNumber(poss_ans):
                #         print(digs, min_ans, poss_ans, digitSum(poss_ans))
                break