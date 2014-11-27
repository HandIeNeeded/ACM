#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define INF 0x3f3f3f3f
#define key 4

using namespace std;

const int N = 205;
const int M = 5005;
int fi[N], en[M << 1], ne[M << 1], val[M << 1], edge;
int dp[N][1 << 8], vis[N][1 << 8], g[1 << 8], cnt[N], ty[N], s[N], id[N];
int mask, n, m, a, b;
pair<int, int> ans[1 << 8];

void add(int x, int y, int z) {
	ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, val[edge] = z;
}

deque<pair<int, int> > q;

void spfa() {
	while (q.size()) {
		int x = q.front().first, st = q.front().second;
		q.pop_front();
		for (int go = fi[x]; go; go = ne[go]) {
			int y = en[go];
			if (dp[y][st] > dp[x][st] + val[go]) {
				dp[y][st] = dp[x][st] + val[go];
				if (!vis[y][st]) {
					vis[y][st] = 1;
					if (!q.size() || dp[y][st] <= dp[q.front().first][q.front().second]) {
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

int get(int st) {
	int aa = 0, bb = 0;
	REP(i, a) {
		if (st & (1 << i)) aa += cnt[id[i]];
	}
	REP(i, b) {
		if (st & (1 << (i + key))) bb++;
	}
	return min(aa, bb);
}

void update(pair<int, int> &a, const pair<int, int> &b) {
	if (b.first > a.first) a = b;
	else if (b.first == a.first && b.second < a.second) a = b;
}

int main() {
	ios :: sync_with_stdio(0);
	// freopen("cf.in", "r", stdin);

	int x, y, z;

	while (cin >> n) {
		a = b = 0;
		REPP(i, 1, n) s[i] = 0;
		pair<int, int> res(0, 0);
		int imp = 0;
		REPP(i, 1, n) {
			cin >> cnt[i] >> ty[i];
			if (cnt[i] && ty[i]) {
				cnt[i]--;
				ty[i] = 0;
				imp++;
			}
			if (cnt[i] > 0) {
				s[i] = 1 << a;
				id[a] = i;
				a++;
			}
			else if (ty[i]) {
				s[i] = 1 << (b + key);
				id[b + key] = i;
				b++;
			}
		}
		edge = 0;
		MST(fi, 0), MST(dp, 0x3f);
		cin >> m;
		REPP(i, 1, m) {
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		mask = (1 << (b + key)) - 1;
		int lim = (1 << (b + key));

		REP(i, a) {
			dp[id[i]][s[id[i]]] = 0;
			vis[id[i]][s[id[i]]] = 1;
			q.push_front(MP(id[i], s[id[i]]));
		}
		REP(i, b) {
			dp[id[i + key]][s[id[i + key]]] = 0;
			vis[id[i + key]][s[id[i + key]]] = 1;
			q.push_front(MP(id[i + key], s[id[i + key]]));
		}

		REP(st, lim) {
			REPP(node, 1, n) {
				int all = st;
				for (int sub = all; sub; sub = all & (sub - 1)) {
					if (dp[node][st] > dp[node][sub] + dp[node][st ^ sub]) {
						dp[node][st] = dp[node][sub] + dp[node][st ^ sub];
						if (!vis[node][st]) {
							vis[node][st] = 1;
							if (!q.size() || dp[node][st] <= dp[q.front().first][q.front().second]) {
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


		REP(st, lim) {
			g[st] = INF;
			REPP(node, 1, n) {
				g[st] = min(g[st], dp[node][st]);
			}
		}

		MST(ans, 0);
		REP(st, lim) {
			int all = st;
			for (int sub = all; sub; sub = all & (sub - 1)) {
				pair<int, int> tmp = ans[st ^ sub];
				int cnt = get(sub), cost = g[sub];
				if (cost != INF) update(ans[st], MP(tmp.first + cnt, tmp.second + cost));
			}
			update(res, ans[st]);
		}
		cout << res.first + imp << ' ' << res.second << endl;
	}

	return 0;
}
