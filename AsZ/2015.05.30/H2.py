import sys

sys.stdin = open("poker.in", "r")
sys.stdout = open("poker.out", "w")

f = [[0 for i in range(25)] for j in range(25)]
g = [[[0 for i in range(25)] for j in range(25)] for k in range(25)]
comb = [[0 for i in range(25)] for j in range(405)]

def gcd(a, b):
	if a < b:
		a, b = b, a
	while b:
		c = b; b = a % b; a = c
	return a

def Comb(a, b):
	if a < 0 or b < 0 or a < b:
		return 0
	else :
		return comb[a][b]

for i in range(401):
	comb[i][0] = 1
	if i <= 20:
		comb[i][i] = 1
	for j in range(min(i, 21)):
		comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1]
		#print i, j, comb[i][j]


first = 0
while True:
	r, s, d, c = map(int, raw_input().split())
	if r == 0 and s == 0:
		break
	if first:
		print ""
	first = first + 1
	
	#straight O(N^3)state  O(N^4) card number straight
	if r < c:
		print '0/1'
	else :
		for i in range(d + 1):
			for j in range(r + 1):
				for k in range(c):
					g[i][j][k] = 0
		g[0][0][0] = 1
		for i in range(d):
			for j in range(r):
				for k in range(c):
					for t in range(s + 1):
						if t > 0:
							if i + t <= d:
								g[i + t][j + 1][k + 1] = g[i + t][j + 1][k + 1] + g[i][j][k] * Comb(s, t)
						else :
							if i + t <= d:
								g[i + t][j + 1][0] = g[i + t][j + 1][0] + g[i][j][k]
		ans = tot = Comb(r * s, d)
		for i in range(r + 1):
			for j in range(c):
				ans -= g[d][i][j]
		dd = gcd(ans, tot)
		#print ans, tot
		print str(ans / dd) + "/" + str(tot / dd)

	#flush O(N^2)state  O(N^3) card suit
	for i in range(d + 1):
		for j in range(s + 1):
			f[i][j] = 0
	f[0][0] = 1
	for i in range(d):
		for j in range(s):
			limit = min(c, r + 1)
			for k in range(limit):
				if i + k <= d:
					f[i + k][j + 1] = f[i + k][j + 1] + f[i][j] * Comb(r, k)
	ans = tot = Comb(r * s, d)
	for i in range(s + 1):
		ans = ans - f[d][i]
	dd = gcd(ans, tot)
	#print ans, tot
	print str(ans / dd) + "/" + str(tot / dd)
