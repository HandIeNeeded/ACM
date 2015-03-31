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

const int N = 605;
const int INF = 0x3f3f3f3f;
int dp[N][N], n;
vector<int> num;

struct Enemy{
	int x, y, h;
}q[N];

int solve(int x, int y) {
	if (x > y) return 0;
	if (dp[x][y] != INF) return dp[x][y];
	int mx = -1;
	REPP(i, 1, n) {
		if (q[i].x >= num[x] && q[i].y <= num[y] && q[i].h > mx) {
			mx = q[i].h;
		}
	}
	if (mx < 0) return dp[x][y] = 0;
	else {
		REPP(i, x, y) {
			dp[x][y] = min(dp[x][y], solve(x, i - 1) + mx + solve(i + 1, y));
		}
		return dp[x][y];
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		num.clear();
		REPP(i, 1, n) {
			int x, y, h;
			cin >> x >> y >> h;
			q[i] = {x, y, h};
			num.push_back(x), num.push_back(y);
		}
		sort(num.begin(), num.end());
		int m = unique(num.begin(), num.end()) - num.begin();
		REP(i, m) {
			REP(j, m) {
				dp[i][j] = INF;
			}
		}
		cout << solve(0, m - 1) << endl;
	}
	
	return 0;
}

