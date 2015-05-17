a = raw_input().split()
b = set(a)
n = int(raw_input())
c = raw_input().split()
c = set(c)
bad = False

for x in b:
    if x not in c:
        bad = True
        break
if bad:
    print "Misspell"
else:
    print "Correct"

