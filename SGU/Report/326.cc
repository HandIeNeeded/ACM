#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 250;
const int M = 1000;
const int INF = 0x3f3f3f3f;

int w[N], r[N], mp[N][N];

struct Edge{
	int y, next, cap;
};

struct MaxFlow{
	int head[N], edge, source, sink, lvl[N], cur[N];
	Edge e[M << 1];

	void init(int S = 0, int T = 1) {
		edge = 1, MST(head, 0);
		source = S, sink = T;
	}

	void _add(int x, int y, int z) {
		e[++edge].next = head[x], head[x] = edge, e[edge].y = y, e[edge].cap = z;
	}

	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, z);
	}

	bool bfs() {
		MST(lvl, -1), lvl[source] = 0;
		queue<int> q;
		q.push(source);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = head[x]; go; go = e[go].next) if (e[go].cap > 0) {
				int y = e[go].y;
				if (lvl[y] < 0) {
					lvl[y] = lvl[x] + 1;
					q.push(y);
				}
			}
		}
		return lvl[sink] >= 0;
	}

	int dfs(int x, int flow = INF) {
		if (flow == 0 || x == sink) return flow;
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = e[go].next) if (e[go].cap > 0) {
			int y = e[go].y;
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, e[go].cap))) > 0) {
				ans += tmp, flow -= tmp;
				e[go].cap -= tmp, e[go ^ 1].cap += tmp;
				if (flow == 0) return ans;
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			memcpy(cur, head, sizeof(head));
			ans += dfs(source);
		}
		return ans;
	}
}flow;

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) cin >> w[i];
	REPP(i, 1, n) cin >> r[i];
	int ans = w[1] + r[1];
	REPP(i, 1, n) {
		REPP(j, 1, n) cin >> mp[i][j];
		if (i > 1) {
			r[i] = 0;
			REPP(j, 2, n) {
				r[i] += mp[i][j];
			}
		}
	}
	REPP(i, 2, n) {
		if (w[i] > ans) {
			cout << "NO" << endl;
			return 0;
		}
	}
	flow.init();
	int node = n, sum = 0;
	REPP(i, 2, n) {
		REPP(j, i + 1, n) {
			flow.add(0, ++node, mp[i][j]);
			flow.add(node, i, mp[i][j]);
			flow.add(node, j, mp[i][j]);
			sum += mp[i][j];
		}
	}
	REPP(i, 2, n) flow.add(i, 1, min(ans - w[i], r[i]));
	if (flow.dinic() == sum) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
    return 0;
}
