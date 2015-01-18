#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 100005;
pair<int, int> p[N];
vector<int> good;

void init(int n, int m) {
	REPP(num, 2, m) {
		long long tmp = num;
		for (int i = 1; i <= m; i++, tmp = num * tmp) {
			if (tmp > n) break;
			if (p[tmp].first > 0) continue;
			p[tmp] = {num, i};
		}
	}
	good.clear();
	REPP(i, 1, n) {
		if (p[i].first > 0) {
			good.push_back(i);
		}
	}
}

vector<pair<int, int> > ans, dp[N];
bool vis[N];

vector<pair<int, int> > solve(int n) {
	if (vis[n]) return dp[n];
	else if (p[n].first > 0) {
		vis[n] = 1;
		return dp[n] = {p[n]};
	}
	else {
		vis[n] = 1;
		int now = 1000000;
		int pos = upper_bound(good.begin(), good.end(), n) - good.begin();
		for (int i = pos - 1; i >= 0; i--) {
			int tmp = solve(n - good[i]).size();
			if (now > tmp + 1) {
				dp[n] = dp[n - good[i]];
				dp[n].push_back(p[good[i]]);
				now = dp[n].size();
			}
			if (dp[n].size() <= 3) {
				return dp[n];
			}
		}
		return dp[n];
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int t, n, m;
	cin >> t;
	p[1] = {1, 1};
	while (t--) {
		cin >> n >> m;
		if (m == n) {
			cout << 1 << endl;
			cout << m << endl << 1 << endl;
			continue;
		}
		if (2 * m >= n) {
			cout << 2 << endl;
			cout << m << ' ' << n - m << endl;
			cout << "1 1" << endl;
			continue;
		}
		else if (3 * m >= n) {
			cout << 3 << endl;
			cout << m << ' ' << m << ' ' << n - 2 * m << endl;
			cout << "1 1 1" << endl;
			continue;
		}
		else if (4 * m >= n) {
			cout << 4 << endl;
			cout << m << ' ' << m << ' ' << m << ' ' << n - 3 * m << endl;
			cout << "1 1 1 1" << endl;
			continue;
		}
		REPP(i, 2, n) p[i] = {-1, -1};
		REPP(i, 1, n) dp[i].clear(), vis[i] = 0;
		init(n, m);
		//REP(i, good.size()) {
		//	cout << good[i] << endl;
		//}
		ans.clear();
		ans = solve(n);
		cout << ans.size() << endl;
		REP(i, ans.size()) {
			cout << ans[i].first << " \n"[i == (int) ans.size() - 1];
		}
		REP(i, ans.size()) {
			cout << ans[i].second << " \n"[i == (int) ans.size() - 1];
		}
	}

	return 0;
}

