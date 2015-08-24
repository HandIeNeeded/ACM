#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

struct Node{
    Node *l, *r;
    int value, size;

    Node* update() {
        size = 1 + l->size + r->size;
        return this;
    }
}bar[N * 40], *rt[N << 3], *null, *foo;

int n, m, tot;
vector<int> num;
int a[N], b[N], c[N], d[N], type[N];

void init() {
    null = foo = bar;
    null->l = null->r = null;
    foo++;
    REPP(i, 1, tot * 4) rt[i] = null;
}

bool gen(int a, int b) {
    return rand() % (a + b) < a;
}

Node* New_Node(int x) {
    return new (foo++) (Node) {null, null, x, 1};
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
        return make_pair(res.first, u->update());
    }
    else {
        PNN res = split(u->r, s - u->l->size - 1);
        u->r = res.first;
        return make_pair(u->update(), res.second);
    }
}

int find(Node *u, int num) {
    //cout << u->value << ' ' << num << endl;
    if (u == null) return 0;
    if (u->value > num) {
        return find(u->l, num);
    }
    else {
        return u->l->size + 1 + find(u->r, num);
    }
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

int dfs(int x, int p) {

}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    int t;


    return 0;
}

