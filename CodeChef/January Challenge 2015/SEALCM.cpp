#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;
const int MOD = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int vis[N], p[N], tot;
int dp[N], n, m;
vector<int> fac[N], cnt;

void prime() {
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) p[tot++] = i, fac[i].push_back(i);
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			fac[i * p[j]] = fac[i];
			if (i % p[j] == 0) break;
			else {
				fac[i * p[j]].push_back(p[j]);
			}
		}
	}
}

int pow_mod(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1LL * ans * x % MOD;
		y >>= 1;
		x = 1LL * x * x % MOD;
	}
	return ans;
}

void dfs(int &ans, int x, int now, int odd, int mul) {
	if (now == (int) cnt.size()) {
		if (mul == 1 || mul == x) return ;
		else if (odd) {
			add(ans, MOD - dp[mul]);
		}
		else {
			add(ans, dp[mul]);
		}
	}
	else {
		dfs(ans, x, now + 1, odd, mul);
		dfs(ans, x, now + 1, odd ^ 1, mul * cnt[now]);
	}
}

int calc(int x) {
	if (x == 1) return pow_mod(m, n);	
	else {
		cnt.clear();
		int y = x;
		REP(i, fac[x].size()) {
			int tmp = 1;
			while (y % fac[x][i] == 0) {
				tmp *= fac[x][i];
				y /= fac[x][i];
			}
			cnt.push_back(tmp);
		}
		int num = 0;
		REPP(i, 1, m) {
			bool bad = 0;
			REP(j, cnt.size()) {
				if (i % cnt[j] == 0) {
					bad = 1;
					break;
				}
			}
			if (!bad) num++;
		}
		int ans = pow_mod(m, n);
		add(ans, MOD - pow_mod(num, n));
		dfs(ans, x, 0, 0, 1);
		if (!(cnt.size() & 1)) ans = MOD - ans;
		return ans;
	}
}

int main() {
	ios :: sync_with_stdio(0);
	prime();

	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> n >> m >> l >> r;
		REPP(i, 1, m) dp[i] = calc(i);
		int ans = 0;
		REPP(i, l, r) {
			add(ans, dp[i]);
		}
		cout << ans << endl;
	}

	return 0;
}
