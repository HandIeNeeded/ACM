def go(a, b):
	c = a;
	a = b;
	b = c;

def sort(a, b):
	n = len(a)
	for i in range(n):
		for j in range(n)[i:]:
			if int(a[i][0][b]) > int(a[j][0][b]):
				go(a[i], a[j])
			elif int(a[i][0][b]) == int(a[j][0][b]):
					if (a[i][1] > a[j][1]):
						go(a[i], a[j])
n, m = raw_input().split()
n, m = int(n), int(m)
#print n, m
a = []
for i in range(n):
	tmp = raw_input().split()
	a.append((tmp, i))
#print a
k = int(raw_input())
#print a
sort(a, k)
for i in range(n):
	print(" ".join(a[i][0]))
