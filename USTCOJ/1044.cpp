#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 20005;
const int M = 50005;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	int node, edge, source, sink;
	int lvl[N], vis[N], cur[N];
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1];
	
	void init(int S, int T, int tot) {
		source = S, sink = T, node = tot;
		MST(fi, 0), edge = 1;
	}

	void _add(int x, int y, int z) {
		ne[++edge] = fi[x];
		fi[x] = edge;
		en[edge] = y;
		cap[edge] = z;
	}

	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, 0);
	}
	
	bool bfs() {
		queue<int> q;
		MST(lvl, 0), MST(vis, 0);
		q.push(source);
		vis[source] = 1;

		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !vis[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				q.push(y);
				vis[y] = 1;
			}
		}
		return vis[sink];
	}

	int dfs(int x, int flow) {
		if (x == sink || flow == 0) {
			return flow;
		}
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				ans += tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				flow -= tmp;
				if (flow == 0) {
					return ans;
				}
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			REPP(i, 1, node) {
				cur[i] = fi[i];
			}
			ans += dfs(source, INF);
		}	
		return ans;
	}
}Flow;

int dx[] = {
	1, -1, 0, 0
};

int dy[] = {
	0, 0, 1, -1
};

int vis[105][105], mp[105][105], dis[105][105], n, m;
char s[105][105];
int sx, sy, ex, ey;

int getid(int x, int y) {
	return (x - 1) * m + y;
}

bool good(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#';
}

void bfs(int x, int y) {
	queue<int> q;
	q.push(x), q.push(y);
	MST(vis, 0), MST(dis, 0x3f);
	vis[x][y] = 1, dis[x][y] = 0;

	while (q.size()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		REP(k, 4) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (good(tx, ty) && !vis[tx][ty]) {
				vis[tx][ty] = 1;
				q.push(tx), q.push(ty);
				dis[tx][ty] = dis[x][y] + 1;
			}
		}
	}
}

bool go(int x, int y) {
	queue<int> q;
	q.push(x), q.push(y);
	MST(vis, 0);
	vis[x][y] = 1;

	while (q.size()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		REP(k, 4) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (good(tx, ty) && !vis[tx][ty]) {
				if (tx == ex && ty == ey) return 1;
				vis[tx][ty] = 1;
				q.push(tx), q.push(ty);
			}
		}
	}
	return 0;
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("cf.in", "r", stdin);

	while (cin >> n >> m, n | m) {
		REPP(i, 1, n) {
			cin >> s[i] + 1;
		}
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				if (s[i][j] == 'A') {
					sx = i, sy = j;
				}
				else if (s[i][j] == 'B') {
					ex = i, ey = j;
				}
			}
		}
		Flow.init(getid(sx, sy), getid(ex, ey) + n * m, 2 * n * m);
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				int x = getid(i, j);
				if (s[i][j] == 'A' || s[i][j] == 'B' || s[i][j] == '.') {
					Flow.add(x, x + n * m, INF);
				}
				else if (s[i][j] == '*') {
					Flow.add(x, x + n * m, 1);
				}
				if (s[i][j] != '#') {
					REP(k, 4) {
						int tx = i + dx[k];
						int ty = j + dy[k];
						int y = getid(tx, ty);
						if (good(tx, ty)) {
							Flow.add(x + n * m, y, INF);
						}
					}
				}
			}
		}
		int ans = Flow.dinic();
		if (ans != 1) {
			cout << "No solution." << endl;
		}
		else {
			bfs(sx, sy);
			pair<int, int> res = make_pair(ex, ey);
			REPP(i, 1, n) {
				REPP(j, 1, m) {
					if (s[i][j] == '*' && dis[i][j] < dis[res.first][res.second]) {
						s[i][j] = '#';
						if (go(sx, sy)) {
							s[i][j] = '*';
							continue;
						}
						res = make_pair(i, j);
						s[i][j] = '*';
					}
				}
			}
			if (res == make_pair(ex, ey)) {
				cout << "No solution." << endl;
			}
			else {
				cout << res.first << ' ' << res.second << endl;
			}
		}
	}
	return 0;
}

