#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e6 + 5;
const int MO = 1e9 + 7;

int fac[N] = {1}, inv[N] = {1};

int pow_mod(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

int C(int x, int y) {
	return 1LL * fac[x] * inv[y] % MO * inv[x - y] % MO;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	REPP(i, 1, n) {
		fac[i] = 1LL * i * fac[i - 1] % MO;
		inv[i] = pow_mod(fac[i], MO - 2);
	}
	int mul = C(n, n - k);
	int ans = 0, now = n - k, turn = 0;
	REPP(i, 1, n - k) {
		if (turn) {
			ans -= 1LL * C(n - k, now) * pow_mod(now, n - 2) % MO;
		}
		else ans += 1LL * C(n - k, now) * pow_mod(now, n - 2) % MO;
		if (ans >= MO) ans -= MO;
		if (ans < 0) ans += MO;
		now--;
		turn ^= 1;
	}
	cout << 1LL * ans * mul % MO << endl;

	return 0;
}

