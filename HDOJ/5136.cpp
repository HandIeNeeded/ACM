#include <cstring>
#include <iostream>
#include <algorithm>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 100005;
const int MOD = 1e9 + 7;

int dp[N], sum[N], fac[N] = {1}, inv[N] = {1};

int pow_mod(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MOD;
		a = 1LL * a * a % MOD;
		b >>= 1; 
	}
	return ans;
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

void Init() {
	REPP(i, 1, N - 1) fac[i] = 1LL * fac[i - 1] * i % MOD;
	REPP(i, 1, N - 1) inv[i] = pow_mod(fac[i], MOD - 2);
	dp[0] = 1, sum[0] = 1;
	dp[1] = 1, sum[1] = 2;
	REPP(i, 2, N - 1) {
		dp[i] = 1LL * dp[i - 1] * sum[i - 2] % MOD;
		add(dp[i], 1LL * dp[i - 1] * (dp[i - 1] + 1) % MOD * inv[2] % MOD);
		sum[i] = sum[i - 1];
		add(sum[i], dp[i]);
	}
}

int solve(int x) {
	int ans = 0;
	if (x == 1) return 1;
	if (x & 1) {
		x >>= 1;
		ans = 1LL * dp[x] * (dp[x] + 1) % MOD * sum[x - 1] % MOD;
		ans = 1LL * ans * inv[2] % MOD;
		int tmp = dp[x];
		tmp = 1LL * tmp * (dp[x] + 1) % MOD;
		tmp = 1LL * tmp * (dp[x] + 2) % MOD;
		tmp = 1LL * tmp * inv[3] % MOD;
		add(ans, tmp);
	}
	else {
		x >>= 1;
		ans = 1LL * dp[x] * (dp[x] + 1) % MOD;
		ans = 1LL * ans * inv[2] % MOD;
	}
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);

	int n;
	Init();
	while (cin >> n, n) {
		cout << solve(n) << endl;
	}
	
	return 0;
}

