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

struct Node{
	int value, size, id;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N * 15], *foo, *rt, *null;

void init() {
	foo = null = bar;
	null->l = null->r = null;
	foo++;
}

Node* New_Node(int x, int y) {
	return new(foo++) (Node) {x, 1, y, null, null};
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

void show(Node *u, vector<int> &ans) {
	if (u == null) return ;
	else {
		show(u->l, ans);
		ans.push_back(u->id);
		show(u->r, ans);
	}
}

int find(Node *u, int x) {
	if (u == null) return 0;
	if (u->value <= x) {
		return u->l->size + 1 + find(u->r, x);
	}
	else return find(u->l, x);
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

void dfs(Node *a, Node *&b) {
	if (a == null) return ;
	else {
		dfs(a->l, b);
		dfs(a->r, b);
		a->l = a->r = null;
		insert(a->update(), b);
	}
}

Node* combine(Node *a, Node *b) {
	if (a->size > b->size) {
		swap(a, b);
	}
	dfs(a, b);
	return b;
}

struct point{
	int a, b, id;
}p[N];

bool cmp(point a, point b) {
	return a.a > b.a || (a.a == b.a && a.b > b.b);
}

int main() {
	ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	REPP(i, 1, n) {
		int x, y;
		cin >> x >> y;
		p[i] = {x, y, i};
	}
	sort(p + 1, p + n + 1, cmp);
	rt = null, init();
	REPP(i, 1, n) {
		Node* tmp = New_Node(p[i].b, p[i].id);
		int tot = find(rt, p[i].b);
		if (tot == rt->size) {
			insert(rt, tmp);
			cout << "hehe" << endl;
		}
	}
	vector<int> ans;
	show(rt, ans);
	sort(ans.begin(), ans.end());
	REP(i, ans.size()) {
		cout << ans[i] << ' ';
	}
	cout << endl;

	return 0;
}

