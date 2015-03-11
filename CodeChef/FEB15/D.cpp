#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define LL long long 

using namespace std;

const int N = 1e7 + 5;
int fac[N], m, n;

void init() {
	fac[0] = 1;
	REPP(i, 1, m - 1) fac[i] = 1LL * i * fac[i - 1] % m;
	REPP(i, 1, m - 1) fac[i] = 1LL * i * fac[i] % m;
	REPP(i, 2, m) {
		fac[i] += fac[i - 1];
		if (fac[i] >= m) fac[i] -= m;
	}
}

int calc(long long x) {
	if (m == 2) {
		if (x % 4 == 0 || x % 4 == 3) return 0;
		else return 1;
	}
	int ans = 0;
	x %= 2 * m;
	ans = 1LL * x * (x + 1) % (2 * m);
	ans = 1LL * ans * x % (2 * m);
	return ans / 2;
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("D.in", "r", stdin);
	cin >> n >> m;
	assert(n <= 100000 && n > 0);
	assert(m <= 10000000 && m >= 1);
	init();
	int ans = 0;
	REPP(i, 1, n) {
		long long x;
		cin >> x;
		assert(x <= (LL) 1e18 && x >= 1);
		if (x <= m) {
			ans += fac[x];
			if (ans >= m) ans -= m;
			assert(ans >= 0 && ans < m);
		}
		else {
			ans += fac[m - 1];
			if (ans >= m) ans -= m;
			assert(ans >= 0 && ans < m);
		}
		ans += calc(x);
		if (ans >= m) ans -= m;
		assert(ans >= 0 && ans < m);
	}
	ans %= m;
	assert(ans >= 0 && ans < m);
	cout << ans << endl;

	return 0;
}
