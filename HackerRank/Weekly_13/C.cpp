#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;

int dp[105][N];
vector<int> p[105], b[105];

int main() {
	ios :: sync_with_stdio(0);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				int x;
				cin >> x;
				p[i].push_back(x);
			}
		}
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				int x;
				cin >> x;
				b[i].push_back(x);
			}
		}
		REPP(i, 1, 1000) {
			dp[0][i] = i;
		}
		REPP(i, 1, n) {
			REPP(j, 1, 1000) dp[i][j] = INF;
			REP(j, b[i].size()) {
				dp[i][b[i][j]] = min(dp[i][b[i][j]], dp[i - 1][p[i][j]]);
			}
			for (int j = 999; j >= 1; --j) {
				dp[i][j] = min(dp[i][j], dp[i][j + 1]);
			}
			int minn = INF, cnt = 1;
			REPP(j, 1, 1000) {
				if (minn + cnt < dp[i][j]) {
					dp[i][j] = minn + cnt;
					cnt++;
				}
				else {
					minn = dp[i][j];
					cnt = 1;
				}
			}
		}
		//REPP(i, 1, n) {
		//	REPP(j, 1, 10) {
		//		cout << dp[i][j] << ' ';
		//	}
		//	cout << endl;
		//}
		cout << dp[n][1] << endl;
		REPP(i, 1, n) p[i].clear(), b[i].clear();
	}

	return 0;
}

