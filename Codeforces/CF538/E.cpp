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
struct op{
	int a, b, c;
}dp[N];

op operator + (const op &x, const op &y) {
	op res;
	res.c = x.c + y.c;
	res.a = max(y.c + x.a, x.c + y.a);
	res.b = x.b + y.b;
	return res;
}

op operator - (const op &x, const op &y) {
	op res;
	res.c = x.c + y.c;
	res.a = x.a + y.a - 1;
	res.b = min(x.b, y.b);
	return res;
}

vector<int> edge[N];

void dfs1(int x, int p, int dep) {
	int flag = 0;
	dp[x] = {-1, -1, -1};
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != p) {
			flag = 1;
			dfs1(y, x, dep ^ 1);
			if (dp[x].a < 0) {
				dp[x] = dp[y];
			}
			else {
				if (dep == 0) dp[x] = dp[x] + dp[y];
				else dp[x] = dp[x] - dp[y];
			}
		}
	}
	if (!flag) dp[x] = {1, 1, 1};
}

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs1(1, 0, 0);
	cout << dp[1].a << ' ' << dp[1].b << endl;

	return 0;
}

