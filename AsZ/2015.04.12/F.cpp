#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e6 + 5;
const int MO = 1e9 + 7;
int fac[N] = {1};

int pow_mod(int a, int b = MO - 2) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1LL * ans * a % MO;
		b >>= 1;
		a = 1LL * a * a % MO;
	}
	return ans;
}

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int dp[200][200];

int work() {
	dp[0][0] = 1;
	int n = 100;
	REPP(i, 1, n) {
		REPP(j, 1, n) {
			dp[i][j] = dp[i - 1][j - 1];
			add(dp[i][j], 1LL * (j - 1) * dp[i - 1][j]);
		}
	}
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	int t, ca = 1;
	work();
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int ans = (1LL * k * (k - 1) >> 1) % MO;
		ans = pow_mod(ans, n - k);
		//for (int i = m; i > m - k; i--) {
		//	ans = 1LL * ans * i % MO;
		//}
		cout << "Case #" << ca++ << ": " << ans << endl;
		cout << "std : " << dp[n][k] << endl;
	}

	return 0;
}

