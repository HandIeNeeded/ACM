#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) a; ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define LL long long 
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
bool vis[N][N];
int pre[N], p[N];

int main() {
	// freopen("1415.in", "r", stdin);
	// freopen("1415.ans", "w", stdout);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		REPP(i, 1, n) {
			cin >> p[i];
			pre[p[i]] = i;
		}
		int ans = 0;
		REPP(i, 1, n - 1) {	
			int x = i, y = i + 1;
			while (!vis[x][y]) {
				vis[x][y] = 1;
				x = pre[x];
				y = pre[y];
			}
			x = i + 1, y = i;
			while(!vis[x][y]) {
				vis[x][y] = 1;
				x = pre[x];
				y = pre[y];
			}
		}
		REPP(i, 1, n) {
			REPP(j, 1, n) {
				if (vis[i][j]) {
					ans ++;
				}
			}
		}
		cout << ans / 2 << endl;
		MST(vis, 0), MST(pre, 0);
	}


	return 0;
}
