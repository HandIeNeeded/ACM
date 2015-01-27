#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 30005;
const int INF = 0x3f3f3f3f;

int dp[N][501], cnt[N];

void toMax(int &x, int y) {
	if (x == INF || x < y) {
		x = y;
	}
}

int main() {
	ios :: sync_with_stdio(0);

	int n, d;
	cin >> n >> d;
	REP(i, n) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	MST(dp, 0x3f);
	dp[d][250] = cnt[d];
	int ans = 0;
	REPP(i, 0, 30000 - 1) {
		for (int j = 0; j <= 500; j++) if (d + j - 250 > 0) {
			if (dp[i][j] < INF) {
				int now = d + j - 250;
				REPP(k, -1, 1) {
					int step = now + k;
					if (step > 0 && i + step <= 30000) {
						int pos = i + step;
						toMax(dp[pos][step - d + 250], dp[i][j] + cnt[pos]);
					}
				}
			}
		}
	}
	REPP(i, 1, 30000) {
		REP(j, 501) if (dp[i][j] < INF) {
			toMax(ans, dp[i][j]);
		}
	}
	cout << ans << endl;

	return 0;
}
