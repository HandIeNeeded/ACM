#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 42;

long long dp[N][N][N][11];

long long tomax(long long a, long long b, long long c) {
	return max(a, max(b, c));
}

int main() {
	ios :: sync_with_stdio(0);

	string a, b, c;
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int x = a.size(), y = b.size(), z = c.size();
		REPP(i, 1, x) REPP(j, 1, y) REPP(k, 1, z) REPP(t, 0, 10) dp[i][j][k][t] = 0;
		REPP(i, 1, x) {
			REPP(j, 1, y) {
				REPP(k, 1, z) {
					if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
						REPP(t, 0, 9) {
							if (t + '0' == a[i - 1]) {
								dp[i][j][k][t] = dp[i - 1][j - 1][k - 1][10] + 1;
							}
							else {
								dp[i][j][k][t] = tomax(dp[i - 1][j][k][t], dp[i][j - 1][k][t], dp[i][j][k - 1][t]);
							}
							dp[i][j][k][10] += dp[i][j][k][t];
						}
					}
					else {
						REPP(t, 0, 9) {
							dp[i][j][k][t] = tomax(dp[i - 1][j][k][t], dp[i][j - 1][k][t], dp[i][j][k - 1][t]);
							dp[i][j][k][10] += dp[i][j][k][t];
						}
					}
				}
			}
		}
		cout << dp[x][y][z][10] << endl;
	}
	return 0;
}

