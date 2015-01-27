#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)

using namespace std;

const int N = 1e5 + 5;

map<pair<int, int>, int> mp;
pair<int, int> q[N];
vector<pair<int, int> > edge[N];
int f[N], vis[N], ans[N], clk;

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
	ios :: sync_with_stdio(0);
	cout << a << endl;

	int n, m, c, nq;
	cin >> n >> m;
	pair<int, int> tmp;
	REP(i, m) {
		cin >> tmp.first >> tmp.second >> c;
		edge[c - 1].push_back(tmp);
	}
	cin >> nq;
	REP(i, nq) {
		cin >> q[i].first >> q[i].second;
	}
	REP(k, m) {
		if (edge[k].size()) {
			clk++;
			vector<int> node;
			REP(i, edge[k].size()) {
				node.push_back(edge[k][i].first);
				node.push_back(edge[k][i].second);
			}
			sort(node.begin(), node.end());
			node.erase(unique(node.begin(), node.end()), node.end());
			REP(i, node.size()) vis[node[i]] = clk, f[node[i]] = node[i];
			REP(i, edge[k].size()) {
				int x = edge[k][i].first, y = edge[k][i].second;
				int tx = find(x), ty = find(y);
				if (tx != ty) f[tx] = ty;
			}
			if (1ULL * node.size() * node.size() >= 1ULL * n) {
				REP(i, nq) {
					int x = q[i].first, y = q[i].second;
					if (vis[x] == clk && vis[y] == clk) {
						int tx = find(x), ty = find(y);
						if (tx == ty) ans[i]++;
					}
				}
			}
			else {
				REP(i, node.size()) {
					REPP(j, i + 1, node.size() - 1) {
						int x = node[i], y = node[j];
						if (find(x) == find(y)) {
							mp[{x, y}]++;
							mp[{y, x}]++;
						}
					}
				}
			}
		}
	}
	REP(i, nq) {
		cout << ans[i] + mp[q[i]] << endl;
	}

	return 0;
}
