#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 50005;

struct Node{
	Node *l, *r;
	int value, size, cnt;

	Node* update() {
		size = l->size + cnt + r->size;
		return this;
	}
}*null;

void init() {
	null = new Node;
	null->l = null->r = null;
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

pair<Node*, int> find(Node *u, int s, int now) {
	if (u == null) return {null, -now};
	if (u->value == s) {
		if (u->cnt > 0) {
			return {u, now + u->l->size + u->cnt};
		}
		else {
			return {null, -(now + u->l->size)};
		}
	}
	else {
		if (u->value > s) {
			return find(u->l, s, now);
		}
		else {
			return find(u->r, s, now + u->l->size + u->cnt);
		}
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
		PNN res = split(r, s - (l->size + u->cnt));
		u->r = res.first;
		return {u->update(), res.second};
	}
}

void erase(Node *&u, int s) {
	pair<Node*, int> res = find(u, s, 0);
	int cnt = res.first->cnt;
	PNN tmp1 = split(u, res.second - cnt);
	PNN tmp2 = split(tmp1.second, cnt);
	tmp2.first->cnt--;
	if (tmp2.first->cnt == 0) {
		u = merge(tmp1.first, tmp2.second);
	}
	else {
		tmp2.first->update();
		u = merge(tmp1.first, tmp2.first);
		u = merge(u, tmp2.second);
	}
}

Node *rt[N << 2];
int a[N];

Node* New_Node(int x) {
	return new (Node) {null, null, x, 1, 1};
}

void insert(Node *&u, int x) {
	pair<Node*, int> res = find(u, x, 0);
	if (res.second <= 0) {
		res.second *= -1;
		PNN tmp = split(u, res.second);
		u = New_Node(x);
		u = merge(tmp.first, u);
		u = merge(u, tmp.second);
	}
	else {
		int cnt = res.first->cnt;
		PNN tmp1 = split(u, res.second - cnt);
		PNN tmp2 = split(tmp1.second, cnt);
		tmp2.first->cnt++;
		tmp2.first->update();
		u = merge(tmp1.first, tmp2.first);
		u = merge(u, tmp2.second);
	}
}

void show(Node *u) {
	if (u == null) return ;
	else {
		show(u->l);
		printf("value: %d, cnt: %d\n", u->value, u->cnt);
		show(u->r);
	}
}

int ql, qr, qx, qd, qe, n, m;

void build(int x, int l, int r) {
	if (l == r) {
		rt[x] = New_Node(a[l]);
	}
	else {
		build(LC), build(RC);
		rt[x] = null;
		REPP(i, l, r) {
			insert(rt[x], a[i]);
		}
	}
}

void modify(int x, int l, int r) {
	if (l == r) {
		erase(rt[x], qe);
		insert(rt[x], qd);
	}
	else {
		if (qx <= MID) modify(LC);
		else modify(RC);
		erase(rt[x], qe);
		insert(rt[x], qd);
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return abs(find(rt[x], qx, 0).second);
	}
	else {
		int ans = 0;
		if (ql <= MID) ans += query(LC);
		if (qr > MID) ans += query(RC);
		return ans;
	}
}

int answer() {
	int l = 0, r = 1e9 + 7;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		qx = mid;
		if (query(1, 1, n) < qd) l = mid;
		else r = mid;
	}
	return r;
}

char s[2];

int main() {
	//freopen("tmp.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REPP(i, 1, n) {
			scanf("%d", a + i);
		}
		init();
		build(1, 1, n);
		while (m--) {
			scanf("%s", s);
			if (s[0] == 'Q') {
				scanf("%d%d%d", &ql, &qr, &qd);
				printf("%d\n", answer());
			}
			else {
				scanf("%d%d", &qx, &qd);
				qe = a[qx];
				a[qx] = qd;
				modify(1, 1, n);
			}
		}
	}

	return 0;
}


