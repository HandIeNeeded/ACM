#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
bool g[4][N][N], vis[N][N][4];
char mp[N][N];
int n, m, dp[N][N][4];

int dx[] = {
	-1, 0, 1, 0
};

int dy[] = {
	0, 1, 0, -1
};

bool good(int x, int y, int t) {
	return x >= 1 && x <= n && y >= 1 && y <= m && !g[t][x][y] && mp[x][y] != '#';
}

string str = "^>v<";

void init() {
	REP(i, 4) REPP(j, 1, n) REPP(k, 1, m) g[i][j][k] = 0;
	REP(i, 4) {
		REPP(x, 1, n) {
			REPP(y, 1, m) {
				int tmp = str.find(mp[x][y]);
				if (tmp >= 0) {
					int tx = x, ty = y;
					g[i][tx][ty] = 1;
					tx += dx[tmp], ty += dy[tmp];
					while (good(tx, ty, i) && (mp[tx][ty] == '.' || mp[tx][ty] == 'S' || mp[tx][ty] == 'G')) {
						g[i][tx][ty] = 1;
						tx += dx[tmp];
						ty += dy[tmp];
					}
					mp[x][y] = str[(tmp + 1) & 3];
				}
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int t, ca = 1;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		REPP(i, 1, n) {
			cin >> mp[i] + 1;
		}
		init();
		//REP(i, 4) {
		//	REPP(j, 1, n) {
		//		REPP(k, 1, m) {
		//			cout << g[i][j][k] << ' ';
		//		}
		//		cout << endl;
		//	}
		//	cout << endl;
		//}
		int x = -1, y = -1;
		REPP(i, 1, n) {
			REPP(j, 1, m) {
				if (mp[i][j] == 'S') {
					x = i, y = j;
					break;
				}
			}
			if (x > 0) break;
		}
		REPP(i, 1, n) {
			REPP(j, 1, m)
				REP(k, 4) {
					dp[i][j][k] = INF;
					vis[i][j][k] = 0;
				}
		}
		queue<int> q;
		dp[x][y][0] = 0, vis[x][y][0] = 1;
		q.push(x), q.push(y), q.push(0);

		int ans = INF, find = 0;
		while (q.size()) {
			x = q.front(); q.pop();
			y = q.front(); q.pop();
			int clk = q.front(); q.pop();

			REP(dir, 4) {
				int tx = x + dx[dir];
				int ty = y + dy[dir];
				int c = (clk + 1) & 3;
				if (good(tx, ty, c) && !vis[tx][ty][c]) {
					dp[tx][ty][c] = dp[x][y][clk] + 1;
					vis[tx][ty][c] = 1;
					if (mp[tx][ty] == 'G') {
						find = 1;
						ans = dp[tx][ty][c];
						break;
					}
					q.push(tx), q.push(ty), q.push(c);
				}
			}
			if (find) {
				break;
			}
		}
		cout << "Case #" << ca++ << ": ";
		if (ans == INF) {
			cout << "impossible" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}


