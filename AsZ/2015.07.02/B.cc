#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 70;
char s[N];
vector<string> ans[N];
int f[N];

bool get(int n) {
	f[0] = f[1] = 0;
	for (int i = 1; i < n; i++) {
		int j = f[i];
		while (j && s[j] != s[i]) j = f[j];
		f[i + 1] = s[j] == s[i] ? j + 1 : 0;
	}
	return f[n] == 0;
}

void dfs(int dep) {
	if (dep == 8) {
		return ;
	}
	else {
		if (dep > 0) {
			s[dep] = 0;
			if (get(dep)) {
				ans[dep].push_back(string(s));
			}
		}
		s[dep] = 'a';
		dfs(dep + 1);
		s[dep] = 'b';
		dfs(dep + 1);
	}
}

int dp[N][N];

void go_dp(int dep, int limit) {
	if (dep <= 1) f[dep] = 0;
	else {
		int tmp = f[dep];
		while (tmp && s[tmp] != s[dep]) tmp = f[tmp];
		f[dep + 1] = s[tmp] == s[dep] ? tmp + 1 : 0;
	}
	REPP(i, dep, limit) {
		REPP(j, 0, limit) {
			dp[i][j] = 0;
		}
	}
	dp[dep][f[dep + 1]] = 1;
	REPP(dep + 1, limit) {

	}
}

void dfs(int dep, int limit, LL pre, LL k) {
	if (dep == limit) {
		s[dep] = 0;
		return ;
	}
	s[dep] = 'a';
	unsigned LL now = go_dp(dep, limit);
	if (now + pre <= k) {
		dfs(dep + 1, limit, pre, k);
	}
	else {
		s[dep] = 'b';
		dfs(dep + 1, limit, now, k);
	}
}

//res[2 * n] = 2 * res[2 * n - 1]
//res[2 * n + 1] = 2 * res[2 * n] - res[n]
unsigned LL res[N];

int main() {
    ios :: sync_with_stdio(0);
	//dfs(0);
	//REPP(i, 1, 7) {
	//	cout << "length" << ' ' << i << ' ' << ans[i].size() << endl;
	//	for (auto &s: ans[i]) {
	//		cout << s << endl;
	//	}
	//	cout << endl;
	//}
	//res[0] = 0, res[1] = 2;
	//REPP(i, 2, 64) {
	//	if (i & 1) res[i] = 2 * res[i - 1] - res[i / 2];
	//	else res[i] = 2 * res[i - 1];
	//	cout << i << ' ' << res[i] << endl;
	//}
	freopen("borderless.in", "r", stdin);
	freopen("borderless.out", "w", stdout);
	while (cin >> n >> k, n | k) {
		dfs(0, n, 0, k);
		cout << s << endl;
	}
    return 0;
}

