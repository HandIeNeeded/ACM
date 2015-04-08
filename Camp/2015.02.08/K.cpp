#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for(int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int vis[N], cnt[N];
double dp[N], sum[N];
vector<int> edge[N];

int main() {
	ios :: sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	REPP(i, 1, m) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;
	dp[n] = 0.0;
	REPP(i, 1, n - 1) sum[i] = m, dp[i] = 1e100;
	q.push({dp[n], n});
	while(q.size()) {
		int x = q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto y: edge[x]) if (!vis[y]) {
			if (dp[y] > (sum[y] + dp[x]) / (cnt[y] + 1)) {
				dp[y] = (sum[y] + dp[x]) / (cnt[y] + 1);
				sum[y] += dp[x];
				cnt[y] ++;
				q.push({dp[y], y});
			}
		}
	}
	cout << fixed << setprecision(10) << dp[1] << endl;

	return 0;
}
