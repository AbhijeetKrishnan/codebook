import string
from collections import defaultdict


def isConsonant(c):
    if c in 'aeiou':
        return False
    return True

def isBobRecipe(s):
    consonantCount = sum([1 for c in s if isConsonant(c)])
    if 2 * consonantCount > len(s):
        return True
    for i in range(len(s) - 1):
        if isConsonant(s[i]) and isConsonant(s[i + 1]):
            return True
    return False

if __name__ == '__main__':
    t = int(input())
    for test in range(t):
        l = int(input())
        L = []
        for _ in range(l):
            s = input()
            L.append(s)
        Alice = []
        Bob = []
        for s in L:
            if isBobRecipe(s):
                Bob.append(s)
            else:
                Alice.append(s)

        #print('Alice: ', Alice)
        #print('Bob', Bob)

        k_alice = len(Alice)
        k_bob = len(Bob)

        freq_alice = defaultdict(int)
        x_alice = defaultdict(int)
        for s in Alice:
            seen = defaultdict(bool)
            for c in s:
                freq_alice[c] += 1
                if not seen[c]:
                    seen[c] = True
                    x_alice[c] += 1
        
        freq_bob = defaultdict(int)
        x_bob = defaultdict(int)
        for s in Bob:
            seen = defaultdict(bool)
            for c in s:
                freq_bob[c] += 1
                if not seen[c]:
                    seen[c] = True
                    x_bob[c] += 1

        x_alice = list(x_alice.values())
        x_bob = list(x_bob.values())
        freq_alice = list(freq_alice.values())
        freq_bob = list(freq_bob.values())

        #print(freq_alice, freq_bob)
        #print(x_alice, x_bob)

        score = 1
        x_alice += [1] * (len(x_bob) - len(x_alice))
        x_bob += [1] * (len(x_alice) - len(x_bob))
        for x_a, x_b in zip(x_alice, x_bob):
            score *= x_a / x_b
        freq_alice += [1] * (len(freq_bob) - len(freq_alice))
        freq_bob += [1] * (len(freq_alice) - len(freq_bob))
        for f_a, f_b in zip(freq_alice, freq_bob):
            score *= (f_b ** k_bob) / (f_a ** k_alice)
        if score > 10 ** 7:
            print('Infinity')
        else:
            print('{:.10f}'.format(score))    
