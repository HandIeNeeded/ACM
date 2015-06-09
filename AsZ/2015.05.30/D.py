import sys
import math

sys.stdin = open("discuss.in", "r")
sys.stdout = open("discuss.out", "w")

z = int(raw_input())
ans = z
div = [0] * 205

def calc(x, y):
    ans = 1
    for i in range(1, y + 1):
        ans = ans * (x + 1 - i)
    ans = ans / div[y]
    return ans

def pow_mod(a, b):
    ans = 1
    while b: 
        if b % 2:
            ans = ans * a
        a = a * a
        b = b / 2
    return ans


def getstart(a, b):
    l, r = 0, 10**(min(50, 400 / (a - 1)))
    while l + 1 < r:
        mid = (l + r) / 2
        if pow(mid, a) < b:
            l = mid
        else :
            r = mid
    return l
    

def get(a, b):
    #print getstart(a, b * div[a])
    l = max(2 * a - 1, getstart(a, b * div[a]))
    r = l + a + 5
    #print a, l, r
    while l + 1 < r:
        mid = (l + r) / 2
        if calc(mid, a) < b:
            l = mid
        else :
            r = mid
    return r

div[0] = 1
for i in range(1, 201):
    div[i] = div[i - 1] * i

for i in range(2, 201):
    y = get(i, z)
    if calc(y, i) == z:
        ans = y
print ans
