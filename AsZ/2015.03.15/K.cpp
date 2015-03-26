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

const int N = 2e5 + 5;

int dp[N][10];
pair<int, int> p[N];

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		REPP(i, 1, n) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p + 1, p + n + 1);
		REP(i, k + 1) dp[n + 1][i] = 0;
		for (int i = n; i >= 1; i--) {
			dp[i][0] = max(dp[i + 1][0], p[i].first - p[i].second);
		}
		REPP(j, 1, k) {
			for (int i = n; i >= 1; i--) {
				dp[i][j] = max(dp[i + 1][j], min(dp[i + 1][j - 1] - p[i].second, p[i].first - p[i].second));
			}
		}
		assert(dp[1][k] >= 0);
		cout << dp[1][k] << endl;
	}

	return 0;
}

