s = raw_input()
n = int(raw_input())

#print s, n
length = len(s)

ans = eval(s)
now = int(s[0])

for i in xrange(1, length, 2):
    if s[i] == '+':
        now = now + int(s[i + 1]) - int('0')
    else:
        now = now * (int(s[i + 1], 10) - int('0', 10))

if ans == n and now == n:
    print 'U'
elif ans == n and now != n:
    print 'M'
elif ans != n and now == n:
    print 'L'
else:
    print 'I'


    

