#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e7 + 5;
int p[N], vis[N], dp[N], tot;

void prime() {
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) p[tot++] = i, dp[i] = 1;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			dp[i * p[j]] = dp[i];
			if (i % p[j] == 0) break;
			else {
				dp[i * p[j]]++;
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int t, ca = 1;
	int left, right, k;
	prime();
	cin >> t;
	while (t--) {
		cin >> left >> right >> k;
		int cnt = 0;
		REPP(i, left, right) {
			if (dp[i] == k) {
				cnt++;
			}
		}
		cout << "Case #" << ca++ << ": " << cnt << endl;
	}

	return 0;
}

