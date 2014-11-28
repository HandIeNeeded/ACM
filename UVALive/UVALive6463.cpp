#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int)(a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 205;
const int MOD = 1e9 + 7;
const int INV = 5e8 + 4;

int c[N][N], fac[N] = {1};
int dp[N][N];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int qp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MOD;
		y >>= 1;
		x = 1LL * x * x % MOD;
	}
	return ans;
}

void Init() {
	dp[0][0] = 1;
	REPP(i, 1, 200) {
		REPP(j, 0, i) {
			if (j == 0) dp[i][j] = c[i][j];
			else {
				dp[i][j] = dp[i][j - 1];
				add(dp[i][j], c[i][j]);
			}
		}
	}
}

int go(int sum, int lo, int hi) {
	if (lo > hi) return 0;
	int ans = dp[sum][hi];
	if (lo) add(ans, MOD - dp[sum][lo - 1]);
	return ans;
}

int main() {
	ios :: sync_with_stdio(0);
	// freopen("cf.in", "r", stdin);

	REPP(i, 0, 200) {
		c[i][0] = c[i][i] = 1;
		REPP(j, 1, i - 1) {
			c[i][j] = c[i - 1][j];
			add(c[i][j], c[i - 1][j - 1]);
		}
	}
	REPP(i, 1, 200) fac[i] = 1LL * fac[i - 1] * i % MOD;
	Init();

	int t;
	int n, m, p, q;
	cin >> t;
	while (t--) {
		cin >> n >> m >> p >> q;
		int ans = 0;
		REPP(i, 0, p) {
			REPP(j, 0, p) {
				if (2 * i + j > m || 2 * j + i > n || 2 * i + 2 * j > p) {
					break;
				}
				int tmp;
				tmp = 1LL * c[n][i] * c[m][2 * i] % MOD;
				tmp = 1LL * c[n - i][2 * j] * c[m - 2 * i][j] % MOD * tmp % MOD;
				tmp = 1LL * fac[2 * i] * tmp % MOD;
				tmp = 1LL * tmp * qp(INV, i) % MOD;
				tmp = 1LL * fac[2 * j] * tmp % MOD;
				tmp = 1LL * tmp * qp(INV, j) % MOD;
				int row = n - i - 2 * j, col = m - j - 2 * i;
				int heavy = p - 2 * i - 2 * j, light = q;
				int sum = heavy + light;
				sum = min(sum, row);
				sum = min(sum, col);
				//cout << "haha" << ' ' << i << ' '<< j << ' ' << tmp << endl;
				REPP(k, 0, sum) {
					int hi = min(k, heavy), lo = max(0, k - light);
					int cnt = 1LL * c[row][k] * c[col][k] % MOD * tmp % MOD;
					cnt = 1LL * cnt * go(k, lo, hi) % MOD;
					cnt = 1LL * cnt * fac[k] % MOD;
					add(ans, cnt);
					//cout << hi << ' ' << lo << ' ' << ans << endl;
				}
			}
		}
		add(ans, MOD - 1);
		cout << ans << endl;
	}

	return 0;
}