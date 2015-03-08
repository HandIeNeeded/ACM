#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 3e4 + 5;

struct Node {
	Node *l, *r;
	int value, size;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N], *foo, *null;

void init() {
	foo = null = bar;
	null->l = null->r = null;
	foo++;
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

int find(Node *u, int s, int now) {
	if (u == null) return now;
	if (u->value <= s) {
		return find(u->r, s, now + u->l->size + 1);
	}
	else {
		return find(u->l, s, now);
	}
}

void insert(Node *&u, int x) {
	int cnt = find(u, x, 0);
	PNN res = split(u, cnt);
	u = new (foo++) (Node) {null, null, x, 1};
	u = merge(res.first, u);
	u = merge(u, res.second);
}

int select(Node *u, int s) {
	if (s == u->l->size + 1) return u->value;
	else if (u->l->size >= s) {
		return select(u->l, s);
	}
	else {
		return select(u->r, s - u->l->size - 1);
	}
}

void show(Node *u) {
	if (u == null) return ;
	show(u->l);
	printf("value: %d, size: %d\n", u->value, u->size);
	show(u->r);
}

int a[N], b[N];

int main() {
	//freopen("tmp.in", "r", stdin);
	ios :: sync_with_stdio(0);
	int n, m, flag = 0;
	while (cin >> n >> m) {
		if (flag++) cout << endl;
		init();
		Node *rt = null;
		REPP(i, 1, n) cin >> a[i];
		REPP(i, 1, m) cin >> b[i];
		int now = 1;
		REPP(i, 1, n) {
			insert(rt, a[i]);
			while (now <= m && b[now] == i) {
				cout << select(rt, now) << endl;
				now++;
			}
			//cout << i << endl;
			//show(rt);
			//cout << "******************************" << endl;
		}
	}

	return 0;
}

