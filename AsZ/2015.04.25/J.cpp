#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e4 + 5;
int dp[N], a[N], cnt;
int n, m, k;

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		cnt = 0;
		REPP(i, 1, n) cin >> a[i], cnt += a[i] == 0;
		REPP(i, 1, m) dp[i] = 0;
		dp[0] = 1;
		REPP(i, 1, n) if (a[i] > 0) {
			for (int j = m; j >= 1; j--) {
				if (j >= a[i]) {
					dp[j] += dp[j - a[i]];
					if (dp[j] > k) dp[j] = k;
				}
			}
		}
		REP(i, cnt) dp[m] <<= 1, dp[m] = min(dp[m], k);
		if (dp[m] >= k) cout << "ENOUGH" << endl;
		else cout << dp[m] << endl;
	}

	return 0;
}

