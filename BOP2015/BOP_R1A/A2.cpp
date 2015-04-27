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

const int N = 5005;
vector<int> edge[N];
int col[N], dp[N];

void dfs(int x, int p) {
	int ans = 0, dec = 0;
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != p) {
			dfs(y, x);
			if (col[x] == col[y]) {
				dec++;
			}
			ans += dp[y];
		}
	}
	dp[x] = ans - dec + 1;
}

int main() {
	int t, ca = 1;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		REPP(i, 1, n) edge[i].clear(), col[i] = 0;
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int q;
		scanf("%d", &q);
		printf("Case #%d:\n", ca++);
		while (q--) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				dfs(1, 0);
				printf("%d\n", dp[1]);
			}
			else {
				int x, y;
				scanf("%d%d", &x, &y);
				col[x] = y;
			}
		}
	}

	return 0;
}

