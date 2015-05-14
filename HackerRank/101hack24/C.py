cost = []

def check(tot):
    step = [0] * n
    person = 1
    for i in range(n):
        if (i == 0 or step[i]):
            if person >= n:
                break
            turn = (tot - step[i] * talk - cost[i]) / talk
            now = step[i]; limit = min(n, turn)
            for j in range(limit):
                now += 1
                step[person] = now
                person += 1
                if person >= n:
                    break
            step[i] = now
    for i in range(n):
        if (step[i] == 0 and i > 0) or step[i] * talk + cost[i] > tot:
            return False
    return True

T = int(raw_input())
for go in range(T):
    n, talk = map(int, raw_input().split())
    cost = map(int, raw_input().split())
    cost.sort(); cost.reverse()
    lo = 0; hi = int(1e15)
    while lo + 1 < hi:
        mid = (lo + hi) / 2
        if check(mid):
            hi = mid
        else :
            lo = mid
    print hi

                
                
