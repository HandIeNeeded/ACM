#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1905;
int dp[N][N], cnt[N][N], mx[N];
int n, h, d;

void calc(int height) {
	REPP(i, 1, n) {
		mx[height] = max(mx[height], dp[i][height]);
	}
}

int main() {
	scanf("%d%d%d", &n, &h, &d);
	REPP(i, 1, n) {
		int x, y;
		cin >> x;
		REP(j, x) {
			scanf("%d", &y);
			cnt[i][y]++;
		}
	}
	REPP(i, 1, n) dp[i][h + 1] = 0;
	calc(h + 1);
	for (int i = h; i >= 0; i--) {
		int pre = min(i + d, h + 1);
		REPP(j, 1, n) {
			dp[j][i] = dp[j][i + 1] + cnt[j][i];
			dp[j][i] = max(dp[j][i], mx[pre] + cnt[j][i]);
		}
		calc(i);
	}
	cout << mx[0] << endl;

	return 0;
}

