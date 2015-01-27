#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 10005;
const int INF = 0x3f3f3f3f;

int vis[N], dp[N], op[N], n, st, ed, ca;

int bfs(int x) {
	queue<int> q;
	MST(dp, 0x3f);
	vis[x] = ca, dp[x] = 0, q.push(x);

	while (q.size()) {
		x = q.front(), q.pop();
		REP(i, n) {
			int y = x + op[i];
			y %= 10000;
			if (vis[y] != ca) {
				dp[y] = dp[x] + 1;
				vis[y] = ca;
				q.push(y);
			}
		}
	}
	return dp[ed];
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("F.in", "r", stdin);

	while (cin >> st >> ed >> n, st | ed | n) {
		REP(i, n) cin >> op[i];
		cout << "Case " << ++ca << ": ";
		int ans = bfs(st);
		if (ans == INF) {
			cout << "Permanently Locked" << endl;
		}
		else {
			cout << ans << endl;
		}
	}

	return 0;
}
