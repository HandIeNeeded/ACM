#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100;
const int M = 5000;
const int INF = 0x3f3f3f3f;

struct MinCostFlow{
	int source, sink;
	int fi[N], en[M << 1], ne[M << 1], cap[M << 1], cost[M << 1], edge;
	int vis[N], dp[N], pre[N];

	void init(int S, int T) {
		edge = 1, source = S, sink = T;
		MST(fi, 0);
	}

	void _add(int x, int y, int z, int w) {
		ne[++edge] = fi[x];
		fi[x] = edge;
		en[edge] = y;
		cap[edge] = z;
		cost[edge] = w;
	}

	void add(int x, int y, int z, int w) {
		_add(x, y, z, w);
		_add(y, x, 0, -w);
	}

	bool spfa() {
		queue<int> q;
		MST(dp, 0x3f), MST(pre, 0);
		dp[source] = 0, q.push(source), vis[source] = 1;

		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) {
				if (cap[go] > 0) {
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
			}
			vis[x] = 0;
		}
		return dp[sink] < INF;
	}
	
	pair<int, int> mincost() {
		int cost = 0, flow = 0;
		while (spfa()) {
			int minn = INF;
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				minn = min(minn, cap[go]);
			}
			flow += minn;
			cost += minn * dp[sink];
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				cap[go] -= minn;
				cap[go ^ 1] += minn;
			}
		}
		return make_pair(cost, flow);
	}
}flow;

int main() {
	ios :: sync_with_stdio(0);
	int t, x, y, z;
	int n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		flow.init(2 * n, 2 * n + 1);
		REPP(i, 1, m) {
			cin >> x >> y >> z;
			flow.add(x, y + n, 1, z);
		}
		REP(i, n) {
			flow.add(2 * n, i, k, 0);
			flow.add(i + n, 2 * n + 1, k, 0);
		}
		pair<int, int> ans = flow.mincost();
		if (ans.second != n * k) {
			cout << -1 << endl;
		}
		else {
			cout << ans.first << endl;
		}
	}

	return 0;
}


