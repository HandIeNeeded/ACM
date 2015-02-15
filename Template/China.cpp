#define LL long long

LL a[N], m[N]; //x == a[i] (mod m[i]), i = 0, 1, ... , n - 1

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

LL china (LL n, LL *a, LL *m){// i = 0, 1, ... , n - 1
	LL re = 0, i, j, k, M = 1, d, x, y;
	REP(i, n) M *= m[i];
	REP(i, n) {
		exgcd(M / m[i], m[i], d, x, y);
		re = (re + x * M / m[i] * a[i]) % M;
	}
	return (re + M) % M;
}
