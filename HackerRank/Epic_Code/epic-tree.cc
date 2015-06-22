#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;
const int MO = 10009;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

struct Edge{
	int y, next;
}e[N << 1];

int start[N], edge;

void add_edge(int x, int y) {
	e[++edge].next = start[x], start[x] = edge, e[edge].y = y;
}

int top[N], pos[N], l[N], r[N], pre[N], son[N], size[N], inv[N], dep[N], now = 1, n, q;

//int sumt[N << 2], flagt[N << 2];//tree A
//int sum[N << 2], Size[N << 2], flag[N << 2];// tree B
struct Tree{
	int sum[N << 2], flag[N << 2], size[N << 2];
	int Size[N];

	void init(int type) {
		if (type == 1) {
			REPP(i, 1, n) {
				Size[i] = (::size[inv[i]]) % MO;
			}
		}
		else {
			REPP(i, 1, n) {
				Size[i] = 1;
			}
		}
		build(1, 1, n);
	}

	void build(int x, int l, int r) {
		if (l == r) {
			size[x] = Size[l];
			sum[x] = flag[x] = 0;
		}
		else {
			build(LC), build(RC);
			size[x] = size[L], add(size[x], size[R]);
			sum[x] = flag[x] = 0;
		}
	}

	void push(int x, int l, int r) {
		add(flag[L], flag[x]), add(flag[R], flag[x]);
		add(sum[L], flag[x] * size[L] % MO), add(sum[R], flag[x] * size[R] % MO);
		flag[x] = 0;
	}

	void update(int x, int l, int r, int ql, int qr, int qd) {
		if (ql <= l && qr >= r) {
			add(flag[x], qd);
			add(sum[x], qd * size[x] % MO);
		}
		else {
			if (flag[x]) push(x, l, r);
			if (ql <= MID) update(LC, ql, qr, qd);
			if (qr > MID) update(RC, ql, qr, qd);
			sum[x] = sum[L], add(sum[x], sum[R]);
		}
	}

	int query(int x, int l, int r, int ql, int qr) {
		if (ql <= l && qr >= r) {
			return sum[x];
		}
		else {
			if (flag[x]) push(x, l, r);
			int ans = 0;
			if (ql <= MID) add(ans, query(LC, ql, qr));
			if (qr > MID) add(ans, query(RC, ql, qr));
			return ans;
		}
	}
}A, B;

void dfs(int x, int p = 0) {
	pre[x] = p, size[x] = 1, son[x] = 0;
	dep[x] = dep[p] + 1;
	for (int go = start[x]; go; go = e[go].next) {
		int y = e[go].y;
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
	for (int go = start[x]; go; go = e[go].next) {
		int y = e[go].y;
		if (y != pre[x] && y != son[x]) {
			divide(y, y);
		}
	}
	r[x] = now - 1;
}

int query(int a, int b) {
	int ans = 0;
	while (top[a] - top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			swap(a, b);
		}
		int ql = pos[top[b]], qr = pos[b];
		assert(ql <= qr);
		add(ans, A.query(1, 1, n, ql, qr));
		b = pre[top[b]];
	}
	if (dep[a] > dep[b]) {
		swap(a, b);
	}
	int ql = pos[a], qr = pos[b];
	//cout << a << ' ' << b << endl;
	//cout << ql << ' ' << qr << endl;
	assert(ql <= qr);
	add(ans, A.query(1, 1, n, ql, qr));
	return ans;
}

void modify(int a, int b, int t) {
	while (top[a] - top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			swap(a, b);
		}
		int ql = pos[top[b]], qr = pos[b];
		A.update(1, 1, n, ql, qr, t);
		B.update(1, 1, n, ql, qr, t);
		b = pre[top[b]];
	}
	if (dep[a] > dep[b]) {
		swap(a, b);
	}
	int ql = pos[a], qr = pos[b];
	A.update(1, 1, n, ql, qr, t);
	B.update(1, 1, n, ql, qr, t);
}

int query(int x) {
	int ans = 0;
	if (x != 1) {
		int a = pre[x], b = 1;
		int addup = query(a, b);
		add(ans, addup * size[x] % MO);
	}
	int tmp = B.query(1, 1, n, l[x], r[x]);
	add(ans, tmp);
	return ans;
}

int in() {
	char c;
	while (c = getchar(), (c < '0' || c > '9') && (c != '-'));
	bool flag = (c == '-');
	if (flag) c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return flag ? -x : x;
}

void out(int x) { //int
	if (x < 0) putchar('-'), x = -x;
	int len = 0, bit[10]; // LL  -> bit[20]
	while (x) {
		bit[len++] = x % 10;
		x /= 10;
	}
	if (!len) bit[len++] = 0;
	while (len--) putchar(bit[len] + 48);
	putchar('\n');
}

int main() {
	//freopen("ein", "r", stdin);
	n = in();
	REPP(i, 1, n - 1) {
		int x, y;
		x = in(), y = in();
		add_edge(x, y), add_edge(y, x);
	}
	dfs(1);
	divide(1, 1);
	A.init(0), B.init(1);
	//REPP(i, 1, n) {
	//	cout << i << ' ' << pos[i] << ' ' << size[i] << ' ' << dep[i] << ' ' << l[i] << ' ' << r[i] << endl;
	//}
	q = in();
	while (q--) {
		int type = in();
		if (type == 1) {
			int a = in(), b = in(), t = in();
			modify(a, b, t);
			//REPP(i, 1, 3) {
			//	cout << A.sum[i] << ' ' << A.flag[i] << endl;
			//}
		}
		else {
			int x = in();
			out(query(x));
			//cout << "hehe" << endl;
		}
	}
    return 0;
}
