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

using namespace std;

const int N = 1e5 + 5;
int val[N], son[N][2];

struct Node{
	Node *l, *r;
	int size, val;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}*rt[N], bar[N], *null, *foo;

void init() {
	foo = null = bar;
	null->l = null->r = null;
	foo++;
}

Node* New_Node(int x) {
	foo->val = x, foo->size = 1;
	foo->l = foo->r = null;
	return foo++;
}

bool gen(int a, int b) {
	return rand() % (a + b) < a;
}

#define PNN pair<Node*, Node*>

PNN split(Node* u, int s) {
	if (u == null) return {u, u};
	if (u->l->size >= s) {
		PNN res = split(u->l, s);
		u->l = res.second;
		return {res.first, u->update()}; 
	}
	else {
		PNN res = split(u->r, s - u->l->size - 1);
		u->r = res.first;
		return {u->update(), res.second};
	}
}

Node* merge(Node* a, Node* b) {
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

int find(Node* u, int x) {
	if (u == null) return 0;
	else if (u->val <= x) {
		return u->l->size + 1 + find(u->r, x);
	}
	else return find(u->l, x);
}

int dp[N][2];

void show(Node* u) {
	if (u == null) return ;
	show(u->l);
	cout << u->val << endl;
	show(u->r);
}

void dfs(int x) {
	//cout << x << endl;
	rt[x] = New_Node(val[x]);
	dp[x][0] = dp[x][1] = 0;
	if (son[x][0]) {
		dfs(son[x][0]);
		if (val[x] > val[son[x][0]]) {
			int tot = find(rt[son[x][0]], val[x] - 1);
			PNN res = split(rt[son[x][0]], tot);
			rt[x] = merge(res.first, rt[x]);
		}
		dp[x][0] = max(dp[son[x][0]][0], dp[son[x][0]][1]);
	}
	if (son[x][1]) {
		dfs(son[x][1]);
		if (val[x] < val[son[x][1]]) {
			int tot = find(rt[son[x][1]], val[x]);
			PNN res = split(rt[son[x][1]], tot);
			rt[x] = merge(rt[x], res.second);
		}
		dp[x][0] = max(dp[x][0], dp[son[x][1]][0]);
		dp[x][0] = max(dp[x][0], dp[son[x][1]][1]);
	}
	dp[x][1] = rt[x]->size;
	//cout << x << "hehe" << endl;
	//show(rt[x]);
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("E.in", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REPP(i, 1, n) {
			int x, y, z;
			cin >> x >> y >> z;
			son[i][0] = x, son[i][1] = y;
			val[i] = z;
		}
		init();
		dfs(1);
		cout << max(dp[1][1], dp[1][0]) << endl;
	}

	return 0;
}

