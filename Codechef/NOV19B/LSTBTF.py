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

if __name__ == '__main__':
    t = int(input())
    for test in range(t):
        digs = int(input())
        found = False
        n = digs
        max_change = 81 * n
        for i in range(1, digs + 1):
            for square in squares(n, max_change):
                diff = square - n
                if diff == 0:
                    print('1' * digs)
                    found = True
                    break
                if diff in poss[i]:
                    print(('1' * (digs - len(poss[i][diff])) + poss[i][diff]))
                    found = True
                    break
            if found:
                break
