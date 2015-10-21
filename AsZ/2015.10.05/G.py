from decimal import *
import sys
#sys.stdin = open("G.in", "r")
sys.stdin = open("game.in", "r")
sys.stdout = open("game.out", "w")

getcontext().prec = 100

dp, A, B, p, q = [[Decimal(0) for i in xrange(55)] for j in xrange(5)]

n, k = map(int, raw_input().split())
tmp = map(Decimal, raw_input().split())
for i in xrange(len(tmp)):
    p[i + 1] = tmp[i]
    q[i + 1] = Decimal(1) - p[i + 1]

def solve(a, b):
    dp[a], dp[b] = Decimal(1), Decimal(0)
    A[1], B[1] = Decimal(0), dp[1]
    A[2], B[2] = Decimal(1), Decimal(0)
    for i in xrange(2, n - 1):
        A[i + 1] = (A[i] - A[i - 1] * q[i]) / p[i]
        B[i + 1] = (B[i] - B[i - 1] * q[i]) / p[i]
    dp[2] = (dp[n - 1] - B[n - 1]) / A[n - 1]
    for i in xrange(3, n - 1):
        dp[i] = A[i] * dp[2] + B[i]
    key = dp[k]
    return key

key = solve(1, n - 1)

ans = Decimal(0)
dp[n - 1], dp[n] = Decimal(1), Decimal(0)
A[0], B[0] = Decimal(0), dp[n]
A[1], B[1] = Decimal(1), Decimal(0)
for i in xrange(1, n - 1):
    A[i + 1] = (A[i] - A[i - 1] * q[i]) / p[i]
    B[i + 1] = (B[i] - B[i - 1] * q[i]) / p[i]
dp[1] = (dp[n - 1] - B[n - 1]) / A[n - 1]
ans += key * dp[1]

dp[1], dp[n] = Decimal(1), Decimal(0)
A[n], B[n] = Decimal(0), dp[n]
A[n - 1], B[n - 1] = Decimal(1), Decimal(0)
for i in xrange(n - 1, 1, -1):
    A[i - 1] = (A[i] - A[i + 1] * p[i]) / q[i]
    B[i - 1] = (B[i] - B[i + 1] * p[i]) / q[i]
dp[n - 1] = (dp[1] - B[1]) / A[1]
ans += (Decimal(1) - key) * dp[n - 1]

print float(ans)
