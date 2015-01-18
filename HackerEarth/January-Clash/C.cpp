#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MOD = 1e9 + 7;

int cnt[10], inv[10];

long long pow_mod(long long x, long long y) {
	long long ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return ans;
}

void init() {
	REP(i, 1 << 9) {
		int tmp = 1, now = 0;
		REP(j, 9) {
			if (i & (1 << j)) {
				now++;
				tmp *= (j + 1);
			}
		}
		int rt = (int) sqrt(tmp + 0.5);
		if (rt * rt == tmp) {
			cout << "hehe" << i << ' ' << tmp << endl;
			cnt[now]++;
		}
	}
	REP(i, 10) {
		inv[i] = pow_mod(i, MOD - 2);
	}
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int C(long long n, int k) {
	int ans = 1;
	for (int i = 0; i < k; i ++) {
		ans = 1LL * ans * ((n - i) % MOD) % MOD;
		ans = 1LL * ans * inv[k - i] % MOD;
	}
	return ans;
}

int calc(long long n) {
	int ans = pow_mod(10, n);
	int tmp = pow_mod(9, n) - 1;
	tmp = 1LL * tmp * 9 % MOD;
	tmp = 1LL * tmp * inv[8] % MOD;
	add(ans, MOD - tmp);
	REPP(i, 0, 9) {
		if (i > n) break;
		long long sum = (n - i) / 2 + 10;
		add(ans, 1LL * cnt[i] * C(sum - 1, 9) % MOD);
	}
	return ans;
}

int ans[10005];

int main() {
	ios :: sync_with_stdio(0);
	int t;
	long long n;
	init();
	REP(i, 10) {
		cout << cnt[i] << ' ' << inv[i] << endl;
	}
	cout << endl;
	REPP(i, 1, 10000) ans[i] = calc(i), add(ans[i], ans[i - 1]);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << ans[n] << endl;
	}

	return 0;
}
