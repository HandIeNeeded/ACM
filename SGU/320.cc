#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 505;
vector<int> p[N * N];
int cnt[N * N];
char mp[N][N], vis[N][N];
int n, m, k;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool good(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y) {
	queue<int> q;
	q.push(x), q.push(y), id[x][y] = now, vis[x][y] = 1;
}

int main() {
    ios :: sync_with_stdio(0);
	cin >> n >> m >> k;
	int tot = 0;
	n += 2, m += 2;
	REPP(i, 1, n) {
		cin >> mp[i + 1];
	}
	REPP(i, 1, n) {
		REPP(j, 1, m) {
			if (!vis[i][j]) {
				bfs(i, j, ++tot);
			}
		}
	}
	queue<int> q;
	q.push(0), q.push(0), vis[0][0] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		bfs(x, y);
	}

    return 0;
}

