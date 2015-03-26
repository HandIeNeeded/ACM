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
int dp[N], a[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	REPP(i, 1, n) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	if (2 * k >= n) {
		cout << a[n] << endl;
		return 0;
	}
	else {
		int ans = 0;
		REPP(i, 1, n) {
			int j = max(0, i - k);
			dp[i] = max(dp[i - 1], a[i] - a[j]);
			ans = max(ans, dp[j] + a[i] - a[j]);
		}
		REPP(i, 1, n) {
			int j = max(0, i - 2 * k);
			ans = max(ans, a[i] - a[j]);
		}
		cout << ans << endl;
	}

	return 0;
}

