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

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define end en

using namespace std;

const int N = 2e5 + 5;
int dep[N], start[N], end[N], head[N], cnt[N], edge = 1, now = 1;
int mi[N << 2], flag[N << 2];

struct Edge{
	int y, next, type;
}e[N << 1];

void add(int x, int y, int z) {
	e[++edge].next = head[x], head[x] = edge, e[edge].y = y, e[edge].type = z;
}

void gao(int x, int p = 0, int tot = 0) {
	start[x] = now++, dep[x] = dep[p] + 1, cnt[now - 1] = tot - (dep[x] >> 1);
	for (int go = head[x]; go; go = e[go].next) {
		int y = e[go].y;
		if (y != p) {
			gao(y, x, tot + e[go].type);
		}
	}
	end[x] = now - 1;
}

int ql, qr, qd;

void build(int x, int l, int r) {
	if (l == r) mi[x] = cnt[l], flag[x] = 0;
	else {
		build(LC), build(RC);
		mi[x] = min(mi[L], mi[R]);
		flag[x] = 0;
	}
}

void push(int x, int l, int r) {
	flag[L] += flag[x], flag[R] += flag[x];
	mi[L] += flag[x], mi[R] += flag[x];
	flag[x] = 0;
}

void update(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		flag[x] += 1;
		mi[x] += 1;
	}
	else {
		if (flag[x]) push(x, l, r);
		if (ql <= MID) update(LC);
		if (qr > MID) update(RC);
		mi[x] = min(mi[L], mi[R]);
	}
}

int query(int x, int l, int r) {
	if (ql <= l && qr >= r) {
		return mi[x];
	}
	else {
		if (flag[x]) push(x, l, r);
		int ans = INT_MAX;
		if (ql <= MID) ans = min(ans, query(LC));
		if (qr > MID) ans = min(ans, query(RC));
		return ans;
	}
}

vector<int> ans;

void dfs(int x, int p = 0) {
	for (int go = head[x]; go; go = e[go].next) {
		int y = e[go].y;
		if (y != p) {
			ql = start[y], qr = end[y];
			int tmp = query(1, 1, now);
			if (tmp < 0) {
				if (e[go].type == 0) {
					ans.push_back(go >> 1);
					update(1, 1, now);
				}
				dfs(y, x);
			}
		}
	}
}

int main() {
    ios :: sync_with_stdio(0);
	//freopen("321.in", "r", stdin);
	int n;
	cin >> n;
	REP(i, n - 1) {
		int x, y, z;
		string tmp;
		cin >> x >> y >> tmp;
		if (tmp[0] == 'a') {
			z = 0;
			cin >> tmp;
		}
		else {
			z = 1;
		}
		add(x, y, z), add(y, x, z);
	}
	gao(1);
	now--;
	//REPP(i, 1, n) {
	//	cout << i << ' ' << start[i] << ' ' << end[i] << ' ' << dep[i] << endl;
	//}
	build(1, 1, now);
	dfs(1);
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i] << " \n"[i == int(ans.size() - 1)];
	}

    return 0;
}

