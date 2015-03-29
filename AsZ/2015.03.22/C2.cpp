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

const int N = 3e5 + 5;
map<string, int> mp;
map<int, string> key[N << 2];
char s[N];
vector<int> edge[N], val[N];
int node, tot, timer, step;

struct Node{
	int l, r;
	int last;
}tr[N * 20];

int head[N], parent[N][20], dep[N];

int New_Node() {
	tr[node].l = tr[node].r = tr[node].last = 0;
	return node++;
}

void update(int &now, int pre, int l, int r, int num) {
	now = New_Node();
	if (l == r) {
		tr[now].last = timer;
		return ;
	}
	int mid = (l + r) >> 1;
	if (mid >= num) {
		update(tr[now].l, tr[pre].l, l, mid, num);
		tr[now].r = tr[pre].r;
	}
	else {
		update(tr[now].r, tr[pre].r, mid + 1, r, num);
		tr[now].l = tr[pre].l;
	}
}

int query(int now, int l, int r, int num) {
	if (l == r) {
		return tr[now].last;
	}
	int mid = (l + r) >> 1;
	if (mid >= num) {
		return query(tr[now].l, l, mid, num);
	}
	else {
		return query(tr[now].r, mid + 1, r, num);
	}
}

int go(int x, int go) {
	REP(i, step) if (go) {
		if (go & (1 << i)) {
			x = parent[x][i];
			go &= go - 1;
		}
	}
	return x;
}

string solve(int x, int step, int value) {
	int y = go(x, step);
	return key[y][value];
}

void bfs() {
	queue<int> q;
	q.push(1), dep[1] = 1;
	REP(i, step) parent[1][i] = 0;
	for (auto z: val[1]) {
		timer = dep[1];
		update(head[1], head[1], 1, tot, z);
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (auto y : edge[x]) {
			head[y] = head[x];
			q.push(y), dep[y] = dep[x] + 1;
			for (auto z : val[y]) {
				timer = dep[y];
				update(head[y], head[y], 1, tot, z);
			}
			parent[y][0] = x;
			REPP(i, 1, step - 1) parent[y][i] = parent[parent[y][i - 1]][i - 1];
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	step = int(log(n + 0.5) / log(2.0)) + 1;
	tot = 1;
	REPP(i, 1, n) {
		int p, cnt;
		scanf("%d%d", &p, &cnt);
		edge[p].push_back(i);
		REP(j, cnt) {
			scanf("%s", s);
			string tmp = string(s);
			int pos = tmp.find('=');
			string a = tmp.substr(0, pos);
			string b = tmp.substr(pos + 1);
			if (!mp.count(a)) mp[a] = tot++;
			val[i].push_back(mp[a]);
			key[i][mp[a]] = b;
		}
	}
	tot--;
	head[0] = New_Node();
	bfs();

	int q;
	scanf("%d", &q);
	while (q--) {
		int x;
		scanf("%d%s", &x, s);
		int value;
		if (mp.count(s) == 0) {
			printf("N/A\n");
			fflush(stdout);
			continue;
		}
		else {
			value = mp[s];
		}
		int last = query(head[x], 1, tot, value);
		if (last == 0) {
			printf("N/A\n");
			fflush(stdout);
			continue;
		}
		printf("%s\n", solve(x, dep[x] - last, value).c_str());
		fflush(stdout);
	}

	return 0;
}



