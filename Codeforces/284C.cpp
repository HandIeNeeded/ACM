#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0;i < (int) (a); ++i)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 205;
const int M = 30005;
const int INF = 0x3f3f3f3f;

struct MaxFlow{
	int node, edge, source, sink;
	int lvl[N], vis[N], cur[N];
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1];
	
	void init(int S, int T, int tot) {
		source = S, sink = T, node = tot;
		MST(fi, 0), edge = 1;
	}

	void _add(int x, int y, int z) {
		ne[++edge] = fi[x];
		fi[x] = edge;
		en[edge] = y;
		cap[edge] = z;
	}

	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, 0);
	}
	
	bool bfs() {
		queue<int> q;
		MST(lvl, 0), MST(vis, 0);
		q.push(source);
		vis[source] = 1;

		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !vis[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				q.push(y);
				vis[y] = 1;
			}
		}
		return vis[sink];
	}

	int dfs(int x, int flow) {
		if (x == sink || flow == 0) {
			return flow;
		}
		int ans = 0, tmp = 0;
		for (int &go = cur[x]; go; go = ne[go]) if (cap[go] > 0) {
			int y = en[go];
			if (lvl[y] == lvl[x] + 1 && (tmp = dfs(y, min(flow, cap[go]))) > 0) {
				ans += tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				flow -= tmp;
				if (flow == 0) {
					return ans;
				}
			}
		}
		return ans;
	}

	int dinic() {
		int ans = 0;
		while (bfs()) {
			REPP(i, 1, node) {
				cur[i] = fi[i];
			}
			ans += dfs(source, INF);
		}	
		return ans;
	}
}Flow;

int vis[100005], p[100005], tot;

void prime() {
	for (int i = 2; i < 100005; i ++) {
		if (!vis[i]) {
			p[tot++] = i;
		}
		for (int j = 0; j < tot && i * p[j] < 100005; j++) {
			vis[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
 	}
}

int number[N];
pair<int, int> edge[N];

int main() {
	ios :: sync_with_stdio(0);

	prime();

	int n, m;
	cin >> n >> m;
	REPP(i, 1, n) {
		cin >> number[i];
	}
	REPP(i, 1, m) {
		cin >> edge[i].first >> edge[i].second;
	}

	vector<int> fac;
	REPP(i, 1, n) {
		int tmp = number[i];
		for (int j = 0; p[j] * p[j] <= tmp; j++) {
			if (tmp % p[j] == 0) {
				fac.push_back(p[j]);
				while (tmp % p[j] == 0) {
					tmp /= p[j];
				}
			}
		}
		if (tmp > 1) {
			fac.push_back(tmp);
		}
	}
	sort(fac.begin(), fac.end());
	fac.resize(unique(fac.begin(), fac.end()) - fac.begin());
	
	int ans = 0;
	REP(i, fac.size()) {
		Flow.init(2 * n + 1, 2 * n + 2, 2 * n + 2);
		REPP(j, 1, n) {
			if (j & 1) Flow.add(2 * n + 1, j, INF);
			if (!(j & 1)) Flow.add(j + n, 2 * n + 2, INF);
		}
		REPP(j, 1, n) {
			int tmp = number[j], a = 0;
			while (tmp % fac[i] == 0) {
				a++;
				tmp /= fac[i];
			}
			Flow.add(j, j + n, a);
		}
		REPP(j, 1, m) {
			int cnt = INF, a = 0, b = 0;
			int x = edge[j].first, y = edge[j].second;
			int tmp = number[x];
			while (tmp % fac[i] == 0) {
				a++;
				tmp /= fac[i];
			}
			tmp = number[y];
			while (tmp % fac[i] == 0) {
				b++;
				tmp /= fac[i];
			}
			cnt = min(a, b);
			if (x & 1) Flow.add(x + n, y, cnt);
			if (y & 1) Flow.add(y + n, x, cnt);
		}
		ans += Flow.dinic();
	}
	cout << ans << endl;

	return 0;
}


