import sys

D = [0] * 205
D[0], D[1], D[2] = 1, 0, 1
for i in range(3, 201):
    D[i] = i * D[i - 1]
    if i % 2:
        D[i] -= 1
    else:
        D[i] += 1

sys.stdin = open("derangements.in", "r")
sys.stdout = open("derangements.out", "w")

n = int(raw_input())
comb, ans = 1, 0
ans += pow(2, n) * D[n]
for i in range(1, n + 1):
    comb = comb * (n + 1 - i) / i
    ans += comb * pow(2, n - i) * D[n - i]
print ans
