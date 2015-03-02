#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;
int parent[N][20], son[N], dep[N], n, q;
vector<int> edge[N];

void dfs(int x, int p, int d) {
	parent[x][0] = p;
	dep[x] = d;
	REPP(i, 1, 19) parent[x][i] = parent[parent[x][i - 1]][i - 1];
	for (auto y: edge[x]) {
		if (y != p) {
			dfs(y, x, d + 1);
			son[x] += son[y];
		}
	}
	son[x]++;
}

int jump(int x, int d) {
	REP(i, 20) {
		if (d & (1 << i)) {
			x = parent[x][i];
		}
	}
	return x;
}

int getlca(int x, int y) {
	if (dep[x] != dep[y]) {
		if (dep[x] < dep[y]) swap(x, y);
		x = jump(x, dep[x] - dep[y]);
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; --i) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}

int query(int a, int b) {
	if (a == b) return n;
	int c = getlca(a, b);
	int dis = dep[a] + dep[b] - 2 * dep[c];
	if (dis & 1) return 0;
	else if (a == c || b == c) {
		if (a == c) {
			int y = jump(b, dis / 2);
			int z = jump(b, dis / 2 - 1);
			return son[y] - son[z];
		}
		else {
			int y = jump(a, dis / 2);
			int z = jump(a, dis / 2 - 1);
			return son[y] - son[z];
		}
	}
	else {
		if (dep[a] > dep[b]) {
			int y = jump(a, dis / 2);
			int z = jump(a, dis / 2 - 1);
			return son[y] - son[z];
		}
		else if (dep[a] < dep[b]) {
			int y = jump(b, dis / 2);
			int z = jump(b, dis / 2 - 1);
			return son[y] - son[z];
		}
		else {
			int y = jump(a, dis / 2 - 1);
			int z = jump(b, dis / 2 - 1);
			return n - son[y] - son[z];
		}
	}
}

int main() {
	ios :: sync_with_stdio(0);
	//freopen("E.in", "r", stdin);
	cin >> n;
	REPP(i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1, 0, 1);
	cin >> q;
	REP(i, q) {
		int a, b;
		cin >> a >> b;
		cout << query(a, b) << endl;
	}

	return 0;
}
