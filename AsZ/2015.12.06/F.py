pw = [1 for i in xrange(100)]
dw = [1 for i in xrange(100)]

def good(d, b, dep):
    return d % pw[dep] == b

answer = [[] for i in xrange(100)]

cnt = 0

def dfs(d, b, dep, limit):
    global cnt
    if cnt == 10000:
        return
    if dep == limit:
        if d >= dw[limit - 1] and good(d, b, limit):
            answer[limit].append(d)
            cnt += 1
        return 
    else:
        dfs(d * 10, b * 2, dep + 1, limit)
        dfs(d * 10 + 1, b * 2 + 1, dep + 1, limit)

for i in xrange(1, 90):
    pw[i] = pw[i - 1] * 2
    dw[i] = dw[i - 1] * 10
    dfs(0, 0, 0, i)
    print("Length: " + str(i))
    print answer[i]
    print("Answer count: " + str(len(answer[i])))


    
