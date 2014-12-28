#include <iostream>
#include <cstring>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 105;
const int MOD = 1e9 + 7;

int c[N][N], dp[N][N], a[N];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	ios :: sync_with_stdio(0);

	REPP(i, 0, 100) {
		c[i][i] = c[i][0] = 1;
		REPP(j, 1, i - 1) {
			c[i][j] = c[i - 1][j];
			add(c[i][j], c[i - 1][j - 1]);
		}
	}

	int n;
	while (cin >> n) {
		REPP(i, 1, n) {
			cin >> a[i];
		}
		REPP(i, 1, n) {
			dp[i][i] = 1;
			if (i + 1 <= n) dp[i][i + 1] = 2;
		}
		REPP(j, 2, n - 1) {
			REPP(i, 1, n) if (i + j <= n) {
				int k = i + j;
				REPP(mid, i, k) {
					if (mid == i) {
						add(dp[i][k], dp[mid + 1][k]);
					}
					else if (mid == k) {
						add(dp[i][k], dp[i][mid - 1]);
					}
					else {
						if (a[mid - 1] != a[mid + 1]) continue;
						else {
							add(dp[i][k], 1LL * dp[i][mid - 1] * dp[mid + 1][k] % MOD * c[j][mid - i] % MOD);
						}
					}
				}
			}
		}
		cout << dp[1][n] << endl;
		MST(dp, 0);
	}
	return 0;
}

