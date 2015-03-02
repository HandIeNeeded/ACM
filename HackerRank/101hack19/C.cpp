#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 100005;
int ne[N << 1], fi[N], en[N << 1], edge;
int dp[2][N], dep[N];
int n, m, st, ed, rad;
bool vis[N];

void add(int x, int y) {
	ne[++edge] = fi[x], en[edge] = y, fi[x] = edge;
}

void bfs() {
	queue<int> q;
	
	MST(dep, 0), MST(vis, 0);
	dep[1] = 0;
	vis[1] = 1;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (!vis[y]) {
				dep[y] = dep[x] + 1;
				vis[y] = 1;
				q.push(y);
			}
		}
	}

	// REPP(i, 1, n) {
	// 	cout << i << ' ' << dep[i] << endl;
	// }

	int mx = -1;
	st = -1;
	REPP(i, 1, n) {
		if (dep[i] > mx) {
			mx = dep[i];
			st = i;
		}
	}

	MST(dep, 0), MST(vis, 0);
	dep[st] = 0;
	vis[st] = 1;
	q.push(st);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (!vis[y]) {
				dep[y] = dep[x] + 1;
				vis[y] = 1;
				q.push(y);
			}
		}
	} 

	mx = -1, ed = -1;
	REPP(i, 1, n) {
		if (dep[i] > mx) {
			mx = dep[i];
			ed = i;
		}
	}
	REPP(i, 1, n) dp[0][i] = dep[i];

	MST(dep, 0), MST(vis, 0);
	dep[ed] = 0;
	vis[ed] = 1;
	q.push(ed);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (!vis[y]) {
				dep[y] = dep[x] + 1;
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	REPP(i, 1, n) dp[1][i] = dep[i];
	rad = dp[0][ed];
}

int main() {
	//freopen("cf.in", "r", stdin);
	ios :: sync_with_stdio(0);

	int x, y;
	cin >> n >> m;
	REPP(i, 1, n - 1) {
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	bfs();
	//cout << st << ' ' << ed << endl;

	while (m--) {
		cin >> x >> y;
		y--;
		LL ans = max(dp[0][x], dp[1][x]);
		ans += 1LL * y * rad;
		cout << ans << endl;
	}	

	return 0;
}