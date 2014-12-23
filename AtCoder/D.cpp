#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 6005;
const int M = 100005;
const int INF = 0x3f3f3f3f;

struct MinCostFlow{
	int pre[N], dp[N];
	int fi[N], ne[M << 2], en[M << 2], cap[M << 2], cost[M << 2], edge;
	bool vis[N];
	int source, sink;

	void init(int S, int T) {
		source = S, sink = T;
		MST(fi, 0), edge = 1;
	}
	
	void _add(int x, int y, int z, int w) {
		ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z, cost[edge] = w;
	}

	void add(int x, int y, int z, int w) {
		_add(x, y, z, w);
		_add(y, x, 0, -w);
	}

	bool spfa() {
		MST(vis, 0), MST(dp, 0x3f);
		queue<int> q;
		q.push(source), vis[source] = 1, dp[source] = 0;

		while (q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
				int y = en[go];
				if (dp[y] > dp[x] + cost[go]) {
					dp[y] = dp[x] + cost[go];
					pre[y] = go;
					if (!vis[y]) {
						vis[y] = 1;
						q.push(y);
					}
				}
			}
			vis[x] = 0;
		}
		return dp[sink] != INF;
	}
	
	pair<int, int> mincost() {
		int cost = 0, flow = 0;
		while (spfa()) {
			int tmp = INF;
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				tmp = min(tmp, cap[go]);
			}
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
			}
			cost += tmp * dp[sink];
			flow += tmp;
		}
		return make_pair(cost, flow);
	}
}AC;

string mp[55];
pair<int, int> p[3];
int vis[55][55], dp[55][55], n, m;

int dx[] = {
	1, -1, 0, 0
};
int dy[] = {
	0, 0, 1, -1
};

int getid(int x, int y) {
	return x * m + y;
}

bool good(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#';
}

int bfs(pair<int, int> a) {
	int x, y;
	MST(vis, 0), MST(dp, 0);
	queue<int> q;
	q.push(p[0].first), q.push(p[0].second);
	vis[p[0].first][p[0].second] = 1;
	
	while (q.size()) {
		x = q.front(); q.pop();
		y = q.front(); q.pop();
		REP(k, 4) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (good(tx, ty) && !vis[tx][ty]) {
				vis[tx][ty] = 1;
				dp[tx][ty] = dp[x][y] + 1;
				q.push(tx), q.push(ty);
			}
		}
	}
	return dp[a.first][a.second];
}

int use[55][55];

pair<int, int> getpos(int x) {
	if (x >= n * m) x -= n * m;
	return make_pair(x / m, x % m);
}

int d1, d2;

bool can() {
	MST(vis, 0), MST(dp, 0);
	queue<int> q;
	q.push(p[0].first), q.push(p[0].second);
	vis[p[0].first][p[0].second] = 1;

	while (q.size()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		REP(i, 4) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (good(tx, ty) && !vis[tx][ty] && use[tx][ty] && mp[tx][ty] != 'a') {
				vis[tx][ty] = 1;
				dp[tx][ty] = dp[x][y] + 1;
				q.push(tx), q.push(ty);
			}
		}
	}
	return dp[p[2].first][p[2].second] == d2;
}

bool dfs(int x, int y) {
	if (x == p[1].first && y == p[1].second) return 1;
	else {
		REP(i, 4) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (good(tx, ty) && use[tx][ty] && (mp[tx][ty] == '.' || mp[tx][ty] == 'A')) {
				if (mp[tx][ty] == '.') mp[tx][ty] = 'a';
				if (can() && dfs(tx, ty)) {
					return 1;
				}
				else {
					mp[tx][ty] = '.';
				}
			}
		}
		return 0;
	}
}

void getans() {
	int *fi = AC.fi, *cap = AC.cap, *en = AC.en, *ne = AC.ne, *cost = AC.cost;
	REP(i, 2 * n * m) {
		for (int go = fi[i]; go; go = ne[go]) if (go % 2 == 0) {
			if (cap[go] == 0 && cost[go] > 0) {
				pair<int, int> tmp = getpos(i);
				use[tmp.first][tmp.second] = 1;
				tmp = getpos(en[go]);
				use[tmp.first][tmp.second] = 1;
			}
		}
	}
	dfs(p[0].first, p[0].second);
	
	REP(i, n) REP(j, m) {
		if (use[i][j] && mp[i][j] == '.') {
			mp[i][j] = 'b';
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);

	cin >> n >> m;
	REP(i, n) {
		cin >> mp[i];
	}
	AC.init(2 * n * m, 2 * n * m + 1);
	REP(i, n) {
		REP(j, m) {
			if (mp[i][j] == 'S') {
				p[0] = make_pair(i, j);
			}
			else if (mp[i][j] == 'A') {
				p[1] = make_pair(i, j);
			}
			else if ( mp[i][j] == 'B') {
				p[2] = make_pair(i, j);
			}
			int tmp = getid(i, j);
			if (mp[i][j] != 'S') {
				AC.add(tmp, tmp + n * m, 1, 0);
			}
			else {
				AC.add(tmp, tmp + n * m, 2, 0);	
			}
			if (mp[i][j] == '#' || mp[i][j] == 'A' || mp[i][j] == 'B') continue;
			REP(k, 4) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (good(x, y)) {
					AC.add(tmp + n * m, getid(x, y), 1, 1);
				}
			}
		}
	}
	AC.add(2 * n * m, getid(p[0].first, p[0].second), 2, 0);
	AC.add(getid(p[1].first, p[1].second) + n * m, 2 * n * m + 1, 1, 0);
	AC.add(getid(p[2].first, p[2].second) + n * m, 2 * n * m + 1, 1, 0);
	d1 = bfs(p[1]), d2 = bfs(p[2]);
	int dis = d1 + d2;
	pair<int, int> ans = AC.mincost();	
	if (ans.first == dis && ans.second == 2) {
		//cout << "YES" << endl;
		getans();
		REP(i, n) {
			cout << mp[i] << endl;
		}
	}
	else {
		cout << "NA" << endl;
	}
	return 0;
}

