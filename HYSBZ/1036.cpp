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

const int N = 3e4 + 5;
int pre[N], pos[N], size[N], son[N], dep[N], top[N], now;
int val[N], mx[N << 2];
long long sum[N << 2];
vector<int> edge[N];

int qx, qd, ql, qr;

void maintain(int x, int l, int r) {
	mx[x] = max(mx[L], mx[R]);
	sum[x] = sum[L] + sum[R];
}

void modify(int x, int l, int r) {
	if (l == r) {
		mx[x] = sum[x] = qd;
	}
	else {
		if (qx <= MID) modify(LC);
		else modify(RC);
		maintain(x, l, r);
	}
}

long long query_sum(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return sum[x];
	}
	else {
		long long ans = 0;
		if (ql <= MID) ans += query_sum(LC);
		if (qr > MID) ans += query_sum(RC);
		return ans;
	}
}

int query_max(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mx[x];
	}
	else {
		int ans = -1000000;
		if (ql <= MID) ans = max(ans, query_max(LC));
		if (qr > MID) ans = max(ans, query_max(RC));
		return ans;
	}
}

int find_max(int a, int b) {
	int ans = -1000000;
	int fa = top[a], fb = top[b];
	while (fa - fb) {
		if (dep[fa] < dep[fb]) {
			swap(a, b), swap(fa, fb);
		}
		ql = pos[fa], qr = pos[a];
		ans = max(ans, query_max(1, 1, now));
		a = pre[fa], fa = top[a];
	}
	ql = pos[a], qr = pos[b];
	if (ql > qr) swap(ql, qr);
	ans = max(ans, query_max(1, 1, now));
	return ans;
}

long long find_sum(int a, int b) {
	long long ans = 0;
	int fa = top[a], fb = top[b];
	while (fa - fb) {
		if (dep[fa] < dep[fb]) {
			swap(a, b), swap(fa, fb);
		}
		ql = pos[fa], qr = pos[a];
		ans += query_sum(1, 1, now);
		a = pre[fa], fa = top[a];
	}
	ql = pos[a], qr = pos[b];
	if (ql > qr) swap(ql, qr);
	ans += query_sum(1, 1, now);
	return ans;
}

char s[10];
int q[N], vis[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, x, y;
	scanf("%d", &n);
	REPP(i, 1, n - 1) {
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	int l = 0, r = 0;
	q[r++] = 1;
	dep[1] = 1, pre[1] = 0, son[1] = 0, size[1] = 1;
	while (l <= r) {
		int x = q[l++];
		REP(i, edge[x].size()) {
			int y = edge[x][i];
			if (y != pre[x]) {
				q[r++] = y;
				dep[y] = dep[x] + 1;
				pre[y] = x;
				son[y] = 0, size[y] = 1;
			}
		}
	}
	for (int i = r - 1; i >= 0; i--) {
		int x = q[i];
		size[pre[x]] += size[x];
		if (size[x] > size[son[pre[x]]]) {
			son[pre[x]] = x;
		}
	}
	REP(i, r) {
		int x = q[i];
		if (vis[x]) continue;
		vis[x] = 1;
		pos[x] = ++now, top[x] = x;
		x = son[x];
		while (x) {
			vis[x] = 1;
			pos[x] = ++now;
			top[x] = top[pre[x]];
			x = son[x];
		}
	}
	REPP(i, 1, n) scanf("%d", val + i);
	REPP(i, 1, n) {
		qx = pos[i], qd = val[i];
		modify(1, 1, now);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s%d%d", s, &x, &y);
		if (s[0] == 'C') {
			qx = pos[x], qd = y;
			val[x] = y;
			modify(1, 1, now);
		}
		else if (s[1] == 'M') {
			printf("%d\n", find_max(x, y));
		}
		else {
			printf("%lld\n", find_sum(x, y));
		}
	}

	return 0;
}


