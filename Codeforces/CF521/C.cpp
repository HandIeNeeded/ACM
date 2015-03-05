#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
const int MO = 1e9 + 7;

int fac[N], inv[N];

int pow_mod(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * x * ans % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

int C(int x, int y) {
	if (x < 0 || y < 0 || x < y) return 0;
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	fac[0] = inv[0] = 1;
	REPP(i, 1, n) {
		fac[i] = 1LL * i * fac[i - 1] % MO;
		inv[i] = pow_mod(fac[i], MO - 2);
	}
	int ans = 0, sum = 0, mul = 1;
	REP(i, n - 1) add(sum, s[i] - '0');
	for (int i = 0, j = n - 2; i < n - 1; i++, j--) {
		add(ans, 1LL * sum * mul % MO * C(n - 2 - i, k - 1) % MO);
		add(sum, MO - s[j] + 48);
		mul = 10LL * mul % MO;
	}
	mul = 1;
	for (int i = n - 1; i >= 0; i--) {
		add(ans, 1LL * (s[i] - '0') * mul % MO * C(i, k) % MO);
		mul = 10LL * mul % MO;
	}
	cout << ans << endl;

	return 0;
}

