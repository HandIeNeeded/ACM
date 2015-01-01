#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 405;
const int M = 50005;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1], edge;
	int lvl[N], cur[N], vis[N];
	int source, sink, tot;

	void init(int S, int T, int node) {
		MST(fi, 0), edge = 1;
		source = S, sink = T, tot = node;
	}

	void _add(int x, int y, int z) {
		ne[++edge] = fi[x]; 
		fi[x] = edge;
		en[edge] = y;
		cap[edge] = z;
	}
	
	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, 0);
	}

	bool bfs() {
		queue<int> q;
		MST(lvl, 0), MST(vis, 0);
		q.push(source), vis[source] = 1;

		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go]) {
				int y = en[go];
				if (!vis[y]) {
					lvl[y] = lvl[x] + 1;
					vis[y] = 1;
					q.push(y);
				}
			}
		}
		return vis[sink];
	}

	int dfs(int x, int flow) {
		if (x == sink || flow == 0) return flow;
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) {
			if (cap[go] > 0) {
				int y = en[go];
				if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
					cap[go] -= tmp;
					cap[go ^ 1] += tmp;
					flow -= tmp;
					ans += tmp;
					if (flow == 0) return ans;
				}
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			REPP(i, 1, tot) cur[i] = fi[i];
			ans += dfs(source, INF);
		}
		return ans;
	}
}flow;

int a[N], b[N];

int main() {
	ios :: sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		flow.init(n + m + 1, n + m + 2, n + m + 2);
		REPP(i, 1, n) cin >> a[i], sum += a[i], flow.add(flow.source, i, a[i]);
		REPP(j, 1, m) cin >> b[j], sum += b[j], flow.add(j + n, flow.sink, b[j]);
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				int x;
				cin >> x;
				if (x == 1) {
					flow.add(i, j + n, min(a[i], b[j]));
				}
			}
		}
		cout << sum - flow.dinic() << endl;
	}

	return 0;
}
