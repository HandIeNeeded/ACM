#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1e5 + 5;

int dep[N], pre[N][20];
vector<int> edge[N];

void dfs(int x, int p = 0) {
	pre[x][0] = p, dep[x] = dep[p] + 1;
	REPP(i, 1, 19) pre[x][i] = pre[pre[x][i - 1]][i - 1];
	for (auto &y: edge[x]) {
		if (y != p) {
			dfs(y, x);
		}
	}
}

int go(int x, int step) {
	REP(i, 20) if (step & (1 << i)) {
		x = pre[x][i];
	}
	return x;
}

int get(int a, int b) {//lca
	if (dep[a] < dep[b]) swap(a, b);
	a = go(a, dep[a] - dep[b]);
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if(pre[a][i] != pre[b][i]) {
			a = pre[a][i];
			b = pre[b][i];
		}
	}
	return pre[a][0];
}

int getlca(int a, int b, int rt) {
	int c = get(a, b);
	if (get(c, rt) != c) return c;
	int x = get(a, rt), y = get(b, rt);
	if (dep[x] > dep[y]) return x;
	return y;
}

int n, m;
char type[2];

int main() {
	freopen("dynamic.in", "r", stdin);
	freopen("dynamic.out", "w", stdout);
	while (scanf("%d", &n), n) {
		REPP(i, 1, n) edge[i].clear();
		REPP(i, 1, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int rt = 1;
		dfs(1);
		scanf("%d", &m);
		while (m--) {
			scanf("%s", type);
			if (type[0] == '!') {
				scanf("%d", &rt);
			}
			else {
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%d\n", getlca(x, y, rt));
			}
		}
	}
	return 0;
}
