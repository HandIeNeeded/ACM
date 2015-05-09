#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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
#define LL long long

using namespace std;

const int N = 1e5 + 5;
int a[N], cnt[N], n, s;
vector<int> edge[N];
LL sum[N], dep[N];

void dfs(int x, int p) {
	dep[x] = 0;
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != p) {
			dfs(y, x);
			dep[x] = max(dep[y] + 1, dep[x]);
			sum[x] += sum[y];
		}
	}
	sum[x] += a[x];
}
int main() {
	//freopen("A.in", "r", stdin);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		cin >> n >> s;
		REPP(i, 1, n) edge[i].clear(), sum[i] = dep[i] = 0;
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		REPP(i, 1, n) scanf("%d", a + i);
		dep[s] = sum[s] = 0;
		REP(i, edge[s].size()) {
			dfs(edge[s][i], s);
			dep[s] = max(dep[s], dep[edge[s][i]] + 1);
			sum[s] = max(sum[s], sum[edge[s][i]]);
		}
		printf("Case #%d: %lld\n", ca++, max(dep[s], sum[s]));
	}

	return 0;
}


