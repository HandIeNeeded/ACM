#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
char mp[N][N], vis[N][N];
int dx[] = {
	0, 0, 1, -1
};
int dy[] = {
	1, -1, 0, 0
};

int n, m;
bool good(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
    ios :: sync_with_stdio(0);
	cin >> n >> m;
	REPP(i, 1, n) {
		cin >> (mp[i] + 1);
	}
	queue<int> q;
	int ans = 0;
	REPP(i, 1, n) {
		REPP(j, 1, m) {
			if (mp[i][j] == 'X' && !vis[i][j]) {
				vis[i][j] = 1;
				q.push(i), q.push(j);
				ans++;
				while (q.size()) {
					int x = q.front(); q.pop();
					int y = q.front(); q.pop();
					REP(dir, 4) {
						int tx = x + dx[dir];
						int ty = y + dy[dir];
						if (!good(tx, ty) || vis[tx][ty]) continue;
						REP(r, 4) {
							int sx = tx + dx[r];
							int sy = ty + dy[r];
							//sx = i && sy = j wrong
							if (!good(sx, sy) || (sx == x && sy == y)) continue;
							if (vis[sx][sy]) {
								ans++;
								vis[tx][ty] = 1;
								q.push(tx), q.push(ty);
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}

