#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define PII pair<int, int>

using namespace std;

const int N = 1e5 + 5;

struct Edge{
	int ed, next, dist;
}e[N << 6];

int start[N], head[N], col[N], edge;
priority_queue<PII, vector<PII>, greater<PII> > q[N];
int vis[N], size[N], maxsub[N], rt;

void add(int x, int y) {
	e[++edge].next = start[x], start[x] = edge, e[edge].ed = y;
}

void add(int x, int y, int z) {
	e[++edge].next = head[x], head[x] = edge, e[edge].ed = y, e[edge].dist = z;
}

void dfs_size(int x, int p = 0) {
	size[x] = 1, maxsub[x] = 0;
	for (int go = start[x]; go; go = e[go].next) {
		int y = e[go].ed;
		if (y != p && !vis[y]) {
			dfs_size(y, x);
			size[x] += size[y];
			if (size[y] > maxsub[x]) {
				maxsub[x] = size[y];
			}
		}
	}
}

void dfs_root(int x, int tot, int p = 0) {
	if (tot - size[x] > maxsub[x]) {
		maxsub[x] = tot - size[x];
	}
	if (maxsub[x] < maxsub[0]) maxsub[0] = maxsub[x], rt = x;
	for (int go = start[x]; go; go = e[go].next) {
		int y = e[go].ed;
		if (y != p && !vis[y]) {
			dfs_root(y, tot, x);
		}
	}
}

void dfs_dist(int x, int p = 0, int dep = 0) {
	add(x, rt, dep);
	for (int go = start[x]; go; go = e[go].next) {
		int y = e[go].ed;
		if (y != p && !vis[y]) {
			dfs_dist(y, x, dep + 1);
		}
	}
}

void divide(int x) {
	maxsub[0] = N;
	dfs_size(x);
	dfs_root(x, size[x]);
	dfs_dist(rt);
	vis[rt] = 1;
	for (int go = start[rt]; go; go = e[go].next) {
		int y = e[go].ed;
		if (!vis[y]) divide(y);
	}
}

void update(int x) {
	if (col[x]) {
		q[x].push(make_pair(0, x));
		for (int go = head[x]; go; go = e[go].next) {
			int y = e[go].ed;
			q[y].push(make_pair(e[go].dist, x));
		}
	}
}

int query(int x) {
	int ans = N;
	for (int go = head[x]; go; go = e[go].next) {
		int y = e[go].ed;
		while (q[y].size() && !col[q[y].top().second]) q[y].pop();
		if (q[y].size()) ans = min(ans, e[go].dist + q[y].top().first);
	}
	if (ans == N) ans = -1;
	return ans;
}

int main() {
    ios :: sync_with_stdio(0);
	//freopen("V.in", "r", stdin);
	int n;
	scanf("%d", &n);
	REPP(i, 1, n - 1) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	divide(1);
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == 0) {
			col[y] ^= 1;
			update(y);
		}
		else {
			printf("%d\n", query(y));
		}
	}
    return 0;
}

