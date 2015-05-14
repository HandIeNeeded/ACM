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
int dep[N], pre[N][20];
int f[N], s[N];
vector<int> edge[N], val[N];
int imp, sa, sb;
int dis[N];
long long dp[N];

struct Edge{
	int x, y, z;
}e[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void dfs(int x, int p, long long now) {
	dp[x] = now;
	pre[x][0] = p;
	REPP(i, 1, 19) pre[x][i] = pre[pre[x][i - 1]][i - 1];
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != p) {
			dep[y] = dep[x] + 1;
			dfs(y, x, dp[x] + val[x][i]);
		}
	}
}

int go(int x, int step) {
	REP(i, 20) {
		if (step & (1 << i)) {
			x = pre[x][i];
		}
	}
	return x;
}

int find(int a, int b) {
	if (dep[a] > dep[b]) {
		a = go(a, dep[a] - dep[b]);
	}
	if (dep[b] > dep[a]) {
		b = go(b, dep[b] - dep[a]);
	}
	if (a == b) return a;
	int step = 19;
	while (step >= 0) {
		int ta = pre[a][step], tb = pre[b][step];
		if (ta - tb) {
			a = ta, b = tb;
		}
		step--;
	}
	return pre[a][0];
}

bool cmp(const Edge &a, const Edge &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.z < b.z);
}

long long get(int a, int b) {
	if (a == b) return 0;
	else {
		int c = find(a, b);
		long long ans = dp[a] - dp[c] + dp[b] - dp[c];
		return ans;
	}
}

long long getdis(int a, int b) {
	if (a == b) return 0;
	else {
		long long ans = get(a, b);
		long long tmp = get(a, sa) + imp + get(b, sb);
		ans = min(ans, tmp);
		tmp = get(a, sb) + imp + get(b, sa);
		ans = min(ans, tmp);
		return ans;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int n, m;
	cin >> n;
	REPP(i, 1, n) f[i] = i;
	REPP(i, 1, n) cin >> s[i];
	REPP(i, 1, n) {
		int x, y, z;
		cin >> x >> y >> z;
		e[i] = (Edge) {x, y, z};
	}
	sort(e + 1, e + n + 1, cmp);
	REPP(i, 1, n) {
		int x = e[i].x, y = e[i].y, z = e[i].z;
		int tx = find(x), ty = find(y);
		if (tx != ty) {
			f[tx] = ty;
			edge[x].push_back(y), val[x].push_back(z);
			edge[y].push_back(x), val[y].push_back(z);
		}
		else {
			imp = e[i].z, sa = e[i].x, sb = e[i].y;
		}
	}
	dfs(1, 0, 0);
	cin >> m;
	long long ans = 0;
	REPP(i, 1, m) {
		cin >> dis[i];
		ans += s[dis[i]];
		if (i > 1) ans += getdis(dis[i - 1], dis[i]);
	}
	cout << ans << endl;

	return 0;
}

