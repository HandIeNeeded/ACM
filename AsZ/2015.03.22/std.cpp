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
int node, tot;

struct Node{
	int l, r;
	int cnt;
}tr[N * 20];

int head[N], parent[N][20], dep[N];

int New_Node() {
	tr[node].l = tr[node].r = tr[node].cnt = 0;
	return node++;
}

void update(int &now, int pre, int l, int r, int num) {
	now = New_Node();
	if (l == r) {
		tr[now].cnt = tr[pre].cnt + 1;
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
	tr[now].cnt = tr[tr[now].l].cnt + tr[tr[now].r].cnt;
}

int query(int now, int pre, int l, int r, int num) {
	if (l == r) {
		return tr[now].cnt - tr[pre].cnt;
	}
	int mid = (l + r) >> 1;
	if (mid >= num) {
		return query(tr[now].l, tr[pre].l, l, mid, num);
	}
	else {
		return query(tr[now].r, tr[pre].r, mid + 1, r, num);
	}
}

int go(int x, int step) {
	REP(i, 20) {
		if (step & (1 << i)) {
			x = parent[x][i];
		}
	}
	return x;
}

string solve(int x, int value) {
	int l = -1, r = dep[x];
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		int y = go(x, mid + 1);
		if (query(head[x], head[y], 1, tot, value) >= 1) r = mid;
		else l = mid;
	}
	int y = go(x, r);
	assert(dep[y] > 0 && dep[y] <= dep[x]);
	//cout << "answer node: " << y << endl;
	return key[y][value];
}

void bfs() {
	queue<int> q;
	q.push(1), dep[1] = 1;
	REP(i, 20) parent[1][i] = 0;
	int pre = 0;
	for (auto z: val[1]) {
		update(head[1], head[pre], 1, tot, z);
		pre = 1;
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (auto y : edge[x]) {
			pre = x;
			for (auto z : val[y]) {
				update(head[y], head[pre], 1, tot, z);
				pre = y;
			}
			q.push(y), dep[y] = dep[x] + 1;
			parent[y][0] = x;
			REPP(i, 1, 19) parent[y][i] = parent[parent[y][i - 1]][i - 1];
		}
	}
}

void goup(int x, int y) {
	int good = 0;
	while (x) {
		for (auto z: val[x]) {
			if (z == y) {
				cout << key[x][y] << endl;
				good = 1;
				break;
			}
		}
		if (good) {
			break;
		}
		else {
			x = parent[x][0];
		}
	}
	if (!good) {
		cout << "N/A" << endl;
	}
}

int main() {
	//freopen("C.in", "r", stdin);
	int n;

	scanf("%d", &n);
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
	//cout << tr[head[0]].cnt << endl;
	//cout << tr[head[1]].cnt << endl;
	//cout << "hehe" << query(head[1], head[0], 1, tot, 3) << endl;

	int q;
	cin >> q;
	while (q--) {
		int x;
		scanf("%d%s", &x, s);
		if (!mp.count(s)) {
			printf("N/A\n");
			fflush(stdout);
			continue;
		}
		int value = mp[string(s)];
		goup(x, value);
	}

	return 0;
}

