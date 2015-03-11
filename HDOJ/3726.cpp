#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cassert>
#include <cmath>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e4 + 5;
const int M = 6e4 + 5;
const int INF = 1e9 + 7;

int value[N], f[N], size[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

struct Node {
	int value, size;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[int(3e5 + 5)], *foo, *null, *rt[N];

void init() {
	foo = null = bar;
	null->l = null->r = null;
	foo++;
}

bool gen(int a, int b) {
	return rand() % (a + b) < a;
}

Node* New_Node(int x) {
	return new (foo++) (Node) {x, 1, null, null};
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
	if (u == null) return make_pair(null, null);
	Node *l = u->l, *r = u->r;
	if (l->size >= s) {
		PNN res = split(l, s);
		u->l = res.second;
		return make_pair(res.first, u->update());
	}
	else {
		PNN res = split(r, s - (l->size + 1));
		u->r = res.first;
		return make_pair(u->update(), res.second);
	}
}

int find(Node *u, int x) {
	if (u == null) return 0;
	Node *l = u->l, *r = u->r;
	if (u->value > x) {
		return find(l, x);
	}
	else {
		return l->size + 1 + find(r, x);
	}
}

void erase(Node *&u, int x) {
	int tmp = find(u, x);
	PNN res = split(u, tmp - 1);
	PNN ans = split(res.second, 1);
	u = merge(res.first, ans.second);
}

void insert(Node *&u, int x) {
	int tmp = find(u, x);
	PNN res = split(u, tmp);
	u = New_Node(x);
	u = merge(res.first, u);
	u = merge(u, res.second);
}
 
int select(Node *u, int x) {
	if (x < 0 || u == null) return INF;
	if (x == u->l->size + 1) return u->value;
	else if (x <= u->l->size) {
		return select(u->l, x);
	}
	else {
		return select(u->r, x - (u->l->size + 1));
	}
}

void combine(Node *a, Node *&b) {
	if (a == null) return ;
	combine(a->l, b);
	insert(b, a->value);
	combine(a->r, b);
}

void link(int x, int y) {
	int tx = find(x), ty = find(y);
	if (tx != ty) {
		if (size[tx] <= size[ty]) {
			f[tx] = ty;
			size[ty] += size[tx];
			combine(rt[tx], rt[ty]);
		}
		else {
			f[ty] = tx;
			size[tx] += size[ty];
			combine(rt[ty], rt[tx]);
		}
	}
}

pair<int, int> edge[M];
char s[2];
bool vis[M];

struct operation{
	int ty, a, b, c;
}q[int(5e5 + 5)];

int main() {
	//freopen("tmp.in", "r", stdin);
	int n, m, ca = 1;
	while (scanf("%d%d", &n, &m), n | m) {
		init();
		REP(i, m) vis[i] = 0;
		REPP(i, 1, n) {
			scanf("%d", value + i);
			f[i] = i;
			size[i] = 1;
			rt[i] = null;
		}
		REPP(i, 1, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[i] = make_pair(x, y);
		}
		int tot = 0, cnt = 0;
		while (scanf("%s", s)) {
			if (s[0] == 'E') break;
			tot++;
			if (s[0] == 'Q') {
				q[tot].ty = 0;
				scanf("%d%d", &q[tot].a, &q[tot].b);
			}
			else if (s[0] == 'C') {
				q[tot].ty = 1;
				scanf("%d%d", &q[tot].a, &q[tot].b);
				q[tot].c = value[q[tot].a];
				value[q[tot].a] = q[tot].b;
			}
			else {
				q[tot].ty = 2;
				int x;
				scanf("%d", &x);
				q[tot].a = edge[x].first;
				q[tot].b = edge[x].second;
				vis[x] = 1;
			}
		}
		REPP(i, 1, n) {
			rt[i] = New_Node(value[i]);
		}
		REPP(i, 1, m) {
			if (!vis[i]) {
				int x, y;
				tie(x, y) = edge[i];
				link(x, y);
			}
		}
		long long ans = 0;
		for (int i = tot; i >= 1; i--) {
			if (q[i].ty == 0) {
				int fx = find(q[i].a), k = q[i].b;
				int tmp = select(rt[fx], size[fx] + 1 - k);
				ans += tmp == INF ? 0 : tmp;
				cnt++;
			}
			else if (q[i].ty == 1) {
				int fx = find(q[i].a), a = q[i].b, b = q[i].c;
				erase(rt[fx], a);
				insert(rt[fx], b);
			}
			else {
				int fx = find(q[i].a), fy = find(q[i].b);
				if (fx != fy) {
					link(q[i].a, q[i].b);
				}
			}
		}
		printf("Case %d: %.6f\n", ca++, 1.0 * ans / cnt);
	}

	return 0;
}

