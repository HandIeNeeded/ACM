const int N = 100005;
const int M = 100005;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	int node, edge, tot, source, sink;
	int lvl[N], cur[N];
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1];
	
	void init(int S, int T) {
		source = S, sink = T;
		MST(fi, 0), edge = 1, tot = n + 1;
	}

	void _add(int x, int y, int z) {
		ne[++edge] = fi[x]; fi[x] = edge; en[edge] = y; cap[edge] = z;
	}

	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, 0);
	}
	
	bool bfs() {
		queue<int> q;
		REPP(i, 0, tot) lvl[i] = 0;
		q.push(source), lvl[source] = 1;

		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !lvl[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				q.push(y);
			}
		}
		return vis[sink];
	}

	int dfs(int x, int flow) {
		if (x == sink || flow == 0) {
			return flow;
		}
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				ans += tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				flow -= tmp;
				if (flow == 0) {
					return ans;
				}
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			REPP(i, 0, tot) cur[i] = fi[i];
			ans += dfs(source, INF);
		}	
		return ans;
	}
}flow;
