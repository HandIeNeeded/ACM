#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100;
int dp[N], vis[N], mp[4][4];

bool good(int x) {
	if (x == 0) return mp[3][1];
	x--;
	return mp[x / 3][x % 3];
}

void spfa(int st) {
	queue<int> q;
	q.push(st), dp[st] = 0, vis[st] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		int y = (x + 1) % 100;
		if (mp[0][3] && dp[y] > dp[x] + 1) {
			dp[y] = dp[x] + 1;
			if (!vis[y]) q.push(y), vis[y] = 1;
		}
		y = (x + 99) % 100;
		if (mp[1][3] && dp[y] > dp[x] + 1) {
			dp[y] = dp[x] + 1;
			if (!vis[y]) q.push(y), vis[y] = 1;
		}
		REP(i, 10) {
			if (good(i) && dp[i] > dp[x] + 1) {
				dp[i] = dp[x] + 1;
				if (!vis[i]) q.push(i), vis[i] = 1;
			}
		}
		REPP(a, 1, 9) {
			REPP(b, 0, 9) {
				if (mp[3][0] && good(a) && good(b) && dp[10 * a + b] > dp[x] + 3) {
					dp[10 * a + b] = dp[x] + 3;
					if (!vis[10 * a + b]) q.push(10 * a + b), vis[10 * a + b] = 1;
				}
			}
		}
		vis[x] = 0;
	}
}

int main() {
    ios :: sync_with_stdio(0);
	REP(i, 2) {
		REP(j, 4) cin >> mp[i][j];
	}
	REP(j, 3) cin >> mp[2][j];
	REP(j, 2) cin >> mp[3][j];
	int start, end;
	cin >> start >> end;
	MST(dp, 0x3f);
	spfa(start);
	if (dp[end] == 0x3f3f3f3f) dp[end] = -1;
	cout << dp[end] << endl;
    return 0;
}
