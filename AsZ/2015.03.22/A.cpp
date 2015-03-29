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
const int INF = 0x3f3f3f3f;

int f[N], g[N], col[N], tmp[N], size[N];
int n, m, q, len, L, R, flag;
vector<int> set[N];
int ans[N];

inline int id(int x) {
	return x / len;
}

void init(int n) {
	flag = 0;
	REPP(i, 1, n) {
		f[i] = g[i] = i;
		col[i] = 0, size[i] = 1;
		set[i].clear();
		set[i].push_back(i);
	}
}

int find(int x) {
	return g[x] == x ? x : g[x] = find(g[x]);
}

int merge(int x, int y, int ty) {
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		bool flag = col[x] == col[y];
		if (set[fx].size() < set[fy].size()) {
			for (auto id: set[fx]) {
				set[fy].push_back(id);
				if (flag) col[id] ^= 1;
			}
			g[fx] = fy;
			if (ty) {
				f[fx] = fy;
				size[fy] += size[fx];
			}
		}
		else {
			for (auto id: set[fy]) {
				set[fx].push_back(id);
				if (flag) col[id] ^= 1;
			}
			g[fy] = fx;
			if (ty) {
				f[fy] = fx;
				size[fx] += size[fy];
			}
		}
		return 1;
	}
	else {
		if (col[x] == col[y]) {
			return 0;
		}
		else return 1;
	}
}

int recover(int x) {
	if (f[x] == x) {
		g[x] = x;
	}
	else {
		f[x] = g[x] = recover(f[x]);
	}
	while (int(set[x].size()) > size[x]) {
		set[x].pop_back();
	}
	return f[x];
}

pair<int, int> edge[N], query[N];
string str[2] = {"Impossible", "Possible"};

int answer(int l, int r) {
	int now = id(l), pre = id(L);
	int ans = 1;
	if (now != pre) {
		L = INF, R = -INF;
		init(n);
	}
	if (flag) return 0;
	REPP(i, max(R, (now + 1) * len), r) {
		if (!merge(edge[i].first, edge[i].second, 1)) {
			flag = 1, ans = 0;
			break;
		}
	}
	L = l, R = r;
	if (flag) return 0;
	int stop = min(r, (now + 1) * len - 1);
	REPP(i, l, stop) {
		if (!merge(edge[i].first, edge[i].second, 0)) {
			stop = i;
			ans = 0;
			break;
		}
	}
	REPP(i, l, stop) {
		recover(edge[i].first);
		recover(edge[i].second);
	}
	return ans;
}

bool cmp(const int &i, const int &j) {
	int x = id(query[i].first), y = id(query[j].first);
	if (x == y) {
		return query[i].second < query[j].second;
	}
	else {
		return x < y;
	}
}

int main() {
	//freopen("A.in", "r", stdin);
	ios :: sync_with_stdio(0);
	cin >> n >> m >> q;
	len = int(sqrt(m + 0.5));
	REPP(i, 1, m) {
		int x, y;
		cin >> x >> y;
		edge[i - 1] = {x, y};
	}
	REPP(i, 1, q) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		query[i] = {x, y};
	}
	REPP(i, 1, q) tmp[i] = i;
	sort(tmp + 1, tmp + q + 1, cmp);
	L = INF, R = -INF;
	REPP(i, 1, q) {
		ans[tmp[i]] = answer(query[tmp[i]].first, query[tmp[i]].second);
	}
	REPP(i, 1, q) {
		cout << str[ans[i]] << endl;
	}

	return 0;
}
