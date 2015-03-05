#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2e5 + 5;
vector<pair<int, int> > edge[N];
int son[N], n;
long long sum[N], dp[N];

void dfs(int x, int p) {
	bool flag = 0;
	for (auto now: edge[x]) {
		int y = now.first, val = now.second;
		if (y != p) {
			flag = 1;
			dfs(y, x);
			son[x] += son[y];
			sum[x] += sum[y] + 1LL * son[y] * val;
		}
	}
	son[x]++;
	if (!flag) sum[x] = 0;
}

void dfs2(int x, int p) {
	for (auto now: edge[x]) {
		int y = now.first, val = now.second;
		if (y != p) {
			long long tmp = dp[x] - 1LL * son[y] * val - dp[y];
			dp[y] += tmp + 1LL * (n - son[y]) * val;
			dfs2(y, x);
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		REPP(i, 1, n - 1) {
			int x, y, z;
			cin >> x >> y >> z;
			edge[x].push_back({y, z});
			edge[y].push_back({x, z});
		}
		dfs(1, 0);
		REPP(i, 1, n) dp[i] = sum[i];
		dfs2(1, 0);
		REPP(i, 1, n) {
			cout << dp[i] << endl;
		}
		REPP(i, 1, n) {
			edge[i].clear();
			dp[i] = sum[i] = son[i] = 0;
		}
	}

	return 0;
}

