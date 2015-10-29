#include <bits/stdc++.h>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LB(x) ((x) & (-(x)))

using namespace std;

const int N = 5e5 + 5;

struct Node{
	Node *l, *r;
	int value;
	short size;

	Node* update() {
		size = l->size + 1 + r->size;
		return this;
	}
}bar[N * 6], *foo, *null, *rt[N];

#define PNN pair<Node*, Node*>

void init(int tot) {
	null = foo = bar;
	null->l = null->r = null;
	REPP(i, 1, tot) rt[i] = null;
	foo++;
}

Node* New_Node(int x) {
	return new (foo++) (Node) {null, null, x, 1};
}

bool gen(int a, int b) {
	return rand() % (a + b) < a;
}

PNN split(Node *u, int s) {
	if (u == null) return {null, null};
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

pair<int, bool> find(Node *u, int num) {
	if (u == null) return {0, 0};
	else {
		if (u->value > num) {
			return find(u->l, num);
		}
		else {
			pair<int, bool> tmp = find(u->r, num);
			tmp.first += u->l->size + 1;
			tmp.second |= u->value == num;
			return tmp;
		}
	}
}

void insert(Node *&u, Node *a) {
	int tmp = find(u, a->value).first;
	PNN res = split(u, tmp);
	u = a;
	u = merge(res.first, u);
	u = merge(u, res.second);
}

void erase(Node *&u, int num) {
	pair<int, bool> tmp = find(u, num);
	if (tmp.second) {
		PNN res = split(u, tmp.first - 1);
		PNN res2 = split(res.second, 1);
		u = merge(res.first, res2.second);
	}
}

int type[N], L[N], R[N], tot, n;
char s[3];

int query(int pos, int num) {
	int ans = 0;
	while (pos) {
		ans += rt[pos]->size - find(rt[pos], num - 1).first;
		pos -= LB(pos);
	}
	return ans;
}

int count(int pos, int num) {
	int ans = 0;
	while (pos) {
		ans += find(rt[pos], num).first - find(rt[pos], num - 1).first;
		pos -= LB(pos);
	}
	return ans;
}

void insert(int pos, int num) {
	while (pos <= tot) {
		Node* tmp = New_Node(num);
		insert(rt[pos], tmp);
		pos += LB(pos);
	}
}

void erase(int pos, int num) {
	int tmp = count(pos, num) - count(pos - 1, num);
	if (tmp) {
		while (pos <= tot) {
			erase(rt[pos], num);
			pos += LB(pos);
		}
	}
}

int main() {
	//freopen("tmp.in", "r", stdin);
	vector<int> num;
	int x, y;
	while(scanf("%s%d%d", s, &x, &y) > 0) {
		n++;
		num.push_back(x), num.push_back(y);
		L[n] = x, R[n] = y, type[n] = s[0] == '+';
	}
	sort(num.begin(), num.end());
	num.resize(unique(num.begin(), num.end()) - num.begin());
	tot = num.size();
	init(tot);
	REPP(i, 1, n) {
		L[i] = lower_bound(num.begin(), num.end(), L[i]) - num.begin() + 1;
		R[i] = lower_bound(num.begin(), num.end(), R[i]) - num.begin() + 1;
	}
	REPP(i, 1, n) {
		if (type[i] == 1) {
			printf("%d\n", query(R[i], L[i]) - query(L[i] - 1, L[i]));
			insert(R[i], L[i]);
		}
		else {
			erase(R[i], L[i]);
		}
	}

    return 0;
}

