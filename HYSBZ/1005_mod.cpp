#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
const int MO = 1e9 + 7;
int fac[N] = {1}, inv[N] = {1}, a[N];

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
	int n;
	cin >> n;
	REPP(i, 1, n) cin >> a[i];
	REPP(i, 1, N - 1) {
		fac[i] = 1LL * i * fac[i - 1] % MO;
		inv[i] = pow_mod(fac[i], MO - 2);
	}
	int cnt = 0, sum = 0, ans;
	bool bad = 0;
	REPP(i, 1, n) {
		if (a[i] >= 0) {
			if (a[i] == 0) {
				bad = 1;
				break;
			}
			sum += a[i];
			cnt++;
		}
	}
	if (cnt > n - 2 || sum > 2 * n - 2) bad = 1;
	if (bad) {
		cout << 0 << endl;
	}
	else {
		sum -= cnt;
		ans = C(n - 2, sum);
		ans = 1LL * ans * fac[sum];
		REPP(i, 1, n) {
			if (a[i] >= 0) {
				ans = 1LL * ans * inv[a[i] - 1] % MO;
			}
		}
		ans = 1LL * ans * pow_mod(n - cnt, n - 2 - sum);
		cout << ans << endl;
	}

	return 0;
}

