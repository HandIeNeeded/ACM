fib = [0 for i in range(1005)]

fib[0], fib[1], fib[2] = 0, 1, 1
for i in xrange(3, 1001):
    fib[i] = fib[i - 1] + fib[i - 2]

t = int(raw_input())

#for i in range(10):
#    print fib[i]


def find(m):
    for i in range(1001):
        if fib[i] >= m:
            if fib[i] == m:
                return i
            return -i

while t:
    n, m = map(int, raw_input().split());
    if m <= 2:
        print 0
        t -= 1
        continue
    pos = find(m)
    ans = 0
    if pos >= 0:
        ans = fib[pos - 2]
    else:
        pos = -pos
        while pos >= 0:
            if m > fib[pos]:
                m -= fib[pos]
            elif m == fib[pos]:
                ans = fib[pos]
                break
            pos -= 1
    print ans
    t -= 1
    
