#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 5e6 + 5;
const int MO = 1e9 + 7;

char s[N];
int dp[N >> 3][2][10];
int g[16][1 << 15][2][10];
int f[16][1 << 15][2][10];
int n, m;

void add(int &x, int y) {
	x += y;
	if (x >= MO) x -= MO;
}

void calc(int now, int st, int limit) {
	int ban = st & (1 << (now - 1));
	if (now * 2 > limit) {
		g[now][st][0][0] = 1;
		if (!ban) {
			REPP(i, 1, m) g[now][st][1][i] = 1;
		}
		else {
			REPP(i, 1, m) g[now][st][1][i] = 0;
		}
	}
	else {
		calc(2 * now, st, limit);
		if (2 * now + 1 <= limit) calc(2 * now + 1, st, limit);
		if (2 * now + 1 > limit) {
			REPP(i, 0, m) {
				REP(j, 2) {
					add(g[now][st][0][i], g[2 * now][st][j][i]);
				}
			}
			if (!ban) {
				int pre = g[2 * now][st][0][0];
				REPP(i, 1, m) {
					g[now][st][1][i] = pre;
					add(pre, g[2 * now][st][0][i]);
				}
			}
			else {
				REPP(i, 1, m) g[now][st][1][i] = 0;
			}
		}
		else {
			REPP(i, 0, m) {
				REPP(j, 0, i) {
					REP(k, 2) {
						REP(t, 2) {
							add(g[now][st][0][i], 1LL * g[2 * now][st][k][j] * g[2 * now + 1][st][t][i - j] % MO);
						}
					}
				}
			}
			if (!ban) {
				REPP(i, 0, m) {
					REPP(j, 0, i) {
						add(g[now][st][1][i], 1LL * g[2 * now][st][0][j] * g[2 * now + 1][st][0][i - j] % MO);
					}
				}
				int pre = g[now][st][1][0];
				int tmp;
				g[now][st][1][0] = 0;
				REPP(i, 1, m) {
					tmp = g[now][st][1][i];
					g[now][st][1][i] = pre;
					add(pre, tmp);
				}
			}
			else {
				REPP(i, 1, m) g[now][st][1][i] = 0;
			}
		}
	}
}

void gao(int dep, int st, int limit) {
	if (dep > limit) {
		calc(1, st, limit);
		REP(i, 1 << limit) {
			REP(j, 2) {
				REP(k, m + 1) {
					f[limit][i][j][k] = g[1][i][j][k];
				}
			}
		}
	}
	else {
		REP(i, 2) {
			gao(dep + 1, st | (i * (1 << (dep - 1))), limit); 
		}
	}
}

void init() {
	REPP(i, 1, 15) {
		gao(1, 0, i);
	}
}

void getst(int now, int num, int &node, int &st) {
	if (now > n) return ;
	else {
		node++;
		if (s[now] == '1') st |= (1 << (num - 1));
		getst(2 * now, 2 * num, node, st);
		getst(2 * now + 1, 2 * num + 1, node, st);
	}
}

void dfs(int x, int &dep, int now) {
	if (2 * x > n) {
		dep = max(dep, now);
		return ;
	}
	if (2 * x <= n) dfs(2 * x, dep, now + 1);
	if (2 * x + 1 <= n) dfs(2 * x + 1, dep, now + 1);
	if (now > dep - 3) {
		return ;
	}
	else if (now == dep - 3) {
		int node = 0, st = 0;
		getst(x, 1, node, st);
		REP(i, 2) {
			REP(j, m + 1) {
				dp[x][i][j] = f[node][st][i][j];
			}
		}
	}
	else {
		REP(i, m + 1) {
			REP(j, i + 1) {
				REP(k, 2) {
					REP(t, 2) {
						add(dp[x][0][i], 1LL * dp[2 * x][k][j] * dp[2 * x + 1][t][i - j] % MO);
					}
				}
			}
		}
		if (s[x] == '0') {
			REP(i, m + 1) {
				REPP(j, 0, i) {
					add(dp[x][1][i], 1LL * dp[2 * x][0][j] * dp[2 * x + 1][0][i - j] % MO);
				}
			}
			int pre = dp[x][1][0];
			int tmp;
			dp[x][1][0] = 0;
			REPP(i, 1, m) {
				tmp = dp[x][0][i];
				dp[x][1][i] = pre;
				add(pre, tmp);
			}
		}
		else {
			REPP(i, 0, m) dp[x][1][i] = 0;
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("F.in", "r", stdin);
	cin >> n >> m;
	cin >> (s + 1);
	if (n < 16) {
		gao(1, 0, n);
		int node = 0, st = 0;
		getst(1, 1, node, st);
		int ans = 0;
		add(ans, f[node][st][0][m]);
		add(ans, f[node][st][1][m]);
		cout << ans << endl;
	}
	else {
		init();
		int dep = 0;
		dfs(1, dep, 0);
		int ans = dp[1][0][m];
		add(ans, dp[1][1][m]);
		cout << ans << endl;
	}

	return 0;
}
