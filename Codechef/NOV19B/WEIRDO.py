import math
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

        score = sum([math.log10(x_a) for x_a in x_alice.values()])
        score -= sum([math.log10(x_b) for x_b in x_bob.values()])
        score -= sum([k_alice * math.log10(f_a) for f_a in freq_alice.values()])
        score += sum([k_bob * math.log10(f_b) for f_b in freq_bob.values()])
        if score > 7:
            print('Infinity')
        else:
            print(f'{score:.10f}')    
