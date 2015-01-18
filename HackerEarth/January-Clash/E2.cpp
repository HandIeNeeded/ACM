#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

int dp[N], pre[N], limit, n, m;
pair<int, int> p[N];
bool flag;
vector<pair<int, int> > ans;

void dfs(int dep, int st, int n) {
	if (dep == limit - 1) {
		int tmp = sqrt(n + 0.5);
		if (tmp * tmp == n) {
			flag = 1;
			ans.push_back({tmp, 2});
		}
		return ;
	}
	st = min(st, (int) sqrt(n + 0.5) + 1);
	for (int i = st; i >= 1; i--) if (i * i <= n) {
		dfs(dep + 1, i, n - i * i);
		if (flag) {
			ans.push_back({i, 2});
			return ;
		}
	}
}

void go() {
	//MST(dp, 0x3f), MST(pre, 0);
	//MST(p, 0);
	REPP(i, 1, n) dp[i] = INF, pre[i] = 0, p[i] = {0, 0};
	dp[0] = 0, pre[0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int num = q.front(); q.pop();
		if (num == n) break;
		for (int i = 1; i <= m; i++) {
			if (i == 1) {
				if (dp[num + 1] > dp[num] + 1) {
					dp[num + 1] = dp[num] + 1;
					p[num + 1] = {1, 1};
					pre[num + 1] = num;
					if (num + 1 == n) {
						break;
					}
					q.push(num + 1);
				}
			}
			else {
				long long tmp = i;
				for (int j = 1; j <= m; j++) {
					if (num + tmp >= n) break;
					if (dp[num + tmp] > dp[num] + 1) {
						dp[num + tmp] = dp[num] + 1;
						p[num + tmp] = {i, j};
						pre[num + tmp] = num;
						if (num + tmp == n) {
							break;
						}
						q.push(num + tmp);
					}
					tmp = tmp * i;
				}
			}
		}
	}
	int now = n;
	while (now) {
		ans.push_back(p[now]);
		now = pre[now];
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		ans.clear();
		if (m == 1) {
			REP(i, n) {
				ans.push_back({1, 1});
			}
			cout << ans.size() << endl;
			REP(i, ans.size()) {
				cout << ans[i].first << " \n"[i == ans.size() - 1];
			}
			REP(i, ans.size()) {
				cout << ans[i].second << " \n"[i == ans.size() - 1];
			}
			continue;
		}
		if (m * m >= n && n >= 2000) {
			flag = 0;
			REPP(i, 1, 4) {
				limit = i;
				dfs(0, m, n);
				if (flag) break;
			}
		}
		else {
			flag = 0;
			REPP(i, 1, 4) {
				limit = i;
				dfs(0, m, n);
				REP(j, ans.size()) {
					if (ans[j].first > m) {
						ans.clear();
						flag = 0;
						break;
					}
				}
				if (flag) break;
			}
			if (!flag) {
				if (m <= 40 && n >= 30000) {
					int mx = 0, id = 0, cnt = 0;
					REPP(i, 2, m) {
						long long tmp = i;
						for (int j = 1; j <= m; j++) {
							if (tmp <= n) {
								if (tmp > mx) {
									mx = tmp, id = i, cnt = j;
								}
							}
							tmp *= i;
						}
					}
					ans.assign(n / mx, {id, cnt});
					n = n - n / mx * mx;
				}
				go();
			}
		}
		cout << ans.size() << endl;
		REP(i, ans.size()) {
			cout << ans[i].first << " \n"[i == ans.size() - 1];
		}
		REP(i, ans.size()) {
			cout << ans[i].second << " \n"[i == ans.size() - 1];
		}
	}

	return 0;
}

