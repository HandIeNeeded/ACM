#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

#define LL long long

const int N = 20;

LL a[N], mod[N]; //x == a[i] (mod mod[i]), i = 0, 1, ... , n - 1

void exgcd( LL a, LL b, LL &d, LL &x, LL &y){
	if (!b) d = a, x = 1, y = 0;
	else exgcd(b, a % b, d, y, x), y -= (a / b) * x;
}

LL china (LL n, LL *a, LL *mod){// i = 0, 1, ... , n - 1
	LL re = 0, M = 1, d, x, y;
	REP(i, n) M *= mod[i];
	REP(i, n) {
		exgcd(M / mod[i], mod[i], d, x, y);
		re = (re + x * M / mod[i] * a[i]) % M;
	}
	return (re + M) % M;
}

int pow_mod(int x, int y, int MO) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

int calc(int x, int p) {
	int ans = 0;
	while (x) {
		ans += x / p;
		x /= p;
	}
	return ans;
}

int getfac(int n, int p) {
	if (n < p) {
		int ans = 1;
		REPP(i, 1, n) {
			ans = ans * i % p;
		}
		return ans;
	}
	else {
		int k = n / p, b = n % p;
		int ans = 1;
		ans = getfac(b, p) * getfac(k, p) % p;
		if (k & 1) ans = p - ans;
		return ans;
	}
}

void get(int n, int r, int p, int id) {
	if (calc(n, p) > calc(r, p) + calc(n - r, p)) {
		a[id] = 0;
		return ;
	}
	else {
		int inv = getfac(r, p);
		int fac = getfac(n, p);
		fac = fac * pow_mod(getfac(n - r, p), p - 2, p) % p;
		a[id] = fac * pow_mod(inv, p - 2, p) % p;
		return ;
	}
}

int main() {
	ios :: sync_with_stdio(0);

	int t, n, r, m;
	cin >> t;
	while (t--) {
		cin >> n >> r >> m;
		int tot = 0;
		REPP(i, 2, 50) {
			if (m % i == 0) {
				mod[tot] = i;
				get(n, r, i, tot);
				m /= i;
				tot++;
			}
		}
		cout << china(tot, a, mod) << endl;
	}

	return 0;
}

