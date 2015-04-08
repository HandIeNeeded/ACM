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

const int N = 2e5 + 5;

struct Node{
	int value, size;
	Node *l, *r;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N], *foo, *rt[N], *null;

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

pair<int, bool> find(Node *u, int x) {
	//cout << u << ' ' << x << endl;
	if (u == null) return {0, 0};
	if (u->value == x) {
		return {u->l->size + 1, 1};
	}
	else if (u->value < x) {
		pair<int, bool> res = find(u->r, x);
		res.first += u->l->size + 1;
		return res;
	}
	else {
		return find(u->l, x);
	}
}

void insert(Node *a, Node *&u) {
	//show(a);
	//cout << "*********************************" << endl;
	pair<int, bool> ans = find(u, a->value);
	if (!ans.second) {
		PNN res = split(u, ans.first);
		u = a;
		u = merge(res.first, u);
		u = merge(u, res.second);
	}
}

Node* combine(Node *a, Node *b) {
	if (a->size > b->size) {
		swap(a, b);
	}
	int tot = a->size;
	REP(i, tot) {
		PNN tmp = split(a, 1);
		a = tmp.second;
		insert(tmp.first, b);
	}
	return b;
}

char buffer[N], query[N << 1];
pair<int, int> range[N];
int ans[N];
vector<int> num[N], edge[N];
vector<int> id[N];

void dfs(int x) {
	rt[x] = null;
	for (auto y: edge[x]) {
		dfs(y);
		rt[x] = combine(rt[x], rt[y]);
	}
	REP(i, num[x].size()) {
		insert(New_Node(num[x][i]), rt[x]);
	}
	for (auto y: id[x]) {
		int l, r;
		tie(l, r) = range[y];
		ans[y] = find(rt[x], r).first - find(rt[x], l - 1).first;
	}
	//cout << "node: " << x << endl;
	//show(rt[x]);
	//cout << "****************************************" << endl;
}

struct AC_Automation {
	int tr[N][2], fail[N], node;

	int New_Node() {
		tr[node][0] = tr[node][1] = 0;
		fail[node] = 0;
		return node++;
	}

	void init() {
		node = 0;
		New_Node();
	}

	void insert(char *s, int i) {
		int now = 0, pos = 0;
		while (s[pos]) {
			int x = s[pos++] - 'a';
			if (!tr[now][x]) tr[now][x] = New_Node();
			now = tr[now][x];
		}
		id[now].push_back(i);
	}

	void go(char *s, int &pos, int i) {
		int now = 0;
		while (s[pos]) {
			int x = s[pos++] - 'a';
			now = tr[now][x];
			num[now].push_back(i);
		}
		pos++;
	}

	void build() {
		queue<int> q;
		REP(i, 2) {
			if (tr[0][i]) {
				edge[0].push_back(tr[0][i]);
				q.push(tr[0][i]);
				fail[tr[0][i]] = 0;
			}
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			REP(i, 2) {
				if (!tr[x][i]) {
					tr[x][i] = tr[fail[x]][i];
					continue;
				}
				int y = tr[x][i];
				fail[y] = tr[fail[x]][i];
				edge[tr[fail[x]][i]].push_back(y);
				q.push(y);
			}
		}
	}
}AC;

int main() {
	//freopen("tmp.in", "r", stdin);
	int n, q, pos = 0, now = 0;
	scanf("%d%d", &n, &q);
	REPP(i, 1, n) {
		scanf("%s", buffer);
		now = 0;
		while (buffer[now]) {
			query[pos++] = buffer[now];
			now++;
		}
		query[pos++] = 0;
	}
	AC.init();
	init();
	REPP(i, 1, q) {
		int x, y;
		scanf("%d%d%s", &x, &y, buffer);
		AC.insert(buffer, i);
		range[i] = {x, y};
	}
	AC.build();
	//REP(i, AC.node) {
	//	cout << AC.fail[i] << ' ';
	//}
	//cout << endl;
	pos = 0, now = 1;
	while (now <= n) {
		AC.go(query, pos, now++);
	}
	for (auto y: edge[0]) {
		dfs(y);
	}
	REPP(i, 1, q) {
		printf("%d\n", ans[i]);
	}
	//printf("%.10f\n", 1.0 * (clock() - st) / CLOCKS_PER_SEC);
	return 0;
}
