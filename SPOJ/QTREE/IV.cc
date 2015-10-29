#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int> > e[N];
int n;

struct Edge{
	int y, next, dist;
}edge[N << 7];
bool ban[N << 7];

int tot, node, start[N << 1], head[N << 1];

void add(int x, int y, int z) {
	edge[++tot].next = start[x], start[x] = tot, edge[tot].y = y, edge[tot].dist = z;
}

void _add(int x, int y, int z) {
	edge[++tot].next = head[x], head[x] = tot, edge[tot].y = y, edge[tot].dist = z;
}

void build(vector<pair<int, int> > &tmp, int x, int l, int r) {
	if (l == r) {
		add(x, tmp[l - 1].first, tmp[l - 1].second);
		add(tmp[l - 1].first, x, tmp[l - 1].second);
		return ;
	}
	int mid = (l + r) >> 1, lson = node++, rson = node++;
	add(x, lson, 0), add(x, rson, 0);
	add(lson, x, 0), add(rson, x, 0);
	build(tmp, lson, l, mid), build(tmp, rson, mid + 1, r);
}

void dfs(int x, int p) {
	vector<pair<int, int> > tmp;
	REP(i, e[x].size()) {
		if (e[x][i].first != p) {
			tmp.push_back(e[x][i]);
		}
	}
	if (tmp.size()) build(tmp, x, 1, tmp.size());
	REP(i, tmp.size()) {
		dfs(tmp[i].first, x);
	}
}

void prepare() {
	node = n + 1, tot = 0, edge = 1;
	dfs(1, 0);
}

int size[N << 1], diff[N << 2], E;

void dfs_size(int x, int tot, int p) {
	size[x] = 1, diff[x] = N;
	for (int go = start[x]; go; go = e[go].next) if (!ban[go]) {
		int y = e[go].y;
		if (!vis[y] && y != p) {
			dfs_size(y, tot, x);
			if (diff[y] < diff[0]) {
				E = go;
				diff[0] = diff[y];
			}
			size[x] += size[y];
		}
	}
	diff[x] = abs(tot - 2 * size[x]);
}

void dfs_dist(int rt, int x, int dep = 0) {
	_add(rt, x, dep), _add(x, rt, dep);
	for (int go = start[go]; go; go = e[go].next) if (!ban[go]) {
		int y = e[go].y;
		dfs_dist(y, x, dep + e[go].dist);
	}
}

void divide(int x) {
	diff[0] = N, E = 0;
	dfs_size(x);
	ban[E] = ban[E ^ 1] = 1;
	dfs_dist(e[E].y, e[E].y), dfs_dist(e[E ^ 1].y, e[E ^ 1].y);
	divide(e[E].y), divide(e[E ^ 1].y);
}

#define PII pair<int, int>
priority_queue<PII, vector<PII>, greater<PII> > q[N << 1];
int col[N << 1], answer;

void update(int x) {
	if (col[x] == 0) {
		q[x].push({0, x});
		answer = max(answer, 0);
	}
}

int main() {
	freopen("IV.in", "r", stdin);
	scanf("%d", &n);
	REP(i, n - 1) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[x].push_back(make_pair(y, z));
		e[y].push_back(make_pair(x, z));
	}
	prepare();
	//cout << node << endl;
	int Q;
	scanf("%d", &Q);
	int cnt = n;
	answer = -0x3f3f3f3f;
	REPP(i, 1, n) update(i);
	while (Q--) {
		char c;
		scanf("%c", &c);
		if (c == 'A') {
			if (!cnt) {
				cout << "They have disappeared." << endl;
			}
			else {
				cout << answer << endl;
			}
		}
		else {
			int x;
			scanf("%d", &x);
			if (col[x]) cnt++;
			else cnt--;
			col[x] ^= 1;
			update(x);
		}
	}
    return 0;
}

