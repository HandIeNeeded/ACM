#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MOD = 10000;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int pow_mod(int x, int y) {
	x %= MOD;
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MOD;
		y >>= 1;
		x = 1LL * x * x % MOD;
	}
	return ans;
}

int cal(int n) {
	long long tmp = 1;
	int ans = 0, now = 1;
	while (10LL * tmp <= n) {
		add(ans, 1LL * now * (10 * tmp - tmp) % MOD);
		now++;
		tmp = 10 * tmp;
	}
	add(ans, 1LL * now * (n - tmp + 1) % MOD);
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	int n;
	int ca = 1;
	while (cin >> n, n) {
		int ans = 0, pw = pow_mod(2, n - 1);
		add(ans, 1LL * n * pw % MOD);
		add(ans, pw * 2 % MOD);
		add(ans, (3LL * n - 4) % MOD);
		add(ans, 1LL * (pw + 1) * cal(n) % MOD);
		cout << "Case " << ca++ << ": ";
		cout << ans << endl;
	}

	return 0;
}

