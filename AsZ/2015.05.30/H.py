import sys

#sys.stdin = open("poker.in", "r")
#sys.stdout = open("poker.out", "w")

comb = [[0 for i in range(405)] for j in range(25)]

def Comb(a, b):
    if a < 0 or b < 0 or a > b:
        return 0
    else :
        return comb[a][b]

for i in range(405):
    comb[0][i] = 1;
    if i <= 20:
        comb[i][i] = 1
    for j in range(1, min(i - 1, 20) + 1):
        comb[j][i] = comb[j][i - 1] + comb[j - 1][i - 1]
        #print str(i) + " " + str(j) + " " + str(comb[j][i])

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        c = b
        b = a % b
        a = c
    return a

first = 0
while 1:
    r, s, d, c = map(int, raw_input().split())
    if r == 0 and s == 0:
        break
    if first:
        print ""
        first = first + 1
    tot = Comb(d, r * s)
    ansa, ansb = 0, 0
    for i in range(c, d + 1):
        if (i - c + 1) % 2:
            ansa = ansa + pow(s, i) * (r - i + 1) * Comb(d - i, r * s - i) / Comb(i, d)
        else :
            ansa = ansa - pow(s, i) * (r - i + 1) * Comb(d - i, r * s - i) / Comb(i, d)
    for i in range(1, s + 1):
        for j in range(c, d + 1):
            if (i + j - c + 1) % 2:
                if i * j <= d:
                    ansb = ansb - Comb(i, s) * pow(Comb(j, r), i) * Comb(d - i * j, r * s - i * j) / Comb(i * j, d)
            else :
                if i * j <= d:
                    ansb = ansb + Comb(i, s) * pow(Comb(j, r), i) * Comb(d - i * j, r * s - i * j) / Comb(i * j, d)
    
    print ansa, ansb, tot
    d = gcd(tot, ansa)
    print str(ansa / d) + "/" + str(tot / d)
    d = gcd(tot, ansb)
    print str(ansb / d) + "/" + str(tot / d)
