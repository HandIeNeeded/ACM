#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

struct Node{
	int size, sum, cnt;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		sum = l->sum + cnt + r->sum;
		return this;
	}
}bar[N << 1], *foo, *null, *rt[2];

void init() {
	foo = null = bar;
	null->l = null->r = null;
	foo++;
	REP(i, 2) rt[i] = null;
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

Node* New_Node() {
	return new(foo++) (Node) {1, 1, 1, null, null};
}

void add(Node *&a, Node *b) {
	a->cnt += b->cnt;
	a->sum += b->sum;
}

void insert(Node *&u, int x, Node *a) {
	//cout << "hehe" << ' ' << x << ' ' << a->cnt << endl;
	PNN res = split(u, x - 1);
	PNN tmp = split(res.second, 1);
	add(tmp.first, a);
	u = merge(res.first, tmp.first);
	u = merge(u, tmp.second);
}

Node* combine(Node *u, Node *v, int n, int st) {
	for (int i = 1; i <= n; i++) {
		PNN res = split(u, 0);
		PNN tmp = split(res.second, 1);
		insert(v, st + i, tmp.first);
		u = merge(res.first, tmp.second);
	}
	return v;
}

void show(Node *u) {
	if (u == null) return ;
	show(u->l);
	printf("cnt: %d, sum: %d, size: %d\n", u->cnt, u->sum, u->size);
	show(u->r);
}

void modify(int x) {
	Node *a, *b, *c, *d;
	if (x > rt[0]->size - x) {
		swap(rt[0], rt[1]);
		x = rt[0]->size - x;
	}
	int tot = rt[0]->size;
	tie(a, b) = split(rt[0], x);
	tie(c, d) = split(rt[1], tot - x);
	rt[0] = combine(d, b, x, 0);
	rt[1] = combine(a, c, x, tot - 2 * x);
}

int answer(Node *u, int x) {
	if (u == null) return 0;
	Node *l = u->l, *r = u->r;
	if (l->size >= x) {
		return answer(l, x);
	}
	else {
		return l->sum + u->cnt + answer(r, x - (l->size + 1));
	}
}

int query(int x, int y) {
	//cout << x << ' ' << y << endl;
	return answer(rt[0], y) - answer(rt[0], x);
}

int main() {
	//freopen("tmp.in", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	REPP(i, 1, n) {
		REP(j, 2) {
			rt[j] = merge(rt[j], New_Node());
		}
	}
	while (m--) {
		int ty, x, y;
		scanf("%d%d", &ty, &x);
		if (ty == 1) {
			modify(x);
		}
		else {
			scanf("%d", &y);
			printf("%d\n", query(x, y));
		}
	}

	return 0;
}

