#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
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

using namespace std;

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

const int N = 2e5 + 5;
const int MX = 1e9 + 7;

struct Node{
	int value, size;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N * 20], *foo, *rt[N << 2], *null;

void init() {
	foo = null = bar;
	null->l = null->r = null;
	foo++;
}

Node* New_Node(int x) {
	return new(foo++) (Node) {x, 1, null, null};
}

bool gen(int a, int b) {
	return rand() % (a + b) < a;
}

Node* merge(Node *a, Node *b) {
	if (a == null) return b;
	if (b == null) return a;
	if (gen(a->size, b->size)) {
		a->r = merge(a->r, b);
		return a->update();
	}
	else {
		b->l = merge(a, b->l);
		return b->update();
	}
}	

#define PNN pair<Node*, Node*>

PNN split(Node *u, int s) {
	if (u == null) return {null, null};
	Node *l = u->l, *r = u->r;
	if (l->size >= s) {
		PNN res = split(l, s);
		u->l = res.second;
		return {res.first, u->update()};
	}
	else {
		PNN res = split(r, s - (l->size + 1));
		u->r = res.first;
		return {u->update(), res.second};
	}
}

void show(Node *u) {
	if (u == null) return ;
	else {
		show(u->l);
		printf("value: %d\n", u->value);
		show(u->r);
	}
}

int find(Node *u, int x) {
	if (u == null) return 0;
	if (u->value <= x) {
		return u->l->size + 1 + find(u->r, x);
	}
	else return find(u->l, x);
}

int findmax(Node *u) {
	while (u != null) {
		if (u->r == null) return u->value;
		else u = u->r;
	}
	return -MX;
}

int findmin(Node *u) {
	while (u != null) {
		if (u->l == null) return u->value;
		else u = u->l;
	}
	return MX;
}

Node* erase(Node *&u, int s) {
	int tmp = find(u, s);
	PNN res = split(u, tmp - 1);
	PNN ans = split(res.second, 1);
	u = merge(res.first, ans.second);
	return ans.first;
}

void insert(Node *a, Node *&u) {
	int ans = find(u, a->value);
	PNN res = split(u, ans);
	u = a;
	u = merge(res.first, u);
	u = merge(u, res.second);
}

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

int ql, qr, qd;
int a[N];

void build(int x, int l, int r) {
	if (l == r) {
		rt[x] = null;
		rt[x] = merge(rt[x], New_Node(a[l]));
	}
	else {
		build(LC), build(RC);
		rt[x] = null;
		REPP(i, l, r) {
			insert(New_Node(a[i]), rt[x]);
		}
	}
}

int ans;

void query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		int pos = find(rt[x], qd);
		PNN res = split(rt[x], pos);
		ans = min(ans, abs(qd - findmax(res.first)));
		ans = min(ans, abs(qd - findmin(res.second)));
		rt[x] = merge(res.first, res.second);
	}
	else {
		if (ql <= MID) query(LC);
		if (qr > MID) query(RC);
	}
}


int main() {
	//freopen("B.in", "r", stdin);
	int t, n, q, ca = 1;
	t = in();
	while (t--) {
		n = in(), q = in();
		REPP(i, 1, n ) a[i] = in();
		init();
		build(1, 1, n);
		//show(rt[1]);
		//REPP(i, 1, 7) {
		//	cout << i << "*********************************" << endl;
		//	show(rt[i]);
		//}
		printf("Case #%d:\n", ca++);
		while (q--) {
			ql = in(), qr = in(), qd = in();
			ans = MX;
			//cout << ans << "init" << endl;
			query(1, 1, n);
			out(ans);
		}
	}

	return 0;
}


