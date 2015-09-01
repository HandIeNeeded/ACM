#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

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

const int N = 1e6 + 5;  

struct Node{
	int value, size;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N], *foo, *rt, *null;

void init() {
	foo = null = rt = bar;
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

int query() {
    if (rt == null) return 0;
    Node *tmp = rt;
    while (tmp -> r != null) {
        tmp = tmp -> r;
    }
    return tmp->value;
}

int find(Node *u, int x) {
	if (u == null) return 0;
	if (u->value <= x) {
		return u->l->size + 1 + find(u->r, x);
	}
	else return find(u->l, x);
}

void insert(Node *u, int x) {
    int cnt = find(rt, x);
    PNN res = split(rt, cnt);
    rt = New_Node(x);
    rt = merge(res.first, rt);
    rt = merge(rt, res.second);
}

void erase(Node *u) {
    if (u == null) return ;
    PNN res = split(u, 1);
    rt = res.second;
}

int main() {
#ifdef HOME
    freopen("G.in", "r", stdin);
#endif

    int n;
    init();
    n = in();
    REP(i, n) {
        int type = in(), x;
        if (type == 1) {
            x = in();
            insert(rt, x);
        }
        else if (type == 2) {
            x = in();
            erase(rt);
        }
        else {
            out(query());
        }
    }

    return 0;
}

