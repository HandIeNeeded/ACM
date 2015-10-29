#include <bits/stdc++.h>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e4 + 5;

struct Edge{
	int a, b, c;
	Edge(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
}q[N];

int top[N], pos[N], dep[N], pre[N], size[N], son[N], now, mx[N << 2];
vector<int> edge[N];

void dfs(int x, int p) {
	size[x] = 1, son[x] = 0;
	dep[x] = dep[p] + 1, pre[x] = p;
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != p) {
			dfs(y, x);
			size[x] += size[y];
			if (size[y] > size[son[x]]) {
				son[x] = y;
			}
		}
	}
}

void build(int x, int p) {
	pos[x] = now++, top[x] = p;
	if (son[x]) build(son[x], p);
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != pre[x] && y != son[x]) {
			build(y, y);
		}
	}
}

int qx, qd, ql, qr;

void modify(int x, int l, int r) {
	if (l == r) {
		mx[x] = qd;
	}
	else {
		int mid = (l + r) >> 1;
		if (qx <= mid) modify(2 * x, l, mid);
		else modify(2 * x + 1, mid + 1, r);
		mx[x] = max(mx[2 * x], mx[2 * x + 1]);
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mx[x];
	}
	else {
		int ans = 0;
		int mid = (l + r) >> 1;
		if (ql <= mid) ans = max(ans, query(2 * x, l, mid));
		if (qr > mid) ans = max(ans, query(2 * x + 1, mid + 1, r));
		return ans;
	}
}

int find(int a, int b) {
	int ans = 0;
	int fa = top[a], fb = top[b];
	while (fa != fb) {
		if (dep[fa] > dep[fb]) swap(a, b), swap(fa, fb);
		ql = pos[fb], qr = pos[b];
		ans = max(ans, query(1, 1, now));
		b = pre[fb], fb = top[b];
	}
	if (a == b) return ans;
	if (dep[a] > dep[b]) swap(a, b), swap(fa, fb);
	ql = pos[son[a]], qr = pos[b];
	ans = max(ans, query(1, 1, now));
	return ans;
}

char s[10];

int main() {
	//freopen("in", "r", stdin);
	int t, a, b, x, y, z, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REPP(i, 1, n) edge[i].clear();
		REPP(i, 1, n - 1) {
			scanf("%d%d%d", &x, &y, &z);
			q[i] = (Edge) {x, y, z};
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		dfs(1, 0);
		now = 0;
		build(1, 1);
		now--;
		REPP(i, 1, n - 1) {
			a = q[i].a, b = q[i].b;
			if (dep[a] > dep[b]) swap(a, b);
			qx = pos[b], qd = q[i].c;
			modify(1, 1, now);
		}
		while (scanf("%s", s), s[0] != 'D') {
			if (s[0] == 'C') {
				scanf("%d%d", &qx, &qd);
				a = q[qx].a, b = q[qx].b;
				if (dep[a] > dep[b]) swap(a, b);
				qx = pos[b];
				modify(1, 1, now);
			}
			else {
				scanf("%d%d", &a, &b);
				printf("%d\n", find(a, b));
			}
		}
	}

	return 0;
}
