import sys

sys.stdin = open("bipartite.in", "r");
sys.stdout = open("bipartite.out", "w");

n = 105
MO = 175781251;

binom = [[0] * n for _ in xrange(n)]
for i in xrange(n):
    binom[i][0] = 1
    for j in xrange(1, i + 1):
        binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j]

a = [0] * n
for i in xrange(n):
    for j in xrange(i + 1):
        a[i] += binom[i][j] * pow(3, j * (i - j))
b = [None] * n
for i in xrange(n):
    b[i] = a[i]
    for j in xrange(1, i):
        b[i] -= binom[i - 1][j - 1] * b[j] * a[i - j]
c = [0] * n
c[0] = 1
for i in xrange(1, n):
    for j in xrange(1, i + 1):
        c[i] += binom[i - 1][j - 1] * b[j] / 2 * c[i - j]

while 1:
    n = int(raw_input())
    if (n == 0):
        break
    print c[n] % MO

