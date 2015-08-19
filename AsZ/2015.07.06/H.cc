#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

int n;

template<int N, int M, class Type>
struct MaxFlow{
	int node, edge, tot, source, sink;
	int lvl[N], cur[N], col[N];
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1];
	const Type INF = 1LL << 60;
	
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
		return lvl[sink];
	}

	Type dfs(int x, Type flow) {
		if (x == sink || flow == 0) {
			return flow;
		}
		Type ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, (Type) cap[go]))) > 0) {
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

	Type dinic() {
		Type ans = 0;
		while (bfs()) {
			REPP(i, 0, tot) cur[i] = fi[i];
			ans += dfs(source, INF);
		}	
		return ans;
	}

	void getans() {
		queue<int> q;
		REPP(i, 0, tot) col[i] = 2;
		q.push(source), col[source] = 1;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && col[en[go]] == 2) {
				col[en[go]] = 1;
				q.push(en[go]);
			}
		}
	}
};

MaxFlow<105, 10205, LL> flow;

int main() {
	ios :: sync_with_stdio(0);
	freopen("hentium.in", "r", stdin);
	freopen("hentium.out", "w", stdout);

	while (cin >> n, n) {
		flow.init(0, n + 1);
		REPP(i, 1, n) {
			int x, y;
			cin >> x >> y;
			flow.add(0, i, y);
			flow.add(i, n + 1, x);
		}
		REPP(i, 1, n) {
			REPP(j, 1, n) {
				int x;
				cin >> x;
				flow.add(i, j, x);
			}
		}
		cout << flow.dinic() << endl;
		flow.getans();
		REPP(i, 1, n) {
			cout << flow.col[i] << " \n"[i == n];
		}
	}
	return 0;
}

