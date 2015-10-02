import sys
sys.stdin = open("in", "r")
while 1:
    try:
        a = raw_input()
        n, m, k = map(int, a.split())
        k = k / 2
        mx = min(n, k - 1)
        n, m = n + 1, m + 1
        ans = 0
        for i in xrange(1, mx + 1):
            upper = min(m - 1, k - i)
            ans += (n - i) * (upper * m - upper * (upper + 1) / 2)
        print ans
    except:
        exit(0)

