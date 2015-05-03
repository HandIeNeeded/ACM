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
#include <climits>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;
int flag[N << 2], s[N << 2], a[N << 2], mx[N << 2];
int top[N], pos[N], l[N], r[N], pre[N], son[N], size[N], inv[N], val[N], dep[N], now;
int fi[N], ne[N << 1], en[N << 1], edge;

void add(int x, int y) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y;
}

void dfs(int x, int p) {
	pre[x] = p, size[x] = 1, son[x] = 0;
	dep[x] = dep[p] + 1;
	for (int go = fi[x]; go; go = ne[go]) {
		int y = en[go];
		if (y != p) {
			dfs(y, x);
			size[x] += size[y];
			if (size[y] > size[son[x]]) {
				son[x] = y;
			}
		}
	}
}

void divide(int x, int tp) {
	top[x] = tp, pos[x] = l[x] = now, inv[now++] = x;
	if (son[x]) divide(son[x], tp);
	for (int go = fi[x]; go; go = ne[go]) {
		int y = en[go];
		if (y != pre[x] && y != son[x]) {
			divide(y, y);
		}
	}
	r[x] = now - 1;
}

int qx, ql, qr, n, qd;

void build(int x, int l, int r) {
	if (l == r) {
		mx[x] = a[x] = flag[x] = 0;
	}
	else {
		build(LC), build(RC);
		mx[x] = a[x] = flag[x] = 0;
	}
}

void push(int x, int l, int r) {
	a[L] += a[x], a[R] += a[x];
	mx[L] += a[x], mx[R] += a[x];
	flag[L] = flag[R] = 1;
	flag[x] = a[x] = 0;
}

void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		flag[x] = 1;
		a[x] += qd;
		mx[x] += qd;
	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		mx[x] = max(mx[L], mx[R]);
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mx[x];
	}
	else {
		if (flag[x]) push(x, l, r);
		int ll = -INT_MAX, rr = -INT_MAX;
		if (ql <= MID) ll = query(LC);
		if (qr > MID) rr = query(RC);
		return max(ll, rr);
	}
}

int query(int a, int b) {
	int ans = -INT_MAX;
	while (top[a] - top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			swap(a, b);
		}
		ql = pos[top[b]], qr = pos[b];
		ans = max(ans, query(1, 1, n));
		b = pre[top[b]];
	}
	if (dep[a] > dep[b]) {
		swap(a, b);
	}
	ql = pos[a], qr = pos[b];
	ans = max(ans, query(1, 1, n));
	return ans;
}

int main() {
	int t = 1;
	while (t--) {
		scanf("%d", &n);
		edge = 0, now = 1;
		REPP(i, 1, n) fi[i] = 0;
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		dfs(1, 0);
		divide(1, 1);
		build(1, 1, n);
		int m;
		scanf("%d", &m);
		while (m--) {
			char tmp[10];
			scanf("%s", tmp);
			if (tmp[0] == 'a') {
				int x, y;
				scanf("%d%d", &x, &y);
				ql = l[x], qr = r[x], qd = y;
				update(1, 1, n);
			}
			else {
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%d\n", query(x, y));
			}
		}
	}

	return 0;
}
