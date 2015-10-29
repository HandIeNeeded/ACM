#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
int mp[N][N], g[N][N], a[N], b[N];
vector<int> edge[N], path;
bool vis[N];

int dfs(int x, int p = 0) {
	vis[x] = 1;
	REP(i, edge[x].size()) {
		int y = edge[x][i];
		if (y != p && !vis[y]) {
			if (dfs(y, x)) {
				path.push_back(x);
				return 1;
			}
		}
		else if (y != p) {
			path.push_back(x);
			return 1;
		}
	}
	return 0;
}

int main() {
    ios :: sync_with_stdio(0);
	int n;
	cin >> n;
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	REPP(i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		mp[x][y] = mp[y][x] = 1;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	vector<pair<int, int> > ans;
	REPP(i, 1, n - 1) {
		cin >> a[i] >> b[i];
		g[a[i]][b[i]] = g[b[i]][a[i]] = 1;
	}
	REPP(i, 1, n - 1) {
		if (mp[a[i]][b[i]]) continue;
		ans.push_back(make_pair(a[i], b[i]));
		edge[a[i]].push_back(b[i]);
		edge[b[i]].push_back(a[i]);
		path.clear();
		REPP(j, 1, n) vis[j] = 0;
		dfs(a[i]);
		if (!g[path[0]][path.back()]) {
			ans.push_back(make_pair(path[0], path.back()));
			edge[path[0]].erase(find(edge[path[0]].begin(), edge[path[0]].end(), path.back()));
			edge[path.back()].erase(find(edge[path.back()].begin(), edge[path.back()].end(), path[0]));
			continue;
		}
		else {
			for (int i = 0; i < int(path.size() - 1); i++) {
				int x = path[i], y = path[i + 1];
				if (!g[x][y]) {
					ans.push_back(make_pair(x, y));
					edge[x].erase(find(edge[x].begin(), edge[x].end(), y));
					edge[y].erase(find(edge[y].begin(), edge[y].end(), x));
					break;
				}
			}
		}
	}
	cout << ans.size() / 2 << endl;
	for (int i = 0; i < int(ans.size()); i += 2) {
		cout << 1 << ' ' << ans[i].first << ' ' << ans[i].second << ' ' << ans[i + 1].first << ' ' << ans[i + 1].second << endl;
	}

    return 0;
}

