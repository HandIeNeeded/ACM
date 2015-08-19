#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1005;

vector<int> edge[N];
int col[N], vis[N];

int main() {
	int n;
	scanf("%d", &n);
	REP(i, n - 1) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	printf("1 1\n");
	fflush(stdout);
	col[1] = 0, vis[1] = 1;
	for (auto &y: edge[1]) {
		col[y] |= 1 << 1;
	}
	int x, y;
	while (scanf("%d%d", &x, &y), x != -1) {
		vis[x] = 1;
		for (auto &z: edge[x]) {
			col[z] |= 1 << y;
		}
		int find = 0, node = -1;
		REPP(i, 1, n) if (!vis[i] && __builtin_popcount(col[i]) >= 2) {
			find = 1;
			node = i;
			break;
		}
		if (!find) {
			REPP(i, 1, n) {
				if (!vis[i]) {
					node = i;
					break;
				}
			}
		}
		REPP(i, 1, 4) if (!((col[node] >> i) & 1)) {
			printf("%d %d\n", node, i);
			fflush(stdout);
			vis[node] = 1;
			for (auto &z: edge[node]) {
				col[z] |= 1 << i;
			}
			break;
		}
	}
    return 0;
}
