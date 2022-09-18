if __name__ == '__main__':
    k = int(input())
    t = int(input())
    for test in range(t):
        n = int(input())
        me = 0
        friend = 0
        diff = 0
        assignment = []
        for i in range(n, 0, -1):
            if diff <= 0:
                me += i ** k
                assignment.append('1')
            else:
                friend += i ** k
                assignment.append('0')
            diff = me - friend
        print(abs(diff))
        print(''.join(reversed(assignment)))