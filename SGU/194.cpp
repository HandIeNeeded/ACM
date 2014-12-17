#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 100005;
const int M = 200005;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	int source, sink, node, edge;
	int lvl[N], cur[N], vis[N];
	int fi[N], en[M << 1], ne[M << 1], cap[M << 1];

	void init(int S, int T, int tot) {
		source = S, sink = T, node = tot;
		MST(fi, 0), edge = 1;
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
		if (x == sink || flow == 0) {
			return flow;
		}
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go]) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				ans += tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				flow -= tmp;
				if (flow == 0) return ans;
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0, tmp = 0;
		while(bfs()) {
			REPP(i, 1, node) cur[i] = fi[i];
			while (tmp = dfs(source, INF)) {
				ans += tmp;
			}
		}
		return ans;
	}
}maxflow;

int ql[N], in[N], a[N];

int main() {		
//	freopen("cf.in", "r", stdin);

	int n, m, x, y, hi, lo;
	cin >> n >> m;
	maxflow.init(n + 1, n + 2, n + 2);
	REPP(i, 1, m) {
		cin >> x >> y;
		cin >> lo >> hi;
		ql[i] = hi - lo, a[i] = lo;
		in[x] -= lo, in[y] += lo;
		maxflow.add(x, y, hi - lo);
	}
	REPP(i, 1, n){
		if (in[i] < 0) {
			maxflow.add(i, maxflow.sink, -in[i]);
		}
		else if (in[i] > 0) {
			maxflow.add(maxflow.source, i, in[i]);
		}
	}
	maxflow.dinic();
	int bad = 0;
	for (int go = maxflow.fi[maxflow.source]; go; go = maxflow.ne[go]) {
		if (maxflow.cap[go] > 0) {
			bad = 1;
			break;
		}
	}
	if (bad) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		REPP(i, 2, 2 * m + 1) {
			if (i & 1) {
				cout << a[i >> 1] + maxflow.cap[i] << endl;
			}
		}
	}

	return 0;
}


