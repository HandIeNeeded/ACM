import sys

sys.stdin = open("nim.in", "r")
#sys.stdout = open("nim.out", "w")

n = int(raw_input())

start, step, now = 2, 3, 4
while start < n:
    cnt = 2
    if step == now:
        cnt -= 1
        now *= 2
    for i in range(cnt):
        start += step
        if start >= n:
            break
    if start >= n:
        break
    step += 1

if start == n:
    print "LOSE"
else:
    print "WIN"


