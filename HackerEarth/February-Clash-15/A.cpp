#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e4 + 5;
const int MO = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int dp[N][10];

int main() {
	ios :: sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		dp[1][0] = 1, dp[1][1] = 0;
		REPP(i, 2, n) {
			REP(j, m) {
				add(dp[i][0], dp[i - 1][j]);
				if (j + 1 < m) add(dp[i][j + 1], dp[i - 1][j]);
			}
			REP(j, m) dp[i - 1][j] = 0;
		}
		int ans = 0;
		REP(i, m) add(ans, dp[n][i]);
		REP(i, m) dp[n][i] = 0;
		cout << ans << endl;
	}

	return 0;
}


