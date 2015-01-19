#include <bits/stdc++.h>

#define REP(i, a) for (int i = 0; i < (int) (a); i ++)
#define REPP(i, a, b) for (int i = (int) (a); i <= (int) (b); i ++)
#define MST(a, b) memset(a, b, sizeof(a))

using namespace std;

const int N = 2005;
const int MOD = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int f[N][N], g[N][N];

int main() {
	ios :: sync_with_stdio(0);
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int t, n, m, ca = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d-%d", &n, &m);
		f[1][0] = 1;
		for (int sum = 1; sum < n + m; sum++) {
			for (int a = 0; a <= n && a <= sum; a++) {
				int b = sum - a;
				if (b > m) continue;
				if (a > b) {
					if (a + 1 <= n) add(f[a + 1][b], f[a][b]);
					if (b + 1 < a && b + 1 <= m) add(f[a][b + 1], f[a][b]);
				}
			}
		}
		g[0][0] = 1;
		for (int sum = 0; sum < n + m; sum++) {
			for (int a = 0; a <= n && a <= sum; a++) {
				int b = sum - a;
				if (b > m) continue;
				if (a <= b || b == m) {
					if (a + 1 <= n && (a + 1 <= b || b == m)) add(g[a + 1][b], g[a][b]);
					if (b + 1 <= m) add(g[a][b + 1], g[a][b]);
				}
			}
		}
		printf("Case #%d: %d %d\n", ca++, f[n][m], g[n][m]);
		MST(f, 0), MST(g, 0);
	}

	return 0;
}
