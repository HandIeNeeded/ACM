#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;
const int M = 100005;
const int INF = 0x3f3f3f3f;

struct MinCostFlow{
	int pre[N], dp[N];
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1], cost[M << 1], edge;
	bool vis[N];
	int source, sink;

	void init(int S, int T) {
		source = S, sink = T;
		MST(fi, 0), edge = 1;
	}
	
	void _add(int x, int y, int z, int w) {
		ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z, cost[edge] = w;
	}

	void add(int x, int y, int z, int w) {
		_add(x, y, z, w);
		_add(y, x, 0, -w);
	}

	bool spfa() {
		MST(dp, 0x3f), MST(pre, 0);
		queue<int> q;
		q.push(source), vis[source] = 1, dp[source] = 0;

		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
				int y = en[go];
				if (dp[y] > dp[x] + cost[go]) {
					dp[y] = dp[x] + cost[go];
					pre[y] = go;
					if (!vis[y]) {
						vis[y] = 1;
						q.push(y);
					}
				}
			}
			vis[x] = 0;
		}
		return dp[sink] != INF;
	}
	
	pair<long long, int> mincost() {
		long long cost = 0, flow = 0;
		while (spfa()) {
			int tmp = INF;
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				tmp = min(tmp, cap[go]);
			}
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
			}
			cost += 1LL * tmp * dp[sink];
			flow += tmp;
		}
		return make_pair(cost, flow);
	}
}flow;

map<int, int> mp;
int tot;
vector<pair<int, int> > edge[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, m, x, y, cnt;
	
	cin >> n;
	REPP(i, 1, n) {
		cin >> cnt;
		REP(j, cnt) {
			cin >> x >> y;
			if (!mp.count(x)) {
				mp[x] = ++tot;
			}
			edge[mp[x]].push_back(make_pair(i, y));
		}
	}
	cin >> m;
	vector<int> s;
	while (m--) {
		s.clear();
		bool bad = 0;
		REP(i, n) {
			cin >> x, s.push_back(x);
			if (!mp.count(x)) {
				bad = 1;
				break;
			}
		}
		if (bad) {
			cout << -1 << endl;
			continue;
		}
		int source = 2 * n + 2, sink = 2 * n + 1;
		flow.init(source, sink);
		REPP(i, 1, n) {
			flow.add(source, i, 1, 0);
		}
		int clk = 1;
		for (auto it : s) {
			flow.add(clk + n, sink, 1, 0);
			for (auto now : edge[mp[it]]) {
				flow.add(now.first, clk + n, INF, now.second);
			}
			clk++;
		}
		pair<long long, int> ans = flow.mincost();
		if (ans.second == n) {
			cout << ans.first << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}

