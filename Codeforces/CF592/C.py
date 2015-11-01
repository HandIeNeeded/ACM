L, a, b = map(int, raw_input().split())

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

if a == b:
    print "1/1"
else :
    c = a * b / gcd(a, b)
    k = L / c
    d = L % c
    ans = k * min(a, b)
    if d >= min(a, b):
        ans += min(a, b) - 1
    else:
        ans += d
    x = gcd(L, ans)
    #print L, ans, x
    print str(ans / x) + "/" + str(L / x)

    



