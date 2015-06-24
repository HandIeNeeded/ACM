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

const int N = 505;
const int M = 10005;
const int INF = 0x3f3f3f3f;

int ans[N], n, m;

struct Dinic{
	int fi[N], en[M << 1], ne[M << 1], cap[M << 1], edge;
	int lvl[N], vis[N], cur[N], source, sink;

	void init(int n) {
		source = 0, sink = n + 1, edge = 1;
		REPP(i, 0, sink) fi[i] = 0;
	}

	void _add(int x, int y, int z) {
		ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z;
	}
	
	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, 0);
	}

	bool bfs() {
		queue<int> q;
		REPP(i, 0, n + 1) lvl[i] = 0;
		lvl[source] = 1, q.push(source);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
				int y = en[go];
				if (!lvl[y]) {
					lvl[y] = lvl[x] + 1;
					q.push(y);
				}
			}
		}
		return lvl[sink];
	}

	int dfs(int x, int flow) {
		if (x == sink || flow == 0) return flow;
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				ans += tmp, flow -= tmp;
				cap[go] -= tmp, cap[go ^ 1] += tmp;
				if (flow == 0) return ans;
			}
		}
		return ans;
	}

	void divide(int x) {
		vis[x] = 1;
		for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !vis[en[go]]) {
			divide(en[go]);
		}
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			REPP(i, 0, sink) cur[i] = fi[i];
			ans += dfs(source, INF);
		}
		REPP(i, 0, sink) vis[i] = 0;
		divide(source);
		return ans;
	}
}d;

vector<int> edge[N];
bool imp[N];

void solve() {
	REP(bit, 31) {
		d.init(n);
		REPP(i, 1, n) {
			REP(j, edge[i].size()) {
				d.add(i, edge[i][j], 1);
			}
			if (ans[i] & (1 << bit)) d.add(i, d.sink, INF);
			else if (imp[i]) d.add(d.source, i, INF);
		}
		d.dinic();
		REPP(i, 1, n) {
			ans[i] |= (1 ^ d.vis[i]) * (1 << bit);
		}
	}
}

int main() {
	//freopen("in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REPP(i, 1, n) edge[i].clear(), ans[i] = 0;
		REPP(i, 1, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y), edge[y].push_back(x);
		}
		int q;
		scanf("%d", &q);
		REPP(i, 1, n) imp[i] = 0;
		REPP(i, 1, q) {
			int x, y;
			scanf("%d%d", &x, &y);
			ans[x] = y, imp[x] = 1;
		}
		solve();
		//REPP(i, 1, n) {
		//	printf("%d\n", ans[i]);
		//}
		long long ans = 0;
		REPP(i, 1, n) {
			REP(j, edge[i].size()) {
				ans += ::ans[i] ^ ::ans[edge[i][j]];
			}
		}
		cout << ans << endl;
	}
	return 0;
}


