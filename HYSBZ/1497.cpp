#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 55005;
const int M = 200005;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	int fi[N], en[M << 1], ne[M << 1], cap[M << 1], edge;
	int lvl[N], cur[N], vis[N];
	int source, sink;

	void init(int a, int b) {
		MST(fi, 0), edge = 1;
		source = a, sink = b;
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
					vis[y] = 1;
					lvl[y] = lvl[x] + 1;
					q.push(y);
				}
			}
		}
		return vis[sink];
	}

	int dfs(int x, int flow) {
		if (x == sink || flow == 0) return flow;
		int ans = 0, tmp;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go]) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				ans += tmp;
				flow -= tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				if (flow == 0) return ans;
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			memcpy(cur, fi, sizeof(fi));
			ans += dfs(source, INF);
		}
		return ans;
	}
}flow;

int main() {
	ios :: sync_with_stdio(0);

	int n, m;
	int x, y, z, sum = 0;
	cin >> n >> m;
	flow.init(n + m + 1, n + m + 2);
	REPP(i, 1, n) {
		cin >> x;
		flow.add(i, flow.sink, x);
	}
	REPP(i, 1, m) {
		cin >> x >> y >> z;
		sum += z;
		flow.add(flow.source, i + n, z);
		flow.add(i + n, x, INF);
		flow.add(i + n, y, INF);
	}
	cout << sum - flow.dinic() << endl;

	return 0;
}



