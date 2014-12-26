#include <iostream>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define inv2 500000004
#define inv3 333333336

using namespace std;

const int N = 100005;
const int MOD = 1e9 + 7;

int dp[N], sum[N];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

void Init() {
	dp[0] = 1, sum[0] = 1;
	dp[1] = 1, sum[1] = 2;
	REPP(i, 2, N - 1) {
		dp[i] = 1LL * dp[i - 1] * sum[i - 2] % MOD;
		add(dp[i], 1LL * dp[i - 1] * (dp[i - 1] + 1) % MOD * inv2 % MOD);
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
		ans = 1LL * ans * inv2 % MOD;
		int tmp = dp[x];
		tmp = 1LL * tmp * (dp[x] + 1) % MOD;
		tmp = 1LL * tmp * (dp[x] + 2) % MOD;
		tmp = 1LL * tmp * inv3 % MOD;
		tmp = 1LL * tmp * inv2 % MOD;
		add(ans, tmp);
	}
	else {
		x >>= 1;
		ans = 1LL * dp[x] * (dp[x] + 1) % MOD;
		ans = 1LL * ans * inv2 % MOD;
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
