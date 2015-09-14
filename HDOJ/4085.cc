#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define INF 0x3f3f3f3f
#define MP make_pair

using namespace std;

const int N = 55;
const int M = 1005;
int fi[N], en[M << 1], ne[M << 1], val[M << 1], edge;
int dp[N][1 << 10], vis[N][1 << 10], s[N], g[1 << 10];
int mask, n, m, k;

void add(int x, int y, int z) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, val[edge] = z;
}

bool check(int x) {
	int ans = 0;
	REPP(i, 1, 2 * k) {
		ans += (x & 1) * (i <= k ? 1 : -1);
		x >>= 1;
	}
	return ans == 0;
}

deque<pair<int, int> > q;

void spfa() {
	while (!q.empty()) {
		int x = q.front().first, st = q.front().second;
		q.pop_front();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (dp[y][st] > dp[x][st] + val[go]) {
				dp[y][st] = dp[x][st] + val[go];
				if (!vis[y][st]) {
					vis[y][st] = 1;
					if (!q.size() || dp[y][st] < dp[q.front().first][q.front().second]) {
						q.push_front(MP(y, st));
					}
					else {
						q.push_back(MP(y, st));
					}
				}
			}
		}
		vis[x][st] = 0;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("cf.in", "r", stdin);

	int t, x, y, z;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;

		mask = (1 << (2 * k)) - 1;
		memset(fi, 0, sizeof(fi));
		edge = 0;

		REPP(i, 1, m) {
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		REPP(i, 1, n) s[i] = 0;
		REPP(i, 1, k) {
			s[i] = 1 << (i - 1);
			s[n + 1 - i] = (1 << (2 * k - i));
		}
		memset(dp, 0x3f, sizeof(dp));
		REPP(i, 1, k) {
			dp[i][s[i]] = 0;
			dp[n + 1 - i][s[n + 1 - i]] = 0;
			q.push_front(MP(i, s[i]));
			q.push_front(MP(n + 1 - i, s[n + 1 - i]));
		}

		REP(st, mask + 1) {
			REPP(node, 1, n) {
				int all = st;
				for (int sub = all; sub; sub = all & (sub - 1)) {
					if (dp[node][st] > dp[node][sub] + dp[node][st ^ sub]) {
						dp[node][st] = dp[node][sub] + dp[node][st ^ sub];
						if (!vis[node][st]) {
							vis[node][st] = 1;
							if (!q.size() || dp[node][st] < dp[q.front().first][q.front().second]) {
								q.push_front(MP(node, st));
							}
							else {
								q.push_back(MP(node, st));
							}
						}
					}
				}
			}
			spfa();
		}

		REP(st, mask + 1) {
			g[st] = INF;
			REPP(node, 1, n) g[st] = min(g[st], dp[node][st]);
		}
		REP(st, mask + 1) {
			if (check(st)) {
				int all = st;
				for (int sub = all; sub; sub = all & (sub - 1)) {
					if (check(sub)) {
						g[st] = min(g[st], g[sub] + g[st ^ sub]);
					}
				}
			}
		}

		int ans = g[mask];
		if (ans == INF) {
			cout << "No solution" << endl;
		}
		else {
			cout << ans << endl;
		}
	}


	return 0;
}

