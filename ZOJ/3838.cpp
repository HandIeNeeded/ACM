#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 105;
char mp[N][N];
bool use[N][N];
int vis[30], n;

int get(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a';
	}
	else if (c == '.') {
		return 26;
	}
	else if (c == '#') {
		return 27;
	}
	else return 28;
}

void go(int x, int y) {
	int tmp = -1, tx, ty;

	tx = x, ty = n + 1 - y;
	if (!use[tx][ty]) {
		tmp = get(mp[tx][ty]);
		vis[tmp]++;
		use[tx][ty] = 1;
	}

	tx = n + 1 - x, ty = y;
	if (!use[tx][ty]) {
		tmp = get(mp[tx][ty]);
		vis[tmp]++;
		use[tx][ty] = 1;
	}

	tx = y, ty = x;
	if (!use[tx][ty]) {
		tmp = get(mp[tx][ty]);
		vis[tmp]++;
		use[tx][ty] = 1;
	}

	tx = n + 1 - y, ty = n + 1 - x;
	if (!use[tx][ty]) {
		tmp = get(mp[tx][ty]);
		vis[tmp]++;
		use[tx][ty] = 1;
	}
}

int main() {
	//freopen("I.in", "r", stdin);
	ios :: sync_with_stdio(0);
		
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		REPP(i, 1, n) {
			cin >> mp[i] + 1;
		}
		int ans = 0;
		REPP(i, 1, n) {
			REPP(j, 1, n) if (!use[i][j]) {
				MST(vis, 0);
				go(i, j);
				go(j, i);
				int tot = 0, mx = 0;
				REP(k, 28) {
					tot += vis[k];
					mx = max(vis[k], mx);
				}
				ans += tot - mx;
			}
		}
		cout << ans << endl;
		MST(use, 0);
	}
	
	return 0;
}