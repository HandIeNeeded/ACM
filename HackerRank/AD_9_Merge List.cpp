#include <bits/stdc++.h> 

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MOD = (int) 1e9 + 7;
const int N = 105;
int dp[N][N];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		MST(dp, 0);
		dp[0][0] = 1;
		for (int sum = 1; sum <= n + m; sum++) {
			REPP(i, 0, min(n, sum)) {
				if (i < sum) {
					add(dp[i][sum - i], dp[i][sum - i - 1]);
				}
				if (i > 0) add(dp[i][sum - i], dp[i - 1][sum - i]);
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
