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

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

using namespace std;

const int N = 1e5 + 5;
map<int, int> mp[N << 2];
vector<int> edge[N];
int sum[N << 2], vis[N], pre[N], col[N], pos[N], st[N], en[N];
int ans;

void bfs() {
	int now = 1;
	queue<int> q;
	q.push(1), vis[1] = 1, pos[1] = 1, pre[1] = 0;
	while (q.size()) {
		int x = q.front(); q.pop();
		st[x] = now;
		REP(i, edge[x].size()) {
			int y = edge[x][i];
			if (!vis[y]) {
				pre[y] = x;
				q.push(y), vis[y] = 1, pos[y] = ++now;
			}
		}
		en[x] = now;
	}
}

int ql, qr, qx, qd, add;

void build(int x, int l, int r) {
	mp[x].clear();
	if (l == r) mp[x][0] = 1;
	else {
		build(LC), build(RC);
		mp[x][0] = r - l + 1; 
	}
}

int common, diff;

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mp[x][qd];
	}
	else {
		int ans = 0;
		if (ql <= MID) ans += query(LC);
		if (qr > MID) ans += query(RC);
		return ans;
	}
}

void modify(int x, int l, int r) {
	if (l == r) {
		mp[x][qd] += add;
	}
	else {
		mp[x][qd] += add;
		if (qx <= MID) modify(LC);
		else modify(RC);
	}
}

int main() {
	int t, ca = 1;
	scanf("%d", &t);
	while(t--) {
		int n, q;
		scanf("%d", &n);
		REPP(i, 1, n) col[i] = 0, edge[i].clear();
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		bfs();
		build(1, 1, n);
		scanf("%d", &q);
		printf("Case #%d:\n", ca++);
		ans = 1;
		while (q--) {
			int ty;
			scanf("%d", &ty);
			if (ty == 1) {
				printf("%d\n", ans);
			}
			else {
				int x, y;
				scanf("%d%d", &x, &y);
				common = diff = 0;
				ql = st[x] + 1, qr = en[x], qd = col[x];
				cout << ql << ' ' << qr << endl;
				common = query(1, 1, n);
				if (col[pre[x]] == col[x] && pre[x]) common++;
				qx = pos[x], qd = col[x], add = -1;
				modify(1, 1, n);
				qx = pos[x], qd = col[x] = y, add = 1;
				modify(1, 1, n);
				ql = st[x] + 1, qr = en[x], qd = col[x];
				diff = query(1, 1, n);
				if (col[pre[x]] == col[x]) diff++;
				ans += common - diff;
				cout << "hehe" << ans << endl;
			}
		}
	}
	return 0;
}

