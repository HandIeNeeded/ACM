#include <bits/stdc++.h> 

#define REP(i, a) for (int i = 0; i <  (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int N = 105;
const int M = 10005;
const int INF = 0x3f3f3f3f;

struct Max_Flow{
	int source, sink, node, edge;
	int fi[N], ne[M << 1], en[M << 1], cap[M << 1];
	int cur[N], lvl[N];
	bool vis[N];
	
	void Init(int S, int T, int tot) {
		MST(fi, 0), edge = 1;
		source = S, sink = T, node = tot;
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
		MST(vis, 0), MST(lvl, 0);
		q.push(source);
		vis[source] = 1;
		lvl[source] = 0;

		while(q.size()) {
			int x = q.front(); q.pop();
			for(int go = fi[x]; go; go = ne[go]) if (cap[go] && !vis[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				vis[y] = 1;
				q.push(y);
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
				flow -= tmp;
				ans += tmp;
				cap[go] -= tmp;
				cap[go ^ 1] += tmp;
				if (flow == 0) return ans;
			}
		}
		return ans;
	}

	int Dinic() {
		int ans = 0, tmp;
		while (bfs()) {
			REPP(i, 1, node) cur[i] = fi[i];
			while (tmp = dfs(source, INF)) {
				ans += tmp;
			}
		}
		return ans;
	}
}MaxFlow;

LL mp[105][105], g[105][105];
int n, m;

void Floyd() {
	REPP(k, 1, n) REPP(i, 1, n) REPP(j, 1, n) {
		if (mp[i][j] > mp[i][k] + mp[k][j]) {
			mp[i][j] = mp[i][k] + mp[k][j];
		}
	}
}

int main() {
	//freopen("cf.in", "r", stdin);
	ios :: sync_with_stdio(0);

	while(cin >> n) {
		REPP(i, 1, n) {
			REPP(j, 1, n) {
				cin >> mp[i][j];
				g[i][j] = mp[i][j];
				if(i == j) mp[i][j] = 0;
				if (mp[i][j] == -1) {
					mp[i][j] = 1LL << 61; 
				}
			}
		}
		int s, t;
		cin >> s >> t;
		s++, t++;
		if (s == t) {
			cout << "inf" << endl;
			continue;
		}
		MaxFlow.Init(s, t, n);
		Floyd();
		REPP(i, 1, n) {
			REPP(j, 1, n) {
				if (g[i][j] >= 0) {
					if (mp[s][i] + g[i][j] + mp[j][t] == mp[s][t]) {
						MaxFlow.add(i, j, 1);
						//cout << i << ' ' << j << endl;
					}
				}
			}
		}
		cout << MaxFlow.Dinic() << endl;
	}
	return 0;
}
