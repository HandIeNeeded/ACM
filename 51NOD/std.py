n = int(raw_input())
#print n
res = 0
fac = 1
for i in xrange(1, n + 1):
    fac = fac * i
for i in xrange(1, n + 1):
    if i * i > n:
        break
    if n % i == 0:
        a, b = i, n / i
        ans = 1
        for x in xrange(1, a + 1):
            for y in xrange(b):
                ans = ans * (x + y)
        tmp = fac / ans
        res += tmp
        if a != b:
            res += tmp

print res % 10007
