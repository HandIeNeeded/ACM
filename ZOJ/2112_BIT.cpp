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
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 5e4 + 5;

struct Node{
	int value, size;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N * 20], *foo, *null, *rt[N];

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
	if (u->l->size >= s) {
		PNN res = split(u->l, s);
		u->l = res.second;
		return {res.first, u->update()};
	}
	else {
		PNN res = split(u->r, s - (u->l->size + 1));
		u->r = res.first;
		return {u->update(), res.second};
	}
}

int find(Node *u, int x) {
	if (u == null) return 0;
	if (u->value <= x) {
		return u->l->size + 1 + find(u->r, x);
	}
	else {
		return find(u->l, x);
	}
}

void insert(Node *a, Node *&u) {
	int tmp = find(u, a->value);
	PNN res = split(u, tmp);
	u = a;
	u = merge(res.first, u);
	u = merge(u, res.second);
}

Node* erase(Node *&u, int s) {
	PNN res = split(u, s - 1);
	PNN tmp = split(res.second, 1);
	u = merge(res.first, tmp.second);
	return tmp.first;
}

void show(Node *u) {
	if (u == null) return ;
	show(u->l);
	printf("%d ", u->value);
	show(u->r);
}

int ty[N], a[N], n, m;
int qa[N], qb[N], qc[N];
char s[2];

void modify(int id) {
	int x = a[qa[id]], y = qb[id];
	a[qa[id]] = y;
	id = qa[id];
	while (id <= n) {
		int tmp = find(rt[id], x);
		Node *pre = erase(rt[id], tmp);
		pre->value = y, pre->l = pre->r = null, pre->size = 1;
		insert(pre, rt[id]);
		id += LB(id);
	}
}

int count(int x, int l, int r) {
	int ans = 0, res = 0;
	while (r) {
		ans += find(rt[r], x);
		r -= LB(r);
	}
	while (l) {
		res += find(rt[l], x);
		l -= LB(l);
	}
	return ans - res;
}

int query(int id) {
	int l = 0, r = (1 << 30) - 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (count(mid, qa[id] - 1, qb[id]) >= qc[id]) r = mid;
		else l = mid;
	}
	return r;
}

void build() {
	REPP(i, 1, n) {
		int st = i - LB(i);
		REPP(j, st + 1, i) {
			insert(New_Node(a[j]), rt[i]);
		}
	}
}

int main() {
	//freopen("in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REPP(i, 1, n) {
			scanf("%d", a + i);
		}
		init();
		int x, y, z;
		REPP(i, 1, m) {
			scanf("%s%d%d", s, &x, &y);
			if (s[0] == 'Q') {
				ty[i] = 0;
				scanf("%d", &z);
			}
			else {
				ty[i] = 1;
			}
			qa[i] = x, qb[i] = y, qc[i] = z;
		}
		REPP(i, 1, n) rt[i] = null;
		build();
		REPP(i, 1, m) {
			if (ty[i] == 1) {
				modify(i);
			}
			else {
				printf("%d\n", query(i));
			}
		}
	}

	return 0;
}

