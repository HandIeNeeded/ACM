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
#define id(l, r) ((l + r) | (l != r))

using namespace std;

const int N = 4e5;
const int M = N << 2;
const int INF = 0x3f3f3f3f;

int a[N], b[N], c[N], w[N];
int n, m, now, ql, qr;
int top[N], son[N], size[N], pre[N], pos[N], dep[N], inv[N];

struct MaxFlow{
	int fi[N], en[M], ne[M], cap[M], edge;
	int lvl[N], cur[N];
	int source, sink, tot;

	void init() {
		edge = 1, tot = 2 * n + 1 + m;
		REPP(i, 0, tot) fi[i] = 0;
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
		REPP(i, 0, tot) lvl[i] = 0;
		q.push(source), lvl[source] = 1;
		while (q.size()) {
			int x = q.front(); q.pop();
			for(int go = fi[x]; go; go = ne[go]) if (cap[go]) {
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
		if (x == sink || flow == 0) {
			return flow;
		}
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go]) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				cap[go] -= tmp, cap[go ^ 1] += tmp;
				ans += tmp, flow -= tmp;
				if (!flow) return ans;
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
}D;

void modify(int node, int l, int r) {
	if (ql <= l && qr >= r) {
		D.add(node, id(l, r), INF);
	}
	else {
		int mid = (l + r) >> 1;
		if (ql <= mid) modify(node, l, mid);
		if (qr > mid) modify(node, mid + 1, r);
	}
}

void build(int l, int r) {
	if (l == r) {
		D.add(id(l, r), D.sink, w[inv[l]]);
	}
	else {
		int mid = (l + r) >> 1;
		build(l, mid), build(mid + 1, r);
		int rt = id(l, r), a = id(l, mid), b = id(mid + 1, r);
		D.add(rt, a, INF), D.add(rt, b, INF);
	}
}

void prepare() {
	D.source = 1, D.sink = 2 * n + 1;
	build(1, n);
	REPP(i, 1, m) {
		D.add(D.source, i + D.sink, c[i]);
	}
}

vector<int> edge[N];

void dfs(int x, int p) {
	size[x] = 1, son[x] = 0;
	dep[x] = dep[p] + 1, pre[x] = p;
	for (auto y: edge[x]) if (y != p) {
		dfs(y, x);
		size[x] += size[y];
		if (size[y] > size[son[x]]) {
			son[x] = y;
		}
	}
}

void divide(int x, int tp) {
	pos[x] = ++now, top[x] = tp;
	if (son[x]) divide(son[x], tp);
	for (auto y: edge[x]) if (y != pre[x] && y != son[x]) {
		divide(y, y);
	}
}

void add_edge(int x, int a, int b) {
	while (top[a] - top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			swap(a, b);
		}
		ql = pos[top[b]], qr = pos[b];
		modify(x + D.sink, 1, n);
		b = pre[top[b]];
	}
	if (dep[a] > dep[b]) swap(a, b);
	ql = pos[a], qr = pos[b];
	modify(x + D.sink, 1, n);
}

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> m;
	REPP(i, 1, n) {
		cin >> w[i];
	}
	REPP(i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	REPP(i, 1, m) {
		cin >> a[i] >> b[i] >> c[i];
	}
	D.init();
	dfs(1, 0);
	divide(1, 1);
	REPP(i, 1, n) inv[pos[i]] = i;
	prepare();
	REPP(i, 1, m) {
		add_edge(i, a[i], b[i]);
	}
	cout << D.dinic() << endl;
	return 0;
}


