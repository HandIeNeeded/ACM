#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;

struct Node{
	int size, value;
	long long sum;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		sum = l->sum + value + r->sum;
		return this;
	}
}*null, *foo, bar[N], *root[2];

#define PNN pair<Node*, Node*>

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

PNN split(Node *u, int s) {
	if (u == null) return {null, null};
	Node *l = u->l, *r = u->r;
	u->l = u->r = null;
	u->update();
	if (l->size >= s) {
		PNN res = split(l, s);
		u->l = res.second;
		u->r = r;
		return {res.first, u->update()};
	}
	else {
		PNN res = split(r, s - (l->size + 1));
		u->l = l;
		u->r = res.first;
		return {u->update(), res.second};
	}
}

void modify(int l, int r) {
	int a = l, b = r;
	int c = l, d = r;
	if (a & 1) a++;
	if (b & 1) b--;
	a = (a + 1) >> 1, b = (b + 1) >> 1;
	if (!(c & 1)) c++;
	if (!(d & 1)) d--;
	c = (c + 1) >> 1, d = (d + 1) >> 1;
	Node *tmp[2][3];
	tie(tmp[0][0], tmp[0][1]) = split(root[0], a - 1);
	tie(tmp[0][1], tmp[0][2]) = split(tmp[0][1], b - a + 1);
	tie(tmp[1][0], tmp[1][1]) = split(root[1], c - 1);
	tie(tmp[1][1], tmp[1][2]) = split(tmp[1][1], d - c + 1);
	swap(tmp[0][1], tmp[1][1]);
	REP(i, 2) {
		root[i] = merge(tmp[i][0], merge(tmp[i][1], tmp[i][2]));
	}
}

long long query(int l, int r) {
	int a = l, b = r;
	int c = l, d = r;
	if (a & 1) a++;
	if (b & 1) b--;
	a = (a + 1) >> 1, b = (b + 1) >> 1;
	if (!(c & 1)) c++;
	if (!(d & 1)) d--;
	c = (c + 1) >> 1, d = (d + 1) >> 1;
	Node *tmp[2][3];
	tie(tmp[0][0], tmp[0][1]) = split(root[0], a - 1);
	tie(tmp[0][1], tmp[0][2]) = split(tmp[0][1], b - a + 1);
	tie(tmp[1][0], tmp[1][1]) = split(root[1], c - 1);
	tie(tmp[1][1], tmp[1][2]) = split(tmp[1][1], d - c + 1);
	long long ans = 0;
	REP(i, 2) {
		ans += tmp[i][1]->sum;
	}
	REP(i, 2) {
		root[i] = merge(tmp[i][0], merge(tmp[i][1], tmp[i][2]));
	}
	return ans;
}

int main() {
	foo = null = bar;
	bar[0] = {0, 0, 0, foo, foo};
	foo++;
	REP(i, 2) root[i] = null;
	int n, m;
	scanf("%d%d", &n, &m);
	REPP(i, 1, n) {
		int x;
		scanf("%d", &x);
		int id = i & 1;
		root[id] = merge(root[id], new (foo++) (Node) {1, x, x, null, null});
	}
	REPP(i, 1, m) {
		int ty, l, r;
		scanf("%d%d%d", &ty, &l, &r);
		if (ty == 1) {
			modify(l, r);
		}
		else {
			printf("%lld\n", query(l, r));
		}
	}
	return 0;
}
