#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
const int MOD = 10007;

int dp[N], a[N];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	ios :: sync_with_stdio(0);

	int n, m;

	while (cin >> n >> m) {
		REPP(i, 1, m) {
			cin >> a[i];
		}
		dp[0] = 1;
		REPP(i, 1, m) {
			REPP(j, 0, n) {
				if (j + a[i] <= n) add(dp[j + a[i]], dp[j]);
			}
		}
		cout << dp[n] << endl;
		MST(dp, 0);
	}

	return 0;
}


