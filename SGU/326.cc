#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 25;
int w[N], r[N], mp[N][N], n;

template<int N, int M, typename Type>
struct MaxFlow{
	int edge, tot, source, sink;
	int lvl[N], cur[N];
	int fi[N], ne[M << 1], en[M << 1];
	Type cap[M << 1];
	const Type INF = 0x3f3f3f3f;
	
	void init(int S, int T) {
		source = S, sink = T;
		edge = 1, tot = N - 1;
		REPP(i, 0, tot) fi[i] = 0;
	}

	void _add(int x, int y, Type z) {
		ne[++edge] = fi[x]; fi[x] = edge; en[edge] = y; cap[edge] = z;
	}

	void add(int x, int y, int z) {
		_add(x, y, z);
		_add(y, x, z);
	}
	
	bool bfs() {
		queue<int> q;
		REPP(i, 0, tot) lvl[i] = 0;
		q.push(source), lvl[source] = 1;
		while(q.size()) {
			int x = q.front(); q.pop();
			for (int go = fi[x]; go; go = ne[go]) if (cap[go] > 0 && !lvl[en[go]]) {
				int y = en[go];
				lvl[y] = lvl[x] + 1;
				q.push(y);
			}
		}
		return lvl[sink];
	}

	Type dfs(int x, Type flow) {
		if (x == sink || flow == 0) {
			return flow;
		}
		Type ans = 0, tmp = 0;
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

	Type dinic() {
		Type ans = 0;
		while (bfs()) {
			REPP(i, 0, tot) cur[i] = fi[i];
			ans += dfs(source, INF);
		}	
		return ans;
	}
};

MaxFlow<1000, 1000, LL> flow;

int main() {
    ios :: sync_with_stdio(0);
	cin >> n;
	assert(n <= 20);
	REPP(i, 1, n) cin >> w[i];
	REPP(i, 1, n) cin >> r[i];
	int ans = w[1] + r[1];
	REPP(i, 1, n) {
		REPP(j, 1, n) cin >> mp[i][j];
		if (i > 1) {
			r[i] = 0;
			REPP(j, 2, n) {
				r[i] += mp[i][j];
			}
		}
	}
	REPP(i, 2, n) {
		if (w[i] > ans) {
			cout << "NO" << endl;
			return 0;
		}
	}
	flow.init(0, 1);
	int node = n, sum = 0;
	REPP(i, 2, n) {
		REPP(j, i + 1, n) {
			flow.add(0, ++node, mp[i][j]);
			flow.add(node, i, mp[i][j]);
			flow.add(node, j, mp[i][j]);
			sum += mp[i][j];
		}
	}
	REPP(i, 2, n) flow.add(i, 1, min(ans - w[i], r[i]));
	if (flow.dinic() == sum) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
    return 0;
}
