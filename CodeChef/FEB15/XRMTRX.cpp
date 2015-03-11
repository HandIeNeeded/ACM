#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 305;
const int MO = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

int pow_mod(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MO;
		y >>= 1;
		x = 1LL * x * x % MO;
	}
	return ans;
}

int t, n;
long long mp[N][N];
int dp[N][N];
bool vis[N][N];
int dx[] = {
	0, 0, -1, 1
};
int dy[] = {
	-1, 1, 0, 0
};
pair<long long, long long> query[505];

bool good(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int dfs(int x, int y, long long now) {
	if (vis[x][y]) return now;
	vis[x][y] = 1;
	int ans = now;
	REP(i, 4) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (good(tx, ty) && mp[tx][ty] == now + 1) {
			ans = max(ans, dfs(tx, ty, now + 1));
		}
	}
	return ans;
}

int go(int x, int y, long long now, long long ans) {
	if (dp[x][y] >= 0) return dp[x][y];
	if (now == ans) {
		return dp[x][y] = 1;
	}
	else {
		dp[x][y] = 0;
		REP(i, 4) {
			int tx = dx[i] + x;
			int ty = dy[i] + y;
			if (good(tx, ty) && mp[tx][ty] == now + 1) {
				add(dp[x][y], go(tx, ty, now + 1, ans));
			}
		}
		return dp[x][y];
	}
}

void solve1() {
	REP(ca, t) {
		n = query[ca].second - query[ca].first + 1;
		long long a = query[ca].first;
		for (int i = 1; i <= n; i++, a++) {
			long long b = query[ca].first;
			for (int j = 1; j <= n; j++, b++) {
				mp[i][j] = a ^ b;
				dp[i][j] = -1;
				vis[i][j] = 0;
			}
		}
		//REPP(i, 1, n) {
		//	REPP(j, 1, n) {
		//		cout << mp[i][j] << ' ';
		//	}
		//	cout << endl;
		//}
		int ans = 0, cnt = 0;
		REPP(i, 1, n) {
			REPP(j, 1, n) if (mp[i][j] == 0) {
				ans = max(ans, dfs(i, j, 0));
			}
		}
		REPP(i, 1, n) {
			if (mp[i][i] == 0) {
				add(cnt, go(i, i, 0, ans));
			}
		}
		cout << ans << ' ' << cnt << endl;
	}
}

void solve2() {

}

void solve3() {
	//to be continued.
}

int main() {
	ios :: sync_with_stdio(0);
	freopen("XRMTRX.in", "r", stdin);

	cin >> t;
	bool flag1 = t > 500;
	bool flag2 = 0;
	REP(i, t) {
		long long x, y;
		cin >> x >> y;
		query[i] = {x, y};
		flag2 = flag2 || (y - x > 300);
	}
	if (!flag1 && !flag2) {
		solve1();
	}
	else {
		assert(0);
		solve2();
	}

	return 0;
}
