#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 100005;
const int M = 100005;
const int INF = 0x3f3f3f3f;

struct MinCostFlow{
	int pre[N], dp[N];
	int fi[N], cost[M << 2], en[M << 2], ne[M << 2], cap[M << 2], edge;
	bool vis[N];
	int source, sink;

	void init(int S, int T) {
		MST(fi, 0);
		edge = 1, source = S, sink = T;
	}

	void _add(int x, int y, int z, int w) {
		ne[++edge] = fi[x], fi[x] = edge, en[edge] = y, cap[edge] = z, cost[edge] = w;
	}

	void add(int x, int y, int z, int w) {
		_add(x, y, z, w);
		_add(y, x, 0, -w);
	}

	bool spfa() {
		MST(vis, 0), MST(dp, 0x3f), MST(pre, 0);
		queue<int> q;
		q.push(source);
		dp[source] = 0;
		vis[source] = 1;

		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0) {
				int y = en[go];
				if (dp[y] > dp[x] + cost[go]) {
					dp[y] = dp[x] + cost[go];
					pre[y] = go;
					if (!vis[y]) {
						q.push(y);
						vis[y] = 1;
					}
				}
			}
			vis[x] = 0;
		}
		if (dp[sink] == INF) return 0;
		return 1;
	}

	int mincost(){
		int ans = 0;
		while (spfa()) {
			int tmp = INF;
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				tmp = min(tmp, cap[go]);
			}
			for (int go = pre[sink]; go; go = pre[en[go ^ 1]]) {
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
			}
			ans += tmp * dp[sink];
		}
		return ans;
	}
}AC;

int main() {
	ios :: sync_with_stdio(0);

	int n, m;
	while (cin >> n >> m) {
		AC.init(n + 1, n + 2);
		REP(i, m) {
			int x, y, z;
			cin >> x >> y >> z;
			AC.add(x, y, 1, z);
			AC.add(y, x, 1, z);
		}
		AC.add(n + 1, 1, 2, 0);
		AC.add(n, n + 2, 2, 0);
		int ans = AC.mincost();
		cout << ans << endl;
	}

	return 0;		
}

