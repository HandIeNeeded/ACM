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

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

const int N = 1e5 + 5;
int flag[N << 2], s[N << 2], a[N << 2];
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

int qx, ql, qr, n;

void build(int x, int l, int r) {
	if (l == r) {
		s[x] = val[inv[l]];
		a[x] = flag[x] = 0;
	}
	else {
		build(LC), build(RC);
		s[x] = s[L] + s[R];
		a[x] = flag[x] = 0;
	}
}

void push(int x, int l, int r) {
	a[L] = s[L], a[R] = s[R];
	flag[L] = flag[R] = 1;
	flag[x] = 0;
}

void modify(int x, int l, int r) {
	if (l == r) {
		flag[x] = a[x] = 0;
	}
	else {
		if (flag[x]) push(x, l, r);
		if (qx <= MID) modify(LC);
		else modify(RC);
		a[x] = a[L] + a[R];
	}
}

void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		flag[x] = 1;
		a[x] = s[x];
	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		a[x] = a[L] + a[R];
	}
}

void query(int a, int b) {
	while (top[a] - top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			swap(a, b);
		}
		ql = pos[top[b]], qr = pos[b];
		update(1, 1, n);
		b = pre[top[b]];
	}
	if (dep[a] > dep[b]) {
		swap(a, b);
	}
	ql = pos[a], qr = pos[b];
	update(1, 1, n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REPP(i, 1, n) scanf("%d", val + i);
		edge = 0, now = 1;
		REPP(i, 1, n) fi[i] = 0;
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		dfs(1, 0);
		divide(1, 1);
		//REPP(i, 1, n) {
		//	cout << i << ' ' << pos[i] << ' ' << inv[i] << endl;
		//}
		//cout << "l r:" << endl;
		//REPP(i, 1, n) {
		//	cout << i << ' ' << l[i] << ' ' << r[i] << endl;
		//}
		build(1, 1, n);
		int m;
		scanf("%d", &m);
		while (m--) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				int x, y;
				scanf("%d%d", &x, &y);
				query(x, y);
			}
			else if (ty == 2) {
				scanf("%d", &qx);
				qx = pos[qx];
				modify(1, 1, n);
			}
			else {
				int x;
				scanf("%d", &x);
				ql = l[x], qr = r[x];
				update(1, 1, n);
			}
			printf("%d\n", a[1]);
		}
	}

	return 0;
}

