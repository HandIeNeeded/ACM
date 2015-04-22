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

const int N = 2005;
const int M = 5005;
const double EPS = 1e-7;

struct MaxFlow{
	int edge, source, sink;
	int lvl[N], vis[N], cur[N];
	int fi[N], ne[M << 1], en[M << 1];
   	double cap[M << 1];
	
	void init(int S, int T) {
		source = S, sink = T;
		MST(fi, 0), edge = 1;
	}

	void _add(int x, int y, double z) {
		ne[++edge] = fi[x];
		fi[x] = edge;
		en[edge] = y;
		cap[edge] = z;
	}

	void add(int x, int y, double z) {
		_add(x, y, z);
		_add(y, x, 0);
	}
	
	bool bfs() {
		queue<int> q;
		MST(lvl, 0), MST(vis, 0);
		q.push(source);
		vis[source] = 1;

		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > EPS && !vis[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				q.push(y);
				vis[y] = 1;
			}
		}
		return vis[sink];
	}

	double dfs(int x, double flow) {
		if (x == sink || flow < EPS) {
			return flow;
		}
		double ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > EPS) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > EPS) {
				ans += tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				flow -= tmp;
				if (fabs(tmp) < EPS) {
					return ans;
				}
			}
		}
		return ans;
	}

	void divide(int x) {
		vis[x] = 1;
		for (int go = fi[x]; go; go = ne[go]) if (cap[go] > EPS) {
			int y = en[go];
			if (!vis[y]) divide(y);
		}
	}

	double dinic() {
		double ans = 0;
		while (bfs()) {
			memcpy(cur, fi, sizeof(fi));
			ans += dfs(source, 1e9);
		}	
		return ans;
	}
}flow;

pair<int, int> edge[M];
int n, m;

double go(double g) {
	double ans = m;
	flow.init(0, n + m + 1);
	REPP(i, 1, m) flow.add(flow.source, i, 1);
	REPP(i, 1, n) flow.add(i + m, flow.sink, g);
	REPP(i, 1, m) {
		flow.add(i, edge[i].first + m, 1e9);
		flow.add(i, edge[i].second + m, 1e9);
	}
	ans -= flow.dinic();
	REPP(i, 0, flow.sink) flow.vis[i] = 0;
	flow.divide(0);
	return ans;
}

vector<int> ans;

void getans() {
	REPP(i, 1, flow.sink - 1) {
		if (flow.vis[i]) {
			if (i <= m) {
				ans.push_back(edge[i].first);
				ans.push_back(edge[i].second);
			}
			else {
				ans.push_back(i - m);
			}
		}
	}
}

int main() {
	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);
	scanf("%d%d", &n, &m);
	REPP(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[i] = {x, y};
	}
	double lo = 0, hi = 2.0 * m;
	while (hi - lo > EPS) {
		double mid = (lo + hi) / 2.0;
		if (go(mid) > EPS) lo = mid;
		else hi = mid;
	}
	go(lo - EPS);
	getans();
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	if (ans.size() == 0) ans.push_back(1);
	printf("%d\n", (int) ans.size());
	REP(i, ans.size()) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

