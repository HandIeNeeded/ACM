#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#define MAX_N 30010
#define MAX_M 100010
#define MAX_OP 150000
#define lch (v<<1)
#define rch ((v<<1)+1)
#define mid ((s+t)>>1)
using namespace std;
int n, m, tt, ee, ti, deep, depth;
int fa[MAX_N], point[MAX_N], d[MAX_N], s[MAX_N], t[MAX_N], l[MAX_N], ff[MAX_N];
int op[MAX_OP], p[MAX_OP], q[MAX_OP], ans[MAX_OP];
int r[MAX_M * 2], nex[MAX_M * 2];
int a[100000];
int f[MAX_N][20];
struct edge {
	int u, v;
	bool operator <(const edge &e) const {
		return (u < e.u || (u == e.u && v < e.v));
	}
	bool operator ==(const edge &e) const {
		return (u == e.u && v == e.v);
	}

} e[MAX_M], e2[MAX_M];
int find(int u) {
	if (ff[u] == 0)
		return u;
	ff[u] = find(ff[u]);
	return ff[u];
}
void bui(int u, int v) {
	ee++;
	r[ee] = v;
	nex[ee] = point[u];
	point[u] = ee;
	ee++;
	r[ee] = u;
	nex[ee] = point[v];
	point[v] = ee;
}
void dfs(int u) {
	ti++;
	l[ti] = u;
	s[u] = ti;
	for (int i = point[u]; i; i = nex[i]) {
		if (r[i] != fa[u]) {
			d[r[i]] = d[u] + 1;
			if (d[r[i]] > deep)
				deep = d[r[i]];
			fa[r[i]] = u;
			dfs(r[i]);
		}
	}
	t[u] = ti;
}
//segment tree
void build(int v, int s, int t) {
	if (s == t) {
		a[v] = d[l[s]];
		return;
	}
	a[v] = 0;
	build(lch, s, mid);
	build(rch, mid + 1, t);
}
void modify(int v, int s, int t, int c, int d) {
	if (c <= s && t <= d) {
		a[v]--;
		return;
	}
	if (c <= mid)
		modify(lch, s, mid, c, d);
	if (d >= mid + 1)
		modify(rch, mid + 1, t, c, d);
}
void ask(int v, int s, int t, int c) {
	depth = depth + a[v];
	if (s == t)
		return;
	if (c <= mid)
		ask(lch, s, mid, c);
	else
		ask(rch, mid + 1, t, c);
}
//lca
void lca_init() {
	int st = (int) (log(deep) / log(2));
	for (int i = 1; i <= n; i++)
		f[i][0] = fa[i];
	for (int j = 1; j <= st; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
}
int lca(int x, int y) {
	if (d[x] < d[y])
		swap(x, y);
	int dd = (int) (log(d[x]) / log(2));
	for (int i = dd; i >= 0; i--)
		if (d[f[x][i]] >= d[y])
			x = f[x][i];
	if (x == y)
		return x;
	for (int i = dd; i >= 0; i--)
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	return fa[x];
}
void init() {
	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v;
		if (e[i].u > e[i].v)
			swap(e[i].u, e[i].v);
	}
	sort(e, e + m);
	int oo = 0;
	for (int i = 0; i < tt; i++) {
		cin >> op[i] >> p[i] >> q[i];
		if (op[i] == 0) {
			e2[oo].u = p[i];
			e2[oo].v = q[i];
			if (e2[oo].u > e2[oo].v)
				swap(e2[oo].u, e2[oo].v);
			oo++;
		}
	}
	sort(e2, e2 + oo);
	int j = 0, u, v;
	ee = 0;
	ti = 0;
	memset(ff, 0, sizeof(ff));
	memset(point, 0, sizeof(point));
	for (int i = 0; i < m; i++)
		if (j < oo && e[i] == e2[j])
			j++;
		else {
			u = find(e[i].u);
			v = find(e[i].v);
			if (u == v) {
				op[tt] = 0;
				p[tt] = e[i].u;
				q[tt] = e[i].v;
				tt++;
			} else {
				ff[u] = v;
				bui(e[i].u, e[i].v);
			}
		}
	d[1] = 1;
	deep = 1;
	dfs(1);
	lca_init();
	build(1, 1, n);
	memset(ff, 0, sizeof(ff));
}
void merge(int u, int v) {
	if (u == v)
		return;
	merge(find(fa[u]), v);
	ff[u] = v;
	modify(1, 1, n, s[u], t[u]);
}
void work() {
	int u, v, w, dd, aa = 0;
	for (int i = 0; i < tt; i++) {
		u = find(p[i]);
		v = find(q[i]);
		w = find(lca(p[i], q[i]));
		if (op[i] == 1) {
			depth = 0;
			ask(1, 1, n, s[u]);
			ask(1, 1, n, s[v]);
			dd = depth;
			depth = 0;
			ask(1, 1, n, s[w]);
			ans[aa++] = dd - depth * 2;
		}
	}
	for (int i = 0; i < tt; i++) cout << ans[i] << endl;
}
int main() {
	// freopen("1413.in", "r", stdin);
	// freopen("1413.ans", "w", stdout);
	while (cin >> n >> m >> tt) {
		init();
		work();
	}
}
